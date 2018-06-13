<<<<<<< HEAD
// Copyright (c) 2014 The Bitcoin Core developers
=======
// Copyright (c) 2014-2017 The Bitcoin Core developers
>>>>>>> upstream/0.16
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_CRYPTO_HMAC_SHA256_H
#define BITCOIN_CRYPTO_HMAC_SHA256_H

<<<<<<< HEAD
#include "crypto/sha256.h"
=======
#include <crypto/sha256.h>
>>>>>>> upstream/0.16

#include <stdint.h>
#include <stdlib.h>

<<<<<<< HEAD
/** A hasher class for HMAC-SHA-512. */
=======
/** A hasher class for HMAC-SHA-256. */
>>>>>>> upstream/0.16
class CHMAC_SHA256
{
private:
    CSHA256 outer;
    CSHA256 inner;

public:
    static const size_t OUTPUT_SIZE = 32;

    CHMAC_SHA256(const unsigned char* key, size_t keylen);
    CHMAC_SHA256& Write(const unsigned char* data, size_t len)
    {
        inner.Write(data, len);
        return *this;
    }
    void Finalize(unsigned char hash[OUTPUT_SIZE]);
};

#endif // BITCOIN_CRYPTO_HMAC_SHA256_H
