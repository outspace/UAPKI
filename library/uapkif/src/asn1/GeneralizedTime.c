/*
 * Copyright 2021 The UAPKI Project Authors.
 * Copyright 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions are 
 * met:
 * 
 * 1. Redistributions of source code must retain the above copyright 
 * notice, this list of conditions and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the above copyright 
 * notice, this list of conditions and the following disclaimer in the 
 * documentation and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS 
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED 
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A 
 * PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED 
 * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR 
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#define _POSIX_PTHREAD_SEMANTICS   /* for Sun */

#ifndef _REENTRANT
#define _REENTRANT                 /* for Sun */
#endif

#undef FILE_MARKER
#define FILE_MARKER "asn1/GeneralizedTime.c"

//for timegm in glibc > 2.19
#define _DEFAULT_SOURCE
//for timegm in glibc <= 2.19
#define _BSD_SOURCE

#include <stdlib.h>
#include "asn_internal.h"
#include "GeneralizedTime.h"
#include "asn1-utils.h"

#ifdef  __CYGWIN__
#include "/usr/include/time.h"
extern void tzset (void);
extern int setenv(const char *name, const char *value, int overwrite);
extern int unsetenv(const char *name);
#else
#include <time.h>
#endif  /* __CYGWIN__ */

#ifdef _WIN32

/*
    PLEASE STOP AND READ!
        localtime_r is implemented via localtime(), which may be not thread-safe.
        gmtime_r is implemented via gmtime(), which may be not thread-safe.
        You must fix the code by inserting appropriate locking
        if you want to use asn_GT2time() or asn_UT2time().
    PLEASE STOP AND READ!
*/

static struct tm *localtime_r(const time_t *tloc, struct tm *result)
{
    struct tm *tm;

    tm = localtime(tloc);
    if (tm) {
        return memcpy(result, tm, sizeof(struct tm));
    }

    return NULL;
}

static struct tm *gmtime_r(const time_t *tloc, struct tm *result)
{
    struct tm *tm;

    tm = gmtime(tloc);
    if (tm) {
        return memcpy(result, tm, sizeof(struct tm));
    }

    return 0;
}

//extern void _tzset (void);
#define tzset _tzset

#ifdef _MSC_VER
#  define putenv(_string) _putenv(_string)
#else
extern int putenv (const char *string);
#endif /* _MSC_VER */

#define setenv(n, v, o)  \
{                        \
    char str[256] = {0}; \
    strcpy(str, n);      \
    strcat(str, "=");    \
    strcat(str, v);      \
    putenv(str);        \
}

#define unsetenv(n)      \
{                        \
    char str[256] = {0}; \
    strcpy(str, n);      \
    strcat(str, "=");    \
    _putenv(str);        \
}

#define _EMULATE_TIMEGM
#else
#include <errno.h>
#endif  /* _WIN32 */

#if defined(__linux__) || defined(_linux_) || defined(sun) || defined(__sun) \
    || defined(hpux) || defined(_hpux) || defined(__hpux)
void tzset (void);
int setenv(const char *envname, const char *envval, int overwrite);
int unsetenv(const char *name);
struct tm *gmtime_r(const time_t *timep, struct tm *result);
struct tm *localtime_r(const time_t *timep, struct tm *result);
#endif

#if defined(sun) || defined(_sun_) || defined(__solaris__)
#define _EMULATE_TIMEGM
#endif

/*
    PLEASE STOP AND READ!
        timegm() is implemented via getenv(\"TZ\")/setenv(\"TZ\"), which may be not thread-safe.
        You must fix the code by inserting appropriate locking
        if you want to use asn_GT2time() or asn_UT2time().
    PLEASE STOP AND READ!
*/

/*
 * Override our GMTOFF decision for other known platforms.
 */
