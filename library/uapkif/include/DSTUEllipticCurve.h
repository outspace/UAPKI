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

#ifndef    _DSTUEllipticCurve_H_
#define    _DSTUEllipticCurve_H_


#include "asn_application.h"

/* Including external dependencies */
#include "ECBinary.h"
#include "OBJECT_IDENTIFIER.h"
#include "constr_CHOICE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum DSTUEllipticCurve_PR {
    DSTUEllipticCurve_PR_NOTHING,    /* No components present */
    DSTUEllipticCurve_PR_ecbinary,
    DSTUEllipticCurve_PR_namedCurve
} DSTUEllipticCurve_PR;

/* DSTUEllipticCurve */
typedef struct DSTUEllipticCurve {
    DSTUEllipticCurve_PR present;
    union DSTUEllipticCurve_u {
        ECBinary_t     ecbinary;
        OBJECT_IDENTIFIER_t     namedCurve;
    } choice;

    /* Context for parsing across buffer boundaries */
    asn_struct_ctx_t _asn_ctx;
} DSTUEllipticCurve_t;

/* Implementation */
extern asn_TYPE_descriptor_t DSTUEllipticCurve_desc;
UAPKIF_EXPORT asn_TYPE_descriptor_t *get_DSTUEllipticCurve_desc(void);

#ifdef __cplusplus
}
#endif

#endif
