/**********************************************************************
 * Copyright (c) 2014 Pieter Wuille                                   *
 * Distributed under the MIT software license, see the accompanying   *
 * file COPYING or http://www.opensource.org/licenses/mit-license.php.*
 **********************************************************************/

<<<<<<< HEAD
#ifndef _SECP256K1_SCALAR_REPR_
#define _SECP256K1_SCALAR_REPR_
=======
#ifndef SECP256K1_SCALAR_REPR_H
#define SECP256K1_SCALAR_REPR_H
>>>>>>> upstream/0.16

#include <stdint.h>

/** A scalar modulo the group order of the secp256k1 curve. */
typedef struct {
    uint64_t d[4];
} secp256k1_scalar;

#define SECP256K1_SCALAR_CONST(d7, d6, d5, d4, d3, d2, d1, d0) {{((uint64_t)(d1)) << 32 | (d0), ((uint64_t)(d3)) << 32 | (d2), ((uint64_t)(d5)) << 32 | (d4), ((uint64_t)(d7)) << 32 | (d6)}}

<<<<<<< HEAD
#endif
=======
#endif /* SECP256K1_SCALAR_REPR_H */
>>>>>>> upstream/0.16