#undef  GMTOFF
static long GMTOFF(struct tm a)
{
    struct tm *lt;
    time_t local_time, gmt_time;

    tzset();

    local_time = mktime(&a);
    lt = gmtime(&local_time);
    gmt_time = mktime(lt);

    return (long)(local_time - gmt_time);
}

#define ATZVARS do {                            \
        char tzoldbuf[64];                      \
        char *tzold
#define ATZSAVETZ do {                          \
        tzold = getenv("TZ");                       \
        if(tzold) {                         \
            size_t tzlen = strlen(tzold);               \
            if(tzlen < sizeof(tzoldbuf)) {              \
                tzold = memcpy(tzoldbuf, tzold, tzlen + 1); \
            } else {                        \
                char *dupptr = tzold;               \
                tzold = MALLOC(tzlen + 1);          \
                if(tzold) memcpy(tzold, dupptr, tzlen + 1); \
            }                           \
        }                               \
        setenv("TZ", "UTC", 1);                 \
        tzset();                            \
    } while(0)
#define ATZOLDTZ do {                           \
        if (tzold) {                            \
            setenv("TZ", tzold, 1);                 \
            *tzoldbuf = 0;                      \
            if(tzold != tzoldbuf)                   \
                FREEMEM(tzold);                 \
        } else {                            \
            unsetenv("TZ");                     \
        }                               \
        tzset();                            \
    } while(0); } while(0);

#ifdef  _EMULATE_TIMEGM
time_t timegm(struct tm *tm)
{
    time_t tloc;
    ATZVARS;
    ATZSAVETZ;
    tloc = mktime(tm);
    ATZOLDTZ;
    return tloc;
}
#endif  /* _EMULATE_TIMEGM */


#ifndef ASN__INTERNAL_TEST_MODE__

/*
 * GeneralizedTime basic type description.
 */
static ber_tlv_tag_t asn_DEF_GeneralizedTime_tags[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (24 << 2)),  /* [UNIVERSAL 24] IMPLICIT ...*/
    (ASN_TAG_CLASS_UNIVERSAL | (26 << 2)),  /* [UNIVERSAL 26] IMPLICIT ...*/
    (ASN_TAG_CLASS_UNIVERSAL | (4 << 2))    /* ... OCTET STRING */
};

static asn_per_constraints_t asn_DEF_GeneralizedTime_constraints = {
    { APC_CONSTRAINED, 7, 7, 0x20, 0x7e },  /* Value */
    { APC_SEMI_CONSTRAINED, -1, -1, 0, 0 }, /* Size */
    0, 0
};

asn_TYPE_descriptor_t GeneralizedTime_desc = {
    "GeneralizedTime",
    "GeneralizedTime",
    OCTET_STRING_free,
    GeneralizedTime_print,
    GeneralizedTime_constraint, /* Check validity of time */
    OCTET_STRING_decode_ber,    /* Implemented in terms of OCTET STRING */
    OCTET_STRING_encode_der,
    OCTET_STRING_decode_xer_utf8,
    GeneralizedTime_encode_xer,
    OCTET_STRING_decode_uper,
    OCTET_STRING_encode_uper,
    0, /* Use generic outmost tag fetcher */
    asn_DEF_GeneralizedTime_tags,
    sizeof(asn_DEF_GeneralizedTime_tags)
    / sizeof(asn_DEF_GeneralizedTime_tags[0]) - 2,
    asn_DEF_GeneralizedTime_tags,
    sizeof(asn_DEF_GeneralizedTime_tags)
    / sizeof(asn_DEF_GeneralizedTime_tags[0]),
    &asn_DEF_GeneralizedTime_constraints,
    0, 0,   /* No members */
    0   /* No specifics */
};

asn_TYPE_descriptor_t *get_GeneralizedTime_desc(void)
{
    return &GeneralizedTime_desc;
}

#endif  /* __ASN_INTERNAL_TEST_MODE__ */

/*
 * Check that the time looks like the time.
 */
