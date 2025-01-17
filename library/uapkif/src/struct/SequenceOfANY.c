/*
 * Copyright (c) 2023, The UAPKI Project Authors.
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

#include "SequenceOfANY.h"

#include "asn_internal.h"

#undef FILE_MARKER
#define FILE_MARKER "pkix/struct/SequenceOfANY.c"

static asn_TYPE_member_t asn_MBR_SequenceOfANY_1[] = {
    { ATF_OPEN_TYPE | ATF_POINTER, 0, 0,
        (ber_tlv_tag_t)-1 /* Ambiguous tag (ANY?) */,
        0,
        &ANY_desc,
        0,	/* Defer constraints checking to the member type */
        0,	/* PER is not compiled, use -gen-PER */
        0,
        ""
        },
};
static const ber_tlv_tag_t SequenceOfANY_desc_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_SequenceOfANY_specs_1 = {
    sizeof(struct SequenceOfANY),
    offsetof(struct SequenceOfANY, _asn_ctx),
    0,	/* XER encoding is XMLDelimitedItemList */
};
asn_TYPE_descriptor_t SequenceOfANY_desc = {
    "SequenceOfANY",
    "SequenceOfANY",
    SEQUENCE_OF_free,
    SEQUENCE_OF_print,
    SEQUENCE_OF_constraint,
    SEQUENCE_OF_decode_ber,
    SEQUENCE_OF_encode_der,
    SEQUENCE_OF_decode_xer,
    SEQUENCE_OF_encode_xer,
    0, 0,	/* No PER support, use "-gen-PER" to enable */
    0,	/* Use generic outmost tag fetcher */
    SequenceOfANY_desc_tags_1,
    sizeof(SequenceOfANY_desc_tags_1)
        /sizeof(SequenceOfANY_desc_tags_1[0]), /* 1 */
    SequenceOfANY_desc_tags_1,	/* Same as above */
    sizeof(SequenceOfANY_desc_tags_1)
        /sizeof(SequenceOfANY_desc_tags_1[0]), /* 1 */
    0,	/* No PER visible constraints */
    asn_MBR_SequenceOfANY_1,
    1,	/* Single element */
    &asn_SPC_SequenceOfANY_specs_1	/* Additional specs */
};

asn_TYPE_descriptor_t* get_SequenceOfANY_desc(void)
{
    return &SequenceOfANY_desc;
}
