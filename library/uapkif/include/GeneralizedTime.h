/*
 * Copyright 2021 The UAPKI Project Authors.
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
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

#ifndef    _GeneralizedTime_H_
#define    _GeneralizedTime_H_

#include "OCTET_STRING.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef OCTET_STRING_t GeneralizedTime_t;  /* Implemented via OCTET STRING */

extern asn_TYPE_descriptor_t GeneralizedTime_desc;
UAPKIF_EXPORT asn_TYPE_descriptor_t *get_GeneralizedTime_desc(void);

asn_struct_print_f GeneralizedTime_print;
asn_constr_check_f GeneralizedTime_constraint;
der_type_encoder_f GeneralizedTime_encode_der;
xer_type_encoder_f GeneralizedTime_encode_xer;

/***********************
 * Some handy helpers. *
 ***********************/

struct tm;    /* <time.h> */

/*
 * Convert a GeneralizedTime structure into time_t
 * and optionally into struct tm.
 * If as_gmt is given, the resulting _optional_tm4fill will have a GMT zone,
 * instead of default local one.
 * On error returns -1 and errno set to EINVAL
 */
UAPKIF_EXPORT time_t  asn_GT2time(const GeneralizedTime_t *, struct tm *_optional_tm4fill,
        int as_gmt);

/* A version of the above function also returning the fractions of seconds */
UAPKIF_EXPORT time_t  asn_GT2time_frac(const GeneralizedTime_t *,
        int *frac_value, int *frac_digits,    /* (value / (10 ^ digits)) */
        struct tm *_optional_tm4fill, int as_gmt);

/*
 * Another version returning fractions with defined precision
 * For example, parsing of the time ending with ".1" seconds
 * with frac_digits=3 (msec) would yield frac_value = 100.
 */
UAPKIF_EXPORT time_t  asn_GT2time_prec(const GeneralizedTime_t *,
        int *frac_value, int frac_digits,
        struct tm *_optional_tm4fill, int as_gmt);

/*
 * Convert a struct tm into GeneralizedTime.
 * If _optional_gt is not given, this function will try to allocate one.
 * If force_gmt is given, the resulting GeneralizedTime will be forced
 * into a GMT time zone (encoding ends with a "Z").
 * On error, this function returns 0 and sets errno.
 */
UAPKIF_EXPORT GeneralizedTime_t  *asn_time2GT(GeneralizedTime_t *_optional_gt,
        const struct tm *, int force_gmt);
UAPKIF_EXPORT GeneralizedTime_t  *asn_time2GT_frac(GeneralizedTime_t *_optional_gt,
        const struct tm *, int frac_value, int frac_digits, int force_gmt);

#ifdef __cplusplus
}
#endif

#endif