int
GeneralizedTime_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
        asn_app_constraint_failed_f *ctfailcb, void *app_key)
{
    const GeneralizedTime_t *st = (const GeneralizedTime_t *)sptr;
    time_t tloc;

    tloc = asn_GT2time(st, 0, 0);

    if (tloc == -1) {
        ASN__CTFAIL(app_key, td, sptr,
                "%s: Invalid time format: %s (%s:%d)",
                td->name, strerror(errno), FILE_MARKER, __LINE__);
        return -1;
    }

    return 0;
}

asn_enc_rval_t
GeneralizedTime_encode_der(asn_TYPE_descriptor_t *td, void *sptr,
        int tag_mode, ber_tlv_tag_t tag,
        asn_app_consume_bytes_f *cb, void *app_key)
{
    GeneralizedTime_t *st = (GeneralizedTime_t *)sptr;
    asn_enc_rval_t erval;
    int fv = 0, fd = 0; /* seconds fraction value and number of digits */
    struct tm tm;
    time_t tloc;

    /*
     * Encode as a canonical DER.
     */
    tloc = asn_GT2time_frac(st, &fv, &fd, &tm, 1);  /* Recognize time */

    if (tloc == -1)
        /* Failed to recognize time. Fail completely. */
    {
        ASN__ENCODE_FAILED;
    }

    st = asn_time2GT_frac(0, &tm, fv, fd, 1); /* Save time canonically */

    if (!st) {
        ASN__ENCODE_FAILED;    /* Memory allocation failure. */
    }

    erval = OCTET_STRING_encode_der(td, st, tag_mode, tag, cb, app_key);

    FREEMEM(st->buf);
    FREEMEM(st);

    return erval;
}

#ifndef __ASN_INTERNAL_TEST_MODE__

asn_enc_rval_t
GeneralizedTime_encode_xer(asn_TYPE_descriptor_t *td, void *sptr,
        int ilevel, enum xer_encoder_flags_e flags,
        asn_app_consume_bytes_f *cb, void *app_key)
{

    if (flags & XER_F_CANONICAL) {
        GeneralizedTime_t *gt;
        asn_enc_rval_t rv;
        int fv = 0, fd = 0;     /* fractional parts */
        struct tm tm;

        if (asn_GT2time_frac((GeneralizedTime_t *)sptr,
                &fv, &fd, &tm, 1) == -1) {
            ASN__ENCODE_FAILED;
        }

        gt = asn_time2GT_frac(0, &tm, fv, fd, 1);

        if (!gt) {
            ASN__ENCODE_FAILED;
        }

        rv = OCTET_STRING_encode_xer_utf8(td, sptr, ilevel, flags,
                cb, app_key);
        ASN_FREE(get_GeneralizedTime_desc(), gt);
        return rv;
    } else {
        return OCTET_STRING_encode_xer_utf8(td, sptr, ilevel, flags,
                cb, app_key);
    }
}

#endif  /* __ASN_INTERNAL_TEST_MODE__ */

int
GeneralizedTime_print(asn_TYPE_descriptor_t *td, const void *sptr, int ilevel,
        asn_app_consume_bytes_f *cb, void *app_key)
{
    const GeneralizedTime_t *st = (const GeneralizedTime_t *)sptr;

    (void)td;   /* Unused argument */
    (void)ilevel;   /* Unused argument */

    if (st && st->buf) {
        char buf[32];
        struct tm tm;
        int ret;

        if (asn_GT2time(st, &tm, 1) == -1) {
            return (cb("<bad-value>", 11, app_key) < 0) ? -1 : 0;
        }

        ret = snprintf(buf, sizeof(buf),
                "%04d-%02d-%02d %02d:%02d:%02d (GMT)",
                tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
                tm.tm_hour, tm.tm_min, tm.tm_sec);
        ASSERT(ret > 0 && ret < (int)sizeof(buf));
        return (cb(buf, ret, app_key) < 0) ? -1 : 0;
    } else {
        return (cb("<absent>", 8, app_key) < 0) ? -1 : 0;
    }
}

