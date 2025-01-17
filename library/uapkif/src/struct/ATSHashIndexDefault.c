/*
 * Copyright (c) 2023, The UAPKI Project Authors.
 * Generated by asn1c-0.9.21 (http://lionet.info/asn1c)
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

#include "ATSHashIndex.h"

#include "asn_internal.h"

#undef FILE_MARKER 
#define FILE_MARKER "struct/ATSHashIndexDefault.c"

static asn_TYPE_member_t asn_MBR_certificatesHashIndex_2[] = {
    { ATF_POINTER, 0, 0,
        (ASN_TAG_CLASS_UNIVERSAL | (4 << 2)),
        0,
        &OCTET_STRING_desc,
        0,	/* Defer constraints checking to the member type */
        0,	/* PER is not compiled, use -gen-PER */
        0,
        ""
        },
};
static ber_tlv_tag_t asn_DEF_certificatesHashIndex_tags_2[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_certificatesHashIndex_specs_2 = {
    sizeof(struct certificatesHashIndex),
    offsetof(struct certificatesHashIndex, _asn_ctx),
    0,	/* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_certificatesHashIndex_2 = {
    "certificatesHashIndex",
    "certificatesHashIndex",
    SEQUENCE_OF_free,
    SEQUENCE_OF_print,
    SEQUENCE_OF_constraint,
    SEQUENCE_OF_decode_ber,
    SEQUENCE_OF_encode_der,
    SEQUENCE_OF_decode_xer,
    SEQUENCE_OF_encode_xer,
    0, 0,	/* No PER support, use "-gen-PER" to enable */
    0,	/* Use generic outmost tag fetcher */
    asn_DEF_certificatesHashIndex_tags_2,
    sizeof(asn_DEF_certificatesHashIndex_tags_2)
        /sizeof(asn_DEF_certificatesHashIndex_tags_2[0]), /* 1 */
    asn_DEF_certificatesHashIndex_tags_2,	/* Same as above */
    sizeof(asn_DEF_certificatesHashIndex_tags_2)
        /sizeof(asn_DEF_certificatesHashIndex_tags_2[0]), /* 1 */
    0,	/* No PER visible constraints */
    asn_MBR_certificatesHashIndex_2,
    1,	/* Single element */
    &asn_SPC_certificatesHashIndex_specs_2	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_crlsHashIndex_4[] = {
    { ATF_POINTER, 0, 0,
        (ASN_TAG_CLASS_UNIVERSAL | (4 << 2)),
        0,
        &OCTET_STRING_desc,
        0,	/* Defer constraints checking to the member type */
        0,	/* PER is not compiled, use -gen-PER */
        0,
        ""
        },
};
static ber_tlv_tag_t asn_DEF_crlsHashIndex_tags_4[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_crlsHashIndex_specs_4 = {
    sizeof(struct crlsHashIndex),
    offsetof(struct crlsHashIndex, _asn_ctx),
    0,	/* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_crlsHashIndex_4 = {
    "crlsHashIndex",
    "crlsHashIndex",
    SEQUENCE_OF_free,
    SEQUENCE_OF_print,
    SEQUENCE_OF_constraint,
    SEQUENCE_OF_decode_ber,
    SEQUENCE_OF_encode_der,
    SEQUENCE_OF_decode_xer,
    SEQUENCE_OF_encode_xer,
    0, 0,	/* No PER support, use "-gen-PER" to enable */
    0,	/* Use generic outmost tag fetcher */
    asn_DEF_crlsHashIndex_tags_4,
    sizeof(asn_DEF_crlsHashIndex_tags_4)
        /sizeof(asn_DEF_crlsHashIndex_tags_4[0]), /* 1 */
    asn_DEF_crlsHashIndex_tags_4,	/* Same as above */
    sizeof(asn_DEF_crlsHashIndex_tags_4)
        /sizeof(asn_DEF_crlsHashIndex_tags_4[0]), /* 1 */
    0,	/* No PER visible constraints */
    asn_MBR_crlsHashIndex_4,
    1,	/* Single element */
    &asn_SPC_crlsHashIndex_specs_4	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_unsignedAttrsHashIndex_6[] = {
    { ATF_POINTER, 0, 0,
        (ASN_TAG_CLASS_UNIVERSAL | (4 << 2)),
        0,
        &OCTET_STRING_desc,
        0,	/* Defer constraints checking to the member type */
        0,	/* PER is not compiled, use -gen-PER */
        0,
        ""
        },
};
static ber_tlv_tag_t asn_DEF_unsignedAttrsHashIndex_tags_6[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_unsignedAttrsHashIndex_specs_6 = {
    sizeof(struct unsignedAttrsHashIndex),
    offsetof(struct unsignedAttrsHashIndex, _asn_ctx),
    0,	/* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_unsignedAttrsHashIndex_6 = {
    "unsignedAttrsHashIndex",
    "unsignedAttrsHashIndex",
    SEQUENCE_OF_free,
    SEQUENCE_OF_print,
    SEQUENCE_OF_constraint,
    SEQUENCE_OF_decode_ber,
    SEQUENCE_OF_encode_der,
    SEQUENCE_OF_decode_xer,
    SEQUENCE_OF_encode_xer,
    0, 0,	/* No PER support, use "-gen-PER" to enable */
    0,	/* Use generic outmost tag fetcher */
    asn_DEF_unsignedAttrsHashIndex_tags_6,
    sizeof(asn_DEF_unsignedAttrsHashIndex_tags_6)
        /sizeof(asn_DEF_unsignedAttrsHashIndex_tags_6[0]), /* 1 */
    asn_DEF_unsignedAttrsHashIndex_tags_6,	/* Same as above */
    sizeof(asn_DEF_unsignedAttrsHashIndex_tags_6)
        /sizeof(asn_DEF_unsignedAttrsHashIndex_tags_6[0]), /* 1 */
    0,	/* No PER visible constraints */
    asn_MBR_unsignedAttrsHashIndex_6,
    1,	/* Single element */
    &asn_SPC_unsignedAttrsHashIndex_specs_6	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_ATSHashIndexDefault_1[] = {
    { ATF_NOFLAGS, 0, offsetof(struct ATSHashIndexDefault, certificatesHashIndex),
        (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
        0,
        &asn_DEF_certificatesHashIndex_2,
        0,	/* Defer constraints checking to the member type */
        0,	/* PER is not compiled, use -gen-PER */
        0,
        "certificatesHashIndex"
        },
    { ATF_NOFLAGS, 0, offsetof(struct ATSHashIndexDefault, crlsHashIndex),
        (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
        0,
        &asn_DEF_crlsHashIndex_4,
        0,	/* Defer constraints checking to the member type */
        0,	/* PER is not compiled, use -gen-PER */
        0,
        "crlsHashIndex"
        },
    { ATF_NOFLAGS, 0, offsetof(struct ATSHashIndexDefault, unsignedAttrsHashIndex),
        (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
        0,
        &asn_DEF_unsignedAttrsHashIndex_6,
        0,	/* Defer constraints checking to the member type */
        0,	/* PER is not compiled, use -gen-PER */
        0,
        "unsignedAttrsHashIndex"
        },
};
static ber_tlv_tag_t ATSHashIndexDefault_desc_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_ATSHashIndexDefault_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 0, 0, 2 }, /* certificatesHashIndex at 3 */
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 1, -1, 1 }, /* crlsHashIndex at 4 */
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 2, -2, 0 } /* unsignedAttrsHashIndex at 5 */
};
static asn_SEQUENCE_specifics_t asn_SPC_ATSHashIndexDefault_specs_1 = {
    sizeof(struct ATSHashIndexDefault),
    offsetof(struct ATSHashIndexDefault, _asn_ctx),
    asn_MAP_ATSHashIndexDefault_tag2el_1,
    3,	/* Count of tags in the map */
    0, 0, 0,	/* Optional elements (not needed) */
    -1,	/* Start extensions */
    -1	/* Stop extensions */
};
asn_TYPE_descriptor_t ATSHashIndexDefault_desc = {
    "ATSHashIndexDefault",
    "ATSHashIndexDefault",
    SEQUENCE_free,
    SEQUENCE_print,
    SEQUENCE_constraint,
    SEQUENCE_decode_ber,
    SEQUENCE_encode_der,
    SEQUENCE_decode_xer,
    SEQUENCE_encode_xer,
    0, 0,	/* No PER support, use "-gen-PER" to enable */
    0,	/* Use generic outmost tag fetcher */
    ATSHashIndexDefault_desc_tags_1,
    sizeof(ATSHashIndexDefault_desc_tags_1)
        /sizeof(ATSHashIndexDefault_desc_tags_1[0]), /* 1 */
    ATSHashIndexDefault_desc_tags_1,	/* Same as above */
    sizeof(ATSHashIndexDefault_desc_tags_1)
        /sizeof(ATSHashIndexDefault_desc_tags_1[0]), /* 1 */
    0,	/* No PER visible constraints */
    asn_MBR_ATSHashIndexDefault_1,
    3,	/* Elements count */
    &asn_SPC_ATSHashIndexDefault_specs_1	/* Additional specs */
};

asn_TYPE_descriptor_t* get_ATSHashIndexDefault_desc(void)
{
    return &ATSHashIndexDefault_desc;
}
