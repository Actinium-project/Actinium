<<<<<<< HEAD
// Copyright (c) 2016 The Bitcoin Core developers
=======
// Copyright (c) 2016-2017 The Bitcoin Core developers
>>>>>>> upstream/0.16
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_QT_TEST_RPC_NESTED_TESTS_H
#define BITCOIN_QT_TEST_RPC_NESTED_TESTS_H

#include <QObject>
#include <QTest>

<<<<<<< HEAD
#include "txdb.h"
#include "txmempool.h"
=======
#include <txdb.h>
#include <txmempool.h>
>>>>>>> upstream/0.16

class RPCNestedTests : public QObject
{
    Q_OBJECT

    private Q_SLOTS:
    void rpcNestedTests();
<<<<<<< HEAD

private:
    CCoinsViewDB *pcoinsdbview;
=======
>>>>>>> upstream/0.16
};

#endif // BITCOIN_QT_TEST_RPC_NESTED_TESTS_H