time_t
asn_GT2time(const GeneralizedTime_t *st, struct tm *ret_tm, int as_gmt)
{
    return asn_GT2time_frac(st, 0, 0, ret_tm, as_gmt);
}

time_t
asn_GT2time_prec(const GeneralizedTime_t *st, int *frac_value, int frac_digits, struct tm *ret_tm, int as_gmt)
{
    time_t tloc;
    int fv, fd = 0;

    if (frac_value) {
        tloc = asn_GT2time_frac(st, &fv, &fd, ret_tm, as_gmt);
    } else {
        return asn_GT2time_frac(st, 0, 0, ret_tm, as_gmt);
    }

    if (fd == 0 || frac_digits <= 0) {
        *frac_value = 0;
    } else {
        while (fd > frac_digits) {
            fv /= 10, fd--;
        }

        while (fd < frac_digits) {
            if (fv < INT_MAX / 10) {
                fv *= 10;
                fd++;
            } else {
                /* Too long precision request */
                fv = 0;
                break;
            }
        }

        *frac_value = fv;
    }

    return tloc;
}

time_t
asn_GT2time_frac(const GeneralizedTime_t *st, int *frac_value, int *frac_digits, struct tm *ret_tm, int as_gmt)
{
    struct tm tm_s;
    uint8_t *buf;
    uint8_t *end;
    int gmtoff_h = 0;
    int gmtoff_m = 0;
    int gmtoff = 0; /* h + m */
    int offset_specified = 0;
    int fvalue = 0;
    int fdigits = 0;
    time_t tloc;

    if (!st || !st->buf || as_gmt) {
        return -1;
    } else {
        buf = st->buf;
        end = buf + st->size;
    }

    if (st->size < 10) {
        return -1;
    }

    /*
     * Decode first 10 bytes: "AAAAMMJJhh"
     */
    memset(&tm_s, 0, sizeof(tm_s));
#undef  B2F
#undef  B2T
#define B2F(var)    do {                  \
        unsigned ch = *buf;               \
        if(ch < 0x30 || ch > 0x39) {      \
            return -1;                    \
        } else {                          \
            var = var * 10 + (ch - 0x30); \
            buf++;                        \
        }                                 \
    } while(0)
