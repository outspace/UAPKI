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

#include "CMSVersion.h"

#include "asn_internal.h"

#undef FILE_MARKER
#define FILE_MARKER "pkix/struct/CMSVersion.c"

int
CMSVersion_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
        asn_app_constraint_failed_f *ctfailcb, void *app_key)
{
    /* Replace with underlying type checker */
    td->check_constraints = INTEGER_desc.check_constraints;
    return td->check_constraints(td, sptr, ctfailcb, app_key);
}

/*
 * This type is implemented using INTEGER,
 * so here we adjust the DEF accordingly.
 */
static void
CMSVersion_1_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td)
{
    td->free_struct    = INTEGER_desc.free_struct;
    td->print_struct   = INTEGER_desc.print_struct;
    td->check_constraints = INTEGER_desc.check_constraints;
    td->ber_decoder    = INTEGER_desc.ber_decoder;
    td->der_encoder    = INTEGER_desc.der_encoder;
    td->xer_decoder    = INTEGER_desc.xer_decoder;
    td->xer_encoder    = INTEGER_desc.xer_encoder;
    td->uper_decoder   = INTEGER_desc.uper_decoder;
    td->uper_encoder   = INTEGER_desc.uper_encoder;
    if (!td->per_constraints) {
        td->per_constraints = INTEGER_desc.per_constraints;
    }
    td->elements       = INTEGER_desc.elements;
    td->elements_count = INTEGER_desc.elements_count;
    td->specifics      = INTEGER_desc.specifics;
}

void
CMSVersion_free(asn_TYPE_descriptor_t *td,
        void *struct_ptr, int contents_only)
{
    CMSVersion_1_inherit_TYPE_descriptor(td);
    td->free_struct(td, struct_ptr, contents_only);
}

int
CMSVersion_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
        int ilevel, asn_app_consume_bytes_f *cb, void *app_key)
{
    CMSVersion_1_inherit_TYPE_descriptor(td);
    return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

asn_dec_rval_t
CMSVersion_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
        void **structure, const void *bufptr, size_t size, int tag_mode)
{
    CMSVersion_1_inherit_TYPE_descriptor(td);
    return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

asn_enc_rval_t
CMSVersion_encode_der(asn_TYPE_descriptor_t *td,
        void *structure, int tag_mode, ber_tlv_tag_t tag,
        asn_app_consume_bytes_f *cb, void *app_key)
{
    CMSVersion_1_inherit_TYPE_descriptor(td);
    return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

asn_dec_rval_t
CMSVersion_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
        void **structure, const char *opt_mname, const void *bufptr, size_t size)
{
    CMSVersion_1_inherit_TYPE_descriptor(td);
    return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

asn_enc_rval_t
CMSVersion_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
        int ilevel, enum xer_encoder_flags_e flags,
        asn_app_consume_bytes_f *cb, void *app_key)
{
    CMSVersion_1_inherit_TYPE_descriptor(td);
    return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

static const ber_tlv_tag_t CMSVersion_desc_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (2 << 2))
};
asn_TYPE_descriptor_t CMSVersion_desc = {
    "CMSVersion",
    "CMSVersion",
    CMSVersion_free,
    CMSVersion_print,
    CMSVersion_constraint,
    CMSVersion_decode_ber,
    CMSVersion_encode_der,
    CMSVersion_decode_xer,
    CMSVersion_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    CMSVersion_desc_tags_1,
    sizeof(CMSVersion_desc_tags_1)
    / sizeof(CMSVersion_desc_tags_1[0]), /* 1 */
    CMSVersion_desc_tags_1,    /* Same as above */
    sizeof(CMSVersion_desc_tags_1)
    / sizeof(CMSVersion_desc_tags_1[0]), /* 1 */
    0,    /* No PER visible constraints */
    0, 0,    /* Defined elsewhere */
    0    /* No specifics */
};

asn_TYPE_descriptor_t *get_CMSVersion_desc(void)
{
    return &CMSVersion_desc;
}
