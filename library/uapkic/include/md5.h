/*
 * Copyright 2021 The UAPKI Project Authors.
 * Copyright 2016 PrivatBank IT <acsk@privatbank.ua>
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

#ifndef UAPKIC_MD5_H
#define UAPKIC_MD5_H

#include "byte-array.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Контекст MD5.
 */
typedef struct MD5Ctx_st Md5Ctx;

/**
 * Створює контекст MD5.
 *
 * @return контекст MD5
 */
UAPKIC_EXPORT Md5Ctx *md5_alloc(void);

UAPKIC_EXPORT Md5Ctx* md5_copy_with_alloc(const Md5Ctx* ctx);

/**
 * Модифікує геш-вектор фрагментом даних.
 *
 * @param ctx контекст MD5
 * @param data фрагмент даних
 * @return код помилки
 */
UAPKIC_EXPORT int md5_update(Md5Ctx *ctx, const ByteArray *data);

/**
 * Завершує обчислення геш-вектора і повертає його значення.
 *
 * @param ctx контекст MD5
 * @param H геш-вектор
 * @return код помилки
 */
UAPKIC_EXPORT int md5_final(Md5Ctx *ctx, ByteArray **H);

/**
 * Звільняє контекст MD5.
 *
 * @param ctx контекст MD5
 */
UAPKIC_EXPORT void md5_free(Md5Ctx *ctx);

/**
 * Повертає розмір блоку геш-функції.
 *
 * @param ctx контекст MD5
 * @return розмір блоку, 0 у разі помилки
 */
UAPKIC_EXPORT size_t md5_get_block_size(const Md5Ctx* ctx);

/**
 * Виконує самотестування реалізації алгоритму MD5.
 *
 * @return код помилки або RET_OK, якщо самотестування пройдено
 */
UAPKIC_EXPORT int md5_self_test(void);

#ifdef __cplusplus
}
#endif

#endif