#define B2T(var)    B2F(tm_s.var)

    B2T(tm_year);   /* 1: A */
    B2T(tm_year);   /* 2: A */
    B2T(tm_year);   /* 3: A */
    B2T(tm_year);   /* 4: A */
    B2T(tm_mon);    /* 5: M */
    B2T(tm_mon);    /* 6: M */
    B2T(tm_mday);   /* 7: J */
    B2T(tm_mday);   /* 8: J */
    B2T(tm_hour);   /* 9: h */
    B2T(tm_hour);   /* 0: h */

    if (buf == end) {
        goto local_finish;
    }

    /*
     * Parse [mm[ss[(.|,)ffff]]]
     *        ^^
     */
    switch (*buf) {
    case 0x30:
    case 0x31:
    case 0x32:
    case 0x33:
    case 0x34:
    case 0x35:
    case 0x36:
    case 0x37:
    case 0x38:
    case 0x39:
        tm_s.tm_min = (*buf++) - 0x30;

        if (buf == end) {
            return -1;
        }

        B2T(tm_min);
        break;

    case 0x2B:
    case 0x2D:   /* +, - */
        goto offset;

    case 0x5A:      /* Z */
        goto utc_finish;

    default:
        return -1;
    }

    if (buf == end) {
        goto local_finish;
    }

    /*
     * Parse [mm[ss[(.|,)ffff]]]
     *           ^^
     */
    switch (*buf) {
    case 0x30:
    case 0x31:
    case 0x32:
    case 0x33:
    case 0x34:
    case 0x35:
    case 0x36:
    case 0x37:
    case 0x38:
    case 0x39:
        tm_s.tm_sec = (*buf++) - 0x30;

        if (buf == end) {
            return -1;
        }

        B2T(tm_sec);
        break;

    case 0x2B:
    case 0x2D:   /* +, - */
        goto offset;

    case 0x5A:      /* Z */
        goto utc_finish;

    default:
        return -1;
    }

    if (buf == end) {
        goto local_finish;
    }

    /*
     * Parse [mm[ss[(.|,)ffff]]]
     *               ^ ^
     */
    switch (*buf) {
    case 0x2C:
    case 0x2E: /* (.|,) */

        /*
         * Process fractions of seconds.
         */
        for (buf++; buf < end; buf++) {
            int v = *buf;

            /* GCC 4.x is being too smart without volatile */
            switch (v) {
            case 0x30:
            case 0x31:
            case 0x32:
            case 0x33:
            case 0x34:
            case 0x35:
            case 0x36:
            case 0x37:
            case 0x38:
            case 0x39:
                if (fvalue < INT_MAX / 10) {
                    fvalue = fvalue * 10 + (v - 0x30);
                    fdigits++;
                } else {
                    /* Not enough precision, ignore */
                }

                continue;

            default:
                break;
            }

            break;
        }
    }

    if (buf == end) {
        goto local_finish;
    }

    switch (*buf) {
    case 0x2B:
    case 0x2D:   /* +, - */
        goto offset;

    case 0x5A:      /* Z */
        goto utc_finish;

    default:
        return -1;
    }


offset:

    if (end - buf < 3) {
        return -1;
    }

    buf++;
    B2F(gmtoff_h);
    B2F(gmtoff_h);

    if (buf[-3] == 0x2D) { /* Negative */
        gmtoff = -1;
    } else {
        gmtoff = 1;
    }

    if ((end - buf) == 2) {
        B2F(gmtoff_m);
        B2F(gmtoff_m);
    } else if (end != buf) {
        return -1;
    }

    gmtoff = gmtoff * (3600 * gmtoff_h + 60 * gmtoff_m);

    /* fall through */
utc_finish:

    offset_specified = 1;

    /* fall through */
local_finish:

    /*
     * Validation.
     */
    if ((tm_s.tm_mon > 12 || tm_s.tm_mon < 1)
            || (tm_s.tm_mday > 31 || tm_s.tm_mday < 1)
            || (tm_s.tm_hour > 23)
            || (tm_s.tm_sec > 60)
       ) {

        return -1;
    }

    /* Canonicalize */
    tm_s.tm_mon -= 1;       /* 0 - 11 */
    tm_s.tm_year -= 1900;
    tm_s.tm_isdst =
            0;      /* XXX: летнее время определяет не правильно с параметром -1;*/

    tm_s.tm_sec -= gmtoff;

    /*** AT THIS POINT tm_s is either GMT or local (unknown) ****/

    if (offset_specified) {
        tloc = timegm(&tm_s);
    } else {
        /*
         * Without an offset (or "Z"),
         * we can only guess that it is a local zone.
         * Interpret it in this fashion.
         */
        tloc = mktime(&tm_s);
    }

    if (tloc == -1) {
        return -1;
    }

    if (ret_tm) {
        if (as_gmt) {
            if (offset_specified) {
                *ret_tm = tm_s;
            } else {
                if (gmtime_r(&tloc, ret_tm) == 0) {
                    return -1;
                }
            }
        } else {
            if (localtime_r(&tloc, ret_tm) == 0) {
                return -1;
            }
        }
    }

    /* Fractions of seconds */
    if (frac_value) {
        *frac_value = fvalue;
    }

    if (frac_digits) {
        *frac_digits = fdigits;
    }

    return tloc;
}

