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

#include "GOST28147ParamsOptionalDke.h"

#include "asn_internal.h"

#undef FILE_MARKER
#define FILE_MARKER "pkix/struct/GOST28147ParamsOptionalDke.c"

static int
memb_iv_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
        asn_app_constraint_failed_f *ctfailcb, void *app_key)
{
    const OCTET_STRING_t *st = (const OCTET_STRING_t *)sptr;
    size_t size;

    if (!sptr) {
        ASN__CTFAIL(app_key, td, sptr,
                "%s: value not given (%s:%d)",
                td->name, FILE_MARKER, __LINE__);
        return -1;
    }

    size = st->size;

    if (size == 8) {
        /* Constraint check succeeded */
        return 0;
    } else {
        ASN__CTFAIL(app_key, td, sptr,
                "%s: constraint failed (%s:%d)",
                td->name, FILE_MARKER, __LINE__);
        return -1;
    }
}

static int
memb_dke_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
        asn_app_constraint_failed_f *ctfailcb, void *app_key)
{
    const OCTET_STRING_t *st = (const OCTET_STRING_t *)sptr;
    size_t size;

    if (!sptr) {
        ASN__CTFAIL(app_key, td, sptr,
                "%s: value not given (%s:%d)",
                td->name, FILE_MARKER, __LINE__);
        return -1;
    }

    size = st->size;

    if (size == 64) {
        /* Constraint check succeeded */
        return 0;
    } else {
        ASN__CTFAIL(app_key, td, sptr,
                "%s: constraint failed (%s:%d)",
                td->name, FILE_MARKER, __LINE__);
        return -1;
    }
}

static asn_TYPE_member_t asn_MBR_GOST28147ParamsOptionalDke_1[] = {
    {
        ATF_NOFLAGS, 0, offsetof(struct GOST28147ParamsOptionalDke, iv),
        (ASN_TAG_CLASS_UNIVERSAL | (4 << 2)),
        0,
        &OCTET_STRING_desc,
        memb_iv_constraint_1,
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "iv"
    },
    {
        ATF_POINTER, 1, offsetof(struct GOST28147ParamsOptionalDke, dke),
        (ASN_TAG_CLASS_UNIVERSAL | (4 << 2)),
        0,
        &OCTET_STRING_desc,
        memb_dke_constraint_1,
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "dke"
    },
};
static const ber_tlv_tag_t GOST28147ParamsOptionalDke_desc_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_GOST28147ParamsOptionalDke_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (4 << 2)), 0, 0, 1 }, /* iv */
    { (ASN_TAG_CLASS_UNIVERSAL | (4 << 2)), 1, -1, 0 } /* dke */
};
static asn_SEQUENCE_specifics_t asn_SPC_GOST28147ParamsOptionalDke_specs_1 = {
    sizeof(struct GOST28147ParamsOptionalDke),
    offsetof(struct GOST28147ParamsOptionalDke, _asn_ctx),
    asn_MAP_GOST28147ParamsOptionalDke_tag2el_1,
    2,    /* Count of tags in the map */
    0, 0, 0,    /* Optional elements (not needed) */
    -1,    /* Start extensions */
    -1    /* Stop extensions */
};
asn_TYPE_descriptor_t GOST28147ParamsOptionalDke_desc = {
    "GOST28147ParamsOptionalDke",
    "GOST28147ParamsOptionalDke",
    SEQUENCE_free,
    SEQUENCE_print,
    SEQUENCE_constraint,
    SEQUENCE_decode_ber,
    SEQUENCE_encode_der,
    SEQUENCE_decode_xer,
    SEQUENCE_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    GOST28147ParamsOptionalDke_desc_tags_1,
    sizeof(GOST28147ParamsOptionalDke_desc_tags_1)
    / sizeof(GOST28147ParamsOptionalDke_desc_tags_1[0]), /* 1 */
    GOST28147ParamsOptionalDke_desc_tags_1,    /* Same as above */
    sizeof(GOST28147ParamsOptionalDke_desc_tags_1)
    / sizeof(GOST28147ParamsOptionalDke_desc_tags_1[0]), /* 1 */
    0,    /* No PER visible constraints */
    asn_MBR_GOST28147ParamsOptionalDke_1,
    2,    /* Elements count */
    &asn_SPC_GOST28147ParamsOptionalDke_specs_1    /* Additional specs */
};

asn_TYPE_descriptor_t *get_GOST28147ParamsOptionalDke_desc(void)
{
    return &GOST28147ParamsOptionalDke_desc;
}
