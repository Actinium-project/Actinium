<<<<<<< HEAD
// Copyright (c) 2015-2016 The Bitcoin Core developers
=======
// Copyright (c) 2015-2017 The Bitcoin Core developers
>>>>>>> upstream/0.16
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_ZMQ_ZMQNOTIFICATIONINTERFACE_H
#define BITCOIN_ZMQ_ZMQNOTIFICATIONINTERFACE_H

<<<<<<< HEAD
#include "validationinterface.h"
=======
#include <validationinterface.h>
>>>>>>> upstream/0.16
#include <string>
#include <map>
#include <list>

class CBlockIndex;
class CZMQAbstractNotifier;

<<<<<<< HEAD
class CZMQNotificationInterface : public CValidationInterface
=======
class CZMQNotificationInterface final : public CValidationInterface
>>>>>>> upstream/0.16
{
public:
    virtual ~CZMQNotificationInterface();

    static CZMQNotificationInterface* Create();

protected:
    bool Initialize();
    void Shutdown();

    // CValidationInterface
    void TransactionAddedToMempool(const CTransactionRef& tx) override;
    void BlockConnected(const std::shared_ptr<const CBlock>& pblock, const CBlockIndex* pindexConnected, const std::vector<CTransactionRef>& vtxConflicted) override;
    void BlockDisconnected(const std::shared_ptr<const CBlock>& pblock) override;
    void UpdatedBlockTip(const CBlockIndex *pindexNew, const CBlockIndex *pindexFork, bool fInitialDownload) override;

private:
    CZMQNotificationInterface();

    void *pcontext;
    std::list<CZMQAbstractNotifier*> notifiers;
};

#endif // BITCOIN_ZMQ_ZMQNOTIFICATIONINTERFACE_H
