/**********************************************************************
 * Copyright (c) 2013, 2014 Pieter Wuille                             *
 * Distributed under the MIT software license, see the accompanying   *
 * file COPYING or http://www.opensource.org/licenses/mit-license.php.*
 **********************************************************************/

<<<<<<< HEAD
#ifndef _SECP256K1_NUM_REPR_
#define _SECP256K1_NUM_REPR_
=======
#ifndef SECP256K1_NUM_REPR_H
#define SECP256K1_NUM_REPR_H
>>>>>>> upstream/0.16

#include <gmp.h>

#define NUM_LIMBS ((256+GMP_NUMB_BITS-1)/GMP_NUMB_BITS)

typedef struct {
    mp_limb_t data[2*NUM_LIMBS];
    int neg;
    int limbs;
} secp256k1_num;

<<<<<<< HEAD
#endif
=======
#endif /* SECP256K1_NUM_REPR_H */
>>>>>>> upstream/0.16
