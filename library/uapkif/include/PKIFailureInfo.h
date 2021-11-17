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

#ifndef    _PKIFailureInfo_H_
#define    _PKIFailureInfo_H_


#include "asn_application.h"

/* Including external dependencies */
#include "BIT_STRING.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum PKIFailureInfo {
    PKIFailureInfo_badAlg    = 0,
    PKIFailureInfo_badRequest    = 2,
    PKIFailureInfo_badDataFormat    = 5,
    PKIFailureInfo_timeNotAvailable    = 14,
    PKIFailureInfo_unacceptedPolicy    = 15,
    PKIFailureInfo_unacceptedExtension    = 16,
    PKIFailureInfo_addInfoNotAvailable    = 17,
    PKIFailureInfo_systemFailure    = 25
} e_PKIFailureInfo;

/* PKIFailureInfo */
typedef BIT_STRING_t     PKIFailureInfo_t;

/* Implementation */
extern asn_TYPE_descriptor_t PKIFailureInfo_desc;
UAPKIF_EXPORT asn_TYPE_descriptor_t *get_PKIFailureInfo_desc(void);
asn_struct_free_f PKIFailureInfo_free;
asn_struct_print_f PKIFailureInfo_print;
asn_constr_check_f PKIFailureInfo_constraint;
ber_type_decoder_f PKIFailureInfo_decode_ber;
der_type_encoder_f PKIFailureInfo_encode_der;
xer_type_decoder_f PKIFailureInfo_decode_xer;
xer_type_encoder_f PKIFailureInfo_encode_xer;

#ifdef __cplusplus
}
#endif

#endif