GeneralizedTime_t *
asn_time2GT(GeneralizedTime_t *opt_gt, const struct tm *tm, int force_gmt)
{
    return asn_time2GT_frac(opt_gt, tm, 0, 0, force_gmt);
}

GeneralizedTime_t *
asn_time2GT_frac(GeneralizedTime_t *opt_gt, const struct tm *_tm, int frac_value, int frac_digits, int force_gmt)
{
    struct tm tm_s;
    struct tm tm_c = *_tm;
    struct tm *tm = &tm_c;
    long gmtoff;
    const unsigned int buf_size =
            4 + 2 + 2   /* yyyymmdd */
            + 2 + 2 + 2 /* hhmmss */
            + 1 + 6     /* .ffffff */
            + 1 + 4     /* +hhmm */
            + 1     /* '\0' */
            ;
    char *buf;
    char *p;
    int size;

    /* Pre-allocate a buffer of sufficient yet small length */
    buf = (char *)MALLOC(buf_size);

    if (!buf) {
        return 0;
    }

    gmtoff = GMTOFF(*tm);

    /* Коррекция летнего времени. */
    if (tm->tm_isdst > 0) {
        tm_s = *tm;
        tm_s.tm_sec -= 3600;
        timegm(&tm_s);  /* Fix the time */
        tm = &tm_s;
    }

    if (force_gmt && gmtoff) {
        tm_s = *tm;
        tm_s.tm_sec -= gmtoff;
        timegm(&tm_s);  /* Fix the time */
        tm = &tm_s;
#ifdef  HAVE_TM_GMTOFF
        ASSERT(!GMTOFF(tm_s));  /* Will fix itself */
#else   /* !HAVE_TM_GMTOFF */
        gmtoff = 0;
#endif
    }

    size = snprintf(buf, buf_size, "%04d%02d%02d%02d%02d%02d",
            tm->tm_year + 1900,
            tm->tm_mon + 1,
            tm->tm_mday,
            tm->tm_hour,
            tm->tm_min,
            tm->tm_sec
                   );

    if (size != 14) {
        /* Could be ASSERT(size == 14); */
        FREEMEM(buf);

        return 0;
    }

    p = buf + size;

    /*
     * Deal with fractions.
     */
    if (frac_value > 0 && frac_digits > 0) {
        char *end = p + 1 + 6;  /* '.' + maximum 6 digits */
        char *z = p;
        long fbase;
        *z++ = '.';

        /* Place bounds on precision */
        while (frac_digits-- > 6) {
            frac_value /= 10;
        }

        /* emulate fbase = pow(10, frac_digits) */
        for (fbase = 1; frac_digits--;) {
            fbase *= 10;
        }

        do {
            int digit = frac_value / fbase;

            if (digit > 9) {
                z = 0;
                break;
            }

            *z++ = (char)(digit + 0x30);
            frac_value %= fbase;
            fbase /= 10;
        } while (fbase > 0 && frac_value > 0 && z < end);

        if (z) {
            for (--z; *z == 0x30; --z); /* Strip zeroes */

            p = z + (*z != '.');
            size = (int)(p - buf);
        }
    }

    if (force_gmt) {
        *p++ = 0x5a;    /* "Z" */
        *p++ = 0;
        size++;
    } else {
        int ret;
        gmtoff %= 86400;
        ret = snprintf(p, (buf_size - size), "%+03ld%02ld",
                gmtoff / 3600, labs(gmtoff % 3600) / 60);

        if (ret != 5) {
            FREEMEM(buf);

            return 0;
        }

        size += ret;
    }

    if (opt_gt) {
        if (opt_gt->buf) {
            FREEMEM(opt_gt->buf);
        }
    } else {
        opt_gt = (GeneralizedTime_t *)CALLOC(1, sizeof * opt_gt);

        if (!opt_gt) {
            FREEMEM(buf);
            return 0;
        }
    }

    opt_gt->buf = (unsigned char *)buf;
    opt_gt->size = size;

    return opt_gt;
}
