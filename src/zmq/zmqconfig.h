<<<<<<< HEAD
// Copyright (c) 2014 The Bitcoin Core developers
=======
// Copyright (c) 2014-2017 The Bitcoin Core developers
>>>>>>> upstream/0.16
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_ZMQ_ZMQCONFIG_H
#define BITCOIN_ZMQ_ZMQCONFIG_H

#if defined(HAVE_CONFIG_H)
<<<<<<< HEAD
#include "config/bitcoin-config.h"
=======
#include <config/bitcoin-config.h>
>>>>>>> upstream/0.16
#endif

#include <stdarg.h>
#include <string>

#if ENABLE_ZMQ
#include <zmq.h>
#endif

<<<<<<< HEAD
#include "primitives/block.h"
#include "primitives/transaction.h"
=======
#include <primitives/block.h>
#include <primitives/transaction.h>
>>>>>>> upstream/0.16

void zmqError(const char *str);

#endif // BITCOIN_ZMQ_ZMQCONFIG_H
