// Copyright (c) 2011-2017 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <qt/walletmodel.h>

<<<<<<< HEAD
#include <consensus/validation.h>
#include <qt/addresstablemodel.h>
=======
#include <qt/addresstablemodel.h>
#include <consensus/validation.h>
>>>>>>> upstream/0.16
#include <qt/guiconstants.h>
#include <qt/guiutil.h>
#include <qt/optionsmodel.h>
#include <qt/paymentserver.h>
#include <qt/recentrequeststablemodel.h>
#include <qt/sendcoinsdialog.h>
#include <qt/transactiontablemodel.h>

#include <base58.h>
#include <chain.h>
#include <keystore.h>
<<<<<<< HEAD
=======
#include <validation.h>
>>>>>>> upstream/0.16
#include <net.h> // for g_connman
#include <policy/fees.h>
#include <policy/rbf.h>
#include <sync.h>
#include <ui_interface.h>
#include <util.h> // for GetBoolArg
<<<<<<< HEAD
#include <validation.h>
=======
>>>>>>> upstream/0.16
#include <wallet/coincontrol.h>
#include <wallet/feebumper.h>
#include <wallet/wallet.h>
#include <wallet/walletdb.h> // for BackupWallet

#include <stdint.h>

#include <QDebug>
#include <QMessageBox>
#include <QSet>
#include <QTimer>


<<<<<<< HEAD
WalletModel::WalletModel(const PlatformStyle* platformStyle, CWallet* _wallet, OptionsModel* _optionsModel, QObject* parent) : QObject(parent), wallet(_wallet), optionsModel(_optionsModel), addressTableModel(0),
                                                                                                                               transactionTableModel(0),
                                                                                                                               recentRequestsTableModel(0),
                                                                                                                               cachedBalance(0), cachedUnconfirmedBalance(0), cachedImmatureBalance(0),
                                                                                                                               cachedEncryptionStatus(Unencrypted),
                                                                                                                               cachedNumBlocks(0)
=======
WalletModel::WalletModel(const PlatformStyle *platformStyle, CWallet *_wallet, OptionsModel *_optionsModel, QObject *parent) :
    QObject(parent), wallet(_wallet), optionsModel(_optionsModel), addressTableModel(0),
    transactionTableModel(0),
    recentRequestsTableModel(0),
    cachedBalance(0), cachedUnconfirmedBalance(0), cachedImmatureBalance(0),
    cachedEncryptionStatus(Unencrypted),
    cachedNumBlocks(0)
>>>>>>> upstream/0.16
{
    fHaveWatchOnly = wallet->HaveWatchOnly();
    fForceCheckBalanceChanged = false;

    addressTableModel = new AddressTableModel(wallet, this);
    transactionTableModel = new TransactionTableModel(platformStyle, wallet, this);
    recentRequestsTableModel = new RecentRequestsTableModel(wallet, this);

    // This timer will be fired repeatedly to update the balance
    pollTimer = new QTimer(this);
    connect(pollTimer, SIGNAL(timeout()), this, SLOT(pollBalanceChanged()));
    pollTimer->start(MODEL_UPDATE_DELAY);

    subscribeToCoreSignals();
}

WalletModel::~WalletModel()
{
    unsubscribeFromCoreSignals();
}

<<<<<<< HEAD
CAmount WalletModel::getBalance(const CCoinControl* coinControl) const
{
    if (coinControl) {
=======
CAmount WalletModel::getBalance(const CCoinControl *coinControl) const
{
    if (coinControl)
    {
>>>>>>> upstream/0.16
        return wallet->GetAvailableBalance(coinControl);
    }

    return wallet->GetBalance();
}

CAmount WalletModel::getUnconfirmedBalance() const
{
    return wallet->GetUnconfirmedBalance();
}

CAmount WalletModel::getImmatureBalance() const
{
    return wallet->GetImmatureBalance();
}

bool WalletModel::haveWatchOnly() const
{
    return fHaveWatchOnly;
}

CAmount WalletModel::getWatchBalance() const
{
    return wallet->GetWatchOnlyBalance();
}

CAmount WalletModel::getWatchUnconfirmedBalance() const
{
    return wallet->GetUnconfirmedWatchOnlyBalance();
}

CAmount WalletModel::getWatchImmatureBalance() const
{
    return wallet->GetImmatureWatchOnlyBalance();
}

void WalletModel::updateStatus()
{
    EncryptionStatus newEncryptionStatus = getEncryptionStatus();

<<<<<<< HEAD
    if (cachedEncryptionStatus != newEncryptionStatus)
=======
    if(cachedEncryptionStatus != newEncryptionStatus)
>>>>>>> upstream/0.16
        Q_EMIT encryptionStatusChanged(newEncryptionStatus);
}

void WalletModel::pollBalanceChanged()
{
    // Get required locks upfront. This avoids the GUI from getting stuck on
    // periodical polls if the core is holding the locks for a longer time -
    // for example, during a wallet rescan.
    TRY_LOCK(cs_main, lockMain);
<<<<<<< HEAD
    if (!lockMain)
        return;
    TRY_LOCK(wallet->cs_wallet, lockWallet);
    if (!lockWallet)
        return;

    if (fForceCheckBalanceChanged || chainActive.Height() != cachedNumBlocks) {
=======
    if(!lockMain)
        return;
    TRY_LOCK(wallet->cs_wallet, lockWallet);
    if(!lockWallet)
        return;

    if(fForceCheckBalanceChanged || chainActive.Height() != cachedNumBlocks)
    {
>>>>>>> upstream/0.16
        fForceCheckBalanceChanged = false;

        // Balance and number of transactions might have changed
        cachedNumBlocks = chainActive.Height();

        checkBalanceChanged();
<<<<<<< HEAD
        if (transactionTableModel)
=======
        if(transactionTableModel)
>>>>>>> upstream/0.16
            transactionTableModel->updateConfirmations();
    }
}

void WalletModel::checkBalanceChanged()
{
    CAmount newBalance = getBalance();
    CAmount newUnconfirmedBalance = getUnconfirmedBalance();
    CAmount newImmatureBalance = getImmatureBalance();
    CAmount newWatchOnlyBalance = 0;
    CAmount newWatchUnconfBalance = 0;
    CAmount newWatchImmatureBalance = 0;
<<<<<<< HEAD
    if (haveWatchOnly()) {
=======
    if (haveWatchOnly())
    {
>>>>>>> upstream/0.16
        newWatchOnlyBalance = getWatchBalance();
        newWatchUnconfBalance = getWatchUnconfirmedBalance();
        newWatchImmatureBalance = getWatchImmatureBalance();
    }

<<<<<<< HEAD
    if (cachedBalance != newBalance || cachedUnconfirmedBalance != newUnconfirmedBalance || cachedImmatureBalance != newImmatureBalance ||
        cachedWatchOnlyBalance != newWatchOnlyBalance || cachedWatchUnconfBalance != newWatchUnconfBalance || cachedWatchImmatureBalance != newWatchImmatureBalance) {
=======
    if(cachedBalance != newBalance || cachedUnconfirmedBalance != newUnconfirmedBalance || cachedImmatureBalance != newImmatureBalance ||
        cachedWatchOnlyBalance != newWatchOnlyBalance || cachedWatchUnconfBalance != newWatchUnconfBalance || cachedWatchImmatureBalance != newWatchImmatureBalance)
    {
>>>>>>> upstream/0.16
        cachedBalance = newBalance;
        cachedUnconfirmedBalance = newUnconfirmedBalance;
        cachedImmatureBalance = newImmatureBalance;
        cachedWatchOnlyBalance = newWatchOnlyBalance;
        cachedWatchUnconfBalance = newWatchUnconfBalance;
        cachedWatchImmatureBalance = newWatchImmatureBalance;
        Q_EMIT balanceChanged(newBalance, newUnconfirmedBalance, newImmatureBalance,
<<<<<<< HEAD
            newWatchOnlyBalance, newWatchUnconfBalance, newWatchImmatureBalance);
=======
                            newWatchOnlyBalance, newWatchUnconfBalance, newWatchImmatureBalance);
>>>>>>> upstream/0.16
    }
}

void WalletModel::updateTransaction()
{
    // Balance and number of transactions might have changed
    fForceCheckBalanceChanged = true;
}

<<<<<<< HEAD
void WalletModel::updateAddressBook(const QString& address, const QString& label, bool isMine, const QString& purpose, int status)
{
    if (addressTableModel)
=======
void WalletModel::updateAddressBook(const QString &address, const QString &label,
        bool isMine, const QString &purpose, int status)
{
    if(addressTableModel)
>>>>>>> upstream/0.16
        addressTableModel->updateEntry(address, label, isMine, purpose, status);
}

void WalletModel::updateWatchOnlyFlag(bool fHaveWatchonly)
{
    fHaveWatchOnly = fHaveWatchonly;
    Q_EMIT notifyWatchonlyChanged(fHaveWatchonly);
}

<<<<<<< HEAD
bool WalletModel::validateAddress(const QString& address)
=======
bool WalletModel::validateAddress(const QString &address)
>>>>>>> upstream/0.16
{
    return IsValidDestinationString(address.toStdString());
}

<<<<<<< HEAD
WalletModel::SendCoinsReturn WalletModel::prepareTransaction(WalletModelTransaction& transaction, const CCoinControl& coinControl)
=======
WalletModel::SendCoinsReturn WalletModel::prepareTransaction(WalletModelTransaction &transaction, const CCoinControl& coinControl)
>>>>>>> upstream/0.16
{
    CAmount total = 0;
    bool fSubtractFeeFromAmount = false;
    QList<SendCoinsRecipient> recipients = transaction.getRecipients();
    std::vector<CRecipient> vecSend;

<<<<<<< HEAD
    if (recipients.empty()) {
=======
    if(recipients.empty())
    {
>>>>>>> upstream/0.16
        return OK;
    }

    QSet<QString> setAddress; // Used to detect duplicates
    int nAddresses = 0;

    // Pre-check input data for validity
<<<<<<< HEAD
    for (const SendCoinsRecipient& rcp : recipients) {
        if (rcp.fSubtractFeeFromAmount)
            fSubtractFeeFromAmount = true;

        if (rcp.paymentRequest.IsInitialized()) { // PaymentRequest...
            CAmount subtotal = 0;
            const payments::PaymentDetails& details = rcp.paymentRequest.getDetails();
            for (int i = 0; i < details.outputs_size(); i++) {
=======
    for (const SendCoinsRecipient &rcp : recipients)
    {
        if (rcp.fSubtractFeeFromAmount)
            fSubtractFeeFromAmount = true;

        if (rcp.paymentRequest.IsInitialized())
        {   // PaymentRequest...
            CAmount subtotal = 0;
            const payments::PaymentDetails& details = rcp.paymentRequest.getDetails();
            for (int i = 0; i < details.outputs_size(); i++)
            {
>>>>>>> upstream/0.16
                const payments::Output& out = details.outputs(i);
                if (out.amount() <= 0) continue;
                subtotal += out.amount();
                const unsigned char* scriptStr = (const unsigned char*)out.script().data();
<<<<<<< HEAD
                CScript scriptPubKey(scriptStr, scriptStr + out.script().size());
=======
                CScript scriptPubKey(scriptStr, scriptStr+out.script().size());
>>>>>>> upstream/0.16
                CAmount nAmount = out.amount();
                CRecipient recipient = {scriptPubKey, nAmount, rcp.fSubtractFeeFromAmount};
                vecSend.push_back(recipient);
            }
<<<<<<< HEAD
            if (subtotal <= 0) {
                return InvalidAmount;
            }
            total += subtotal;
        } else { // User-entered bitcoin address / amount:
            if (!validateAddress(rcp.address)) {
                return InvalidAddress;
            }
            if (rcp.amount <= 0) {
=======
            if (subtotal <= 0)
            {
                return InvalidAmount;
            }
            total += subtotal;
        }
        else
        {   // User-entered bitcoin address / amount:
            if(!validateAddress(rcp.address))
            {
                return InvalidAddress;
            }
            if(rcp.amount <= 0)
            {
>>>>>>> upstream/0.16
                return InvalidAmount;
            }
            setAddress.insert(rcp.address);
            ++nAddresses;

            CScript scriptPubKey = GetScriptForDestination(DecodeDestination(rcp.address.toStdString()));
            CRecipient recipient = {scriptPubKey, rcp.amount, rcp.fSubtractFeeFromAmount};
            vecSend.push_back(recipient);

            total += rcp.amount;
        }
    }
<<<<<<< HEAD
    if (setAddress.size() != nAddresses) {
=======
    if(setAddress.size() != nAddresses)
    {
>>>>>>> upstream/0.16
        return DuplicateAddress;
    }

    CAmount nBalance = getBalance(&coinControl);

<<<<<<< HEAD
    if (total > nBalance) {
=======
    if(total > nBalance)
    {
>>>>>>> upstream/0.16
        return AmountExceedsBalance;
    }

    {
        LOCK2(cs_main, wallet->cs_wallet);

        transaction.newPossibleKeyChange(wallet);

        CAmount nFeeRequired = 0;
        int nChangePosRet = -1;
        std::string strFailReason;

<<<<<<< HEAD
        CWalletTx* newTx = transaction.getTransaction();
        CReserveKey* keyChange = transaction.getPossibleKeyChange();
=======
        CWalletTx *newTx = transaction.getTransaction();
        CReserveKey *keyChange = transaction.getPossibleKeyChange();
>>>>>>> upstream/0.16
        bool fCreated = wallet->CreateTransaction(vecSend, *newTx, *keyChange, nFeeRequired, nChangePosRet, strFailReason, coinControl);
        transaction.setTransactionFee(nFeeRequired);
        if (fSubtractFeeFromAmount && fCreated)
            transaction.reassignAmounts(nChangePosRet);

<<<<<<< HEAD
        if (!fCreated) {
            if (!fSubtractFeeFromAmount && (total + nFeeRequired) > nBalance) {
                return SendCoinsReturn(AmountWithFeeExceedsBalance);
            }
            Q_EMIT message(tr("Send Coins"), QString::fromStdString(strFailReason),
                CClientUIInterface::MSG_ERROR);
=======
        if(!fCreated)
        {
            if(!fSubtractFeeFromAmount && (total + nFeeRequired) > nBalance)
            {
                return SendCoinsReturn(AmountWithFeeExceedsBalance);
            }
            Q_EMIT message(tr("Send Coins"), QString::fromStdString(strFailReason),
                         CClientUIInterface::MSG_ERROR);
>>>>>>> upstream/0.16
            return TransactionCreationFailed;
        }

        // reject absurdly high fee. (This can never happen because the
        // wallet caps the fee at maxTxFee. This merely serves as a
        // belt-and-suspenders check)
        if (nFeeRequired > maxTxFee)
            return AbsurdFee;
    }

    return SendCoinsReturn(OK);
}

<<<<<<< HEAD
WalletModel::SendCoinsReturn WalletModel::sendCoins(WalletModelTransaction& transaction)
=======
WalletModel::SendCoinsReturn WalletModel::sendCoins(WalletModelTransaction &transaction)
>>>>>>> upstream/0.16
{
    QByteArray transaction_array; /* store serialized transaction */

    {
        LOCK2(cs_main, wallet->cs_wallet);
<<<<<<< HEAD
        CWalletTx* newTx = transaction.getTransaction();

        for (const SendCoinsRecipient& rcp : transaction.getRecipients()) {
            if (rcp.paymentRequest.IsInitialized()) {
=======
        CWalletTx *newTx = transaction.getTransaction();

        for (const SendCoinsRecipient &rcp : transaction.getRecipients())
        {
            if (rcp.paymentRequest.IsInitialized())
            {
>>>>>>> upstream/0.16
                // Make sure any payment requests involved are still valid.
                if (PaymentServer::verifyExpired(rcp.paymentRequest.getDetails())) {
                    return PaymentRequestExpired;
                }

                // Store PaymentRequests in wtx.vOrderForm in wallet.
                std::string key("PaymentRequest");
                std::string value;
                rcp.paymentRequest.SerializeToString(&value);
                newTx->vOrderForm.push_back(make_pair(key, value));
<<<<<<< HEAD
            } else if (!rcp.message.isEmpty()) // Message from normal bitcoin:URI (bitcoin:123...?message=example)
                newTx->vOrderForm.push_back(make_pair("Message", rcp.message.toStdString()));
        }

        CReserveKey* keyChange = transaction.getPossibleKeyChange();
        CValidationState state;
        if (!wallet->CommitTransaction(*newTx, *keyChange, g_connman.get(), state))
=======
            }
            else if (!rcp.message.isEmpty()) // Message from normal bitcoin:URI (bitcoin:123...?message=example)
                newTx->vOrderForm.push_back(make_pair("Message", rcp.message.toStdString()));
        }

        CReserveKey *keyChange = transaction.getPossibleKeyChange();
        CValidationState state;
        if(!wallet->CommitTransaction(*newTx, *keyChange, g_connman.get(), state))
>>>>>>> upstream/0.16
            return SendCoinsReturn(TransactionCommitFailed, QString::fromStdString(state.GetRejectReason()));

        CDataStream ssTx(SER_NETWORK, PROTOCOL_VERSION);
        ssTx << *newTx->tx;
        transaction_array.append(&(ssTx[0]), ssTx.size());
    }

    // Add addresses / update labels that we've sent to the address book,
    // and emit coinsSent signal for each recipient
<<<<<<< HEAD
    for (const SendCoinsRecipient& rcp : transaction.getRecipients()) {
        // Don't touch the address book when we have a payment request
        if (!rcp.paymentRequest.IsInitialized()) {
=======
    for (const SendCoinsRecipient &rcp : transaction.getRecipients())
    {
        // Don't touch the address book when we have a payment request
        if (!rcp.paymentRequest.IsInitialized())
        {
>>>>>>> upstream/0.16
            std::string strAddress = rcp.address.toStdString();
            CTxDestination dest = DecodeDestination(strAddress);
            std::string strLabel = rcp.label.toStdString();
            {
                LOCK(wallet->cs_wallet);

                std::map<CTxDestination, CAddressBookData>::iterator mi = wallet->mapAddressBook.find(dest);

                // Check if we have a new address or an updated label
<<<<<<< HEAD
                if (mi == wallet->mapAddressBook.end()) {
                    wallet->SetAddressBook(dest, strLabel, "send");
                } else if (mi->second.name != strLabel) {
=======
                if (mi == wallet->mapAddressBook.end())
                {
                    wallet->SetAddressBook(dest, strLabel, "send");
                }
                else if (mi->second.name != strLabel)
                {
>>>>>>> upstream/0.16
                    wallet->SetAddressBook(dest, strLabel, ""); // "" means don't change purpose
                }
            }
        }
        Q_EMIT coinsSent(wallet, rcp, transaction_array);
    }
    checkBalanceChanged(); // update balance immediately, otherwise there could be a short noticeable delay until pollBalanceChanged hits

    return SendCoinsReturn(OK);
}

<<<<<<< HEAD
OptionsModel* WalletModel::getOptionsModel()
=======
OptionsModel *WalletModel::getOptionsModel()
>>>>>>> upstream/0.16
{
    return optionsModel;
}

<<<<<<< HEAD
AddressTableModel* WalletModel::getAddressTableModel()
=======
AddressTableModel *WalletModel::getAddressTableModel()
>>>>>>> upstream/0.16
{
    return addressTableModel;
}

<<<<<<< HEAD
TransactionTableModel* WalletModel::getTransactionTableModel()
=======
TransactionTableModel *WalletModel::getTransactionTableModel()
>>>>>>> upstream/0.16
{
    return transactionTableModel;
}

<<<<<<< HEAD
RecentRequestsTableModel* WalletModel::getRecentRequestsTableModel()
=======
RecentRequestsTableModel *WalletModel::getRecentRequestsTableModel()
>>>>>>> upstream/0.16
{
    return recentRequestsTableModel;
}

WalletModel::EncryptionStatus WalletModel::getEncryptionStatus() const
{
<<<<<<< HEAD
    if (!wallet->IsCrypted()) {
        return Unencrypted;
    } else if (wallet->IsLocked()) {
        return Locked;
    } else {
=======
    if(!wallet->IsCrypted())
    {
        return Unencrypted;
    }
    else if(wallet->IsLocked())
    {
        return Locked;
    }
    else
    {
>>>>>>> upstream/0.16
        return Unlocked;
    }
}

<<<<<<< HEAD
bool WalletModel::setWalletEncrypted(bool encrypted, const SecureString& passphrase)
{
    if (encrypted) {
        // Encrypt
        return wallet->EncryptWallet(passphrase);
    } else {
=======
bool WalletModel::setWalletEncrypted(bool encrypted, const SecureString &passphrase)
{
    if(encrypted)
    {
        // Encrypt
        return wallet->EncryptWallet(passphrase);
    }
    else
    {
>>>>>>> upstream/0.16
        // Decrypt -- TODO; not supported yet
        return false;
    }
}

<<<<<<< HEAD
bool WalletModel::setWalletLocked(bool locked, const SecureString& passPhrase)
{
    if (locked) {
        // Lock
        return wallet->Lock();
    } else {
=======
bool WalletModel::setWalletLocked(bool locked, const SecureString &passPhrase)
{
    if(locked)
    {
        // Lock
        return wallet->Lock();
    }
    else
    {
>>>>>>> upstream/0.16
        // Unlock
        return wallet->Unlock(passPhrase);
    }
}

<<<<<<< HEAD
bool WalletModel::changePassphrase(const SecureString& oldPass, const SecureString& newPass)
=======
bool WalletModel::changePassphrase(const SecureString &oldPass, const SecureString &newPass)
>>>>>>> upstream/0.16
{
    bool retval;
    {
        LOCK(wallet->cs_wallet);
        wallet->Lock(); // Make sure wallet is locked before attempting pass change
        retval = wallet->ChangeWalletPassphrase(oldPass, newPass);
    }
    return retval;
}

<<<<<<< HEAD
bool WalletModel::backupWallet(const QString& filename)
=======
bool WalletModel::backupWallet(const QString &filename)
>>>>>>> upstream/0.16
{
    return wallet->BackupWallet(filename.toLocal8Bit().data());
}

// Handlers for core signals
<<<<<<< HEAD
static void NotifyKeyStoreStatusChanged(WalletModel* walletmodel, CCryptoKeyStore* wallet)
=======
static void NotifyKeyStoreStatusChanged(WalletModel *walletmodel, CCryptoKeyStore *wallet)
>>>>>>> upstream/0.16
{
    qDebug() << "NotifyKeyStoreStatusChanged";
    QMetaObject::invokeMethod(walletmodel, "updateStatus", Qt::QueuedConnection);
}

<<<<<<< HEAD
static void NotifyAddressBookChanged(WalletModel* walletmodel, CWallet* wallet, const CTxDestination& address, const std::string& label, bool isMine, const std::string& purpose, ChangeType status)
=======
static void NotifyAddressBookChanged(WalletModel *walletmodel, CWallet *wallet,
        const CTxDestination &address, const std::string &label, bool isMine,
        const std::string &purpose, ChangeType status)
>>>>>>> upstream/0.16
{
    QString strAddress = QString::fromStdString(EncodeDestination(address));
    QString strLabel = QString::fromStdString(label);
    QString strPurpose = QString::fromStdString(purpose);

    qDebug() << "NotifyAddressBookChanged: " + strAddress + " " + strLabel + " isMine=" + QString::number(isMine) + " purpose=" + strPurpose + " status=" + QString::number(status);
    QMetaObject::invokeMethod(walletmodel, "updateAddressBook", Qt::QueuedConnection,
<<<<<<< HEAD
        Q_ARG(QString, strAddress),
        Q_ARG(QString, strLabel),
        Q_ARG(bool, isMine),
        Q_ARG(QString, strPurpose),
        Q_ARG(int, status));
}

static void NotifyTransactionChanged(WalletModel* walletmodel, CWallet* wallet, const uint256& hash, ChangeType status)
=======
                              Q_ARG(QString, strAddress),
                              Q_ARG(QString, strLabel),
                              Q_ARG(bool, isMine),
                              Q_ARG(QString, strPurpose),
                              Q_ARG(int, status));
}

static void NotifyTransactionChanged(WalletModel *walletmodel, CWallet *wallet, const uint256 &hash, ChangeType status)
>>>>>>> upstream/0.16
{
    Q_UNUSED(wallet);
    Q_UNUSED(hash);
    Q_UNUSED(status);
    QMetaObject::invokeMethod(walletmodel, "updateTransaction", Qt::QueuedConnection);
}

<<<<<<< HEAD
static void ShowProgress(WalletModel* walletmodel, const std::string& title, int nProgress)
{
    // emits signal "showProgress"
    QMetaObject::invokeMethod(walletmodel, "showProgress", Qt::QueuedConnection,
        Q_ARG(QString, QString::fromStdString(title)),
        Q_ARG(int, nProgress));
}

static void NotifyWatchonlyChanged(WalletModel* walletmodel, bool fHaveWatchonly)
{
    QMetaObject::invokeMethod(walletmodel, "updateWatchOnlyFlag", Qt::QueuedConnection,
        Q_ARG(bool, fHaveWatchonly));
=======
static void ShowProgress(WalletModel *walletmodel, const std::string &title, int nProgress)
{
    // emits signal "showProgress"
    QMetaObject::invokeMethod(walletmodel, "showProgress", Qt::QueuedConnection,
                              Q_ARG(QString, QString::fromStdString(title)),
                              Q_ARG(int, nProgress));
}

static void NotifyWatchonlyChanged(WalletModel *walletmodel, bool fHaveWatchonly)
{
    QMetaObject::invokeMethod(walletmodel, "updateWatchOnlyFlag", Qt::QueuedConnection,
                              Q_ARG(bool, fHaveWatchonly));
>>>>>>> upstream/0.16
}

void WalletModel::subscribeToCoreSignals()
{
    // Connect signals to wallet
    wallet->NotifyStatusChanged.connect(boost::bind(&NotifyKeyStoreStatusChanged, this, _1));
    wallet->NotifyAddressBookChanged.connect(boost::bind(NotifyAddressBookChanged, this, _1, _2, _3, _4, _5, _6));
    wallet->NotifyTransactionChanged.connect(boost::bind(NotifyTransactionChanged, this, _1, _2, _3));
    wallet->ShowProgress.connect(boost::bind(ShowProgress, this, _1, _2));
    wallet->NotifyWatchonlyChanged.connect(boost::bind(NotifyWatchonlyChanged, this, _1));
}

void WalletModel::unsubscribeFromCoreSignals()
{
    // Disconnect signals from wallet
    wallet->NotifyStatusChanged.disconnect(boost::bind(&NotifyKeyStoreStatusChanged, this, _1));
    wallet->NotifyAddressBookChanged.disconnect(boost::bind(NotifyAddressBookChanged, this, _1, _2, _3, _4, _5, _6));
    wallet->NotifyTransactionChanged.disconnect(boost::bind(NotifyTransactionChanged, this, _1, _2, _3));
    wallet->ShowProgress.disconnect(boost::bind(ShowProgress, this, _1, _2));
    wallet->NotifyWatchonlyChanged.disconnect(boost::bind(NotifyWatchonlyChanged, this, _1));
}

// WalletModel::UnlockContext implementation
WalletModel::UnlockContext WalletModel::requestUnlock()
{
    bool was_locked = getEncryptionStatus() == Locked;
<<<<<<< HEAD
    if (was_locked) {
=======
    if(was_locked)
    {
>>>>>>> upstream/0.16
        // Request UI to unlock wallet
        Q_EMIT requireUnlock();
    }
    // If wallet is still locked, unlock was failed or cancelled, mark context as invalid
    bool valid = getEncryptionStatus() != Locked;

    return UnlockContext(this, valid, was_locked);
}

<<<<<<< HEAD
WalletModel::UnlockContext::UnlockContext(WalletModel* _wallet, bool _valid, bool _relock) : wallet(_wallet),
                                                                                             valid(_valid),
                                                                                             relock(_relock)
=======
WalletModel::UnlockContext::UnlockContext(WalletModel *_wallet, bool _valid, bool _relock):
        wallet(_wallet),
        valid(_valid),
        relock(_relock)
>>>>>>> upstream/0.16
{
}

WalletModel::UnlockContext::~UnlockContext()
{
<<<<<<< HEAD
    if (valid && relock) {
=======
    if(valid && relock)
    {
>>>>>>> upstream/0.16
        wallet->setWalletLocked(true);
    }
}

void WalletModel::UnlockContext::CopyFrom(const UnlockContext& rhs)
{
    // Transfer context; old object no longer relocks wallet
    *this = rhs;
    rhs.relock = false;
}

<<<<<<< HEAD
bool WalletModel::getPubKey(const CKeyID& address, CPubKey& vchPubKeyOut) const
=======
bool WalletModel::getPubKey(const CKeyID &address, CPubKey& vchPubKeyOut) const
>>>>>>> upstream/0.16
{
    return wallet->GetPubKey(address, vchPubKeyOut);
}

bool WalletModel::IsSpendable(const CTxDestination& dest) const
{
    return IsMine(*wallet, dest) & ISMINE_SPENDABLE;
}

<<<<<<< HEAD
bool WalletModel::getPrivKey(const CKeyID& address, CKey& vchPrivKeyOut) const
=======
bool WalletModel::getPrivKey(const CKeyID &address, CKey& vchPrivKeyOut) const
>>>>>>> upstream/0.16
{
    return wallet->GetKey(address, vchPrivKeyOut);
}

// returns a list of COutputs from COutPoints
void WalletModel::getOutputs(const std::vector<COutPoint>& vOutpoints, std::vector<COutput>& vOutputs)
{
    LOCK2(cs_main, wallet->cs_wallet);
<<<<<<< HEAD
    for (const COutPoint& outpoint : vOutpoints) {
=======
    for (const COutPoint& outpoint : vOutpoints)
    {
>>>>>>> upstream/0.16
        auto it = wallet->mapWallet.find(outpoint.hash);
        if (it == wallet->mapWallet.end()) continue;
        int nDepth = it->second.GetDepthInMainChain();
        if (nDepth < 0) continue;
        COutput out(&it->second, outpoint.n, nDepth, true /* spendable */, true /* solvable */, true /* safe */);
        vOutputs.push_back(out);
    }
}

bool WalletModel::isSpent(const COutPoint& outpoint) const
{
    LOCK2(cs_main, wallet->cs_wallet);
    return wallet->IsSpent(outpoint.hash, outpoint.n);
}

// AvailableCoins + LockedCoins grouped by wallet address (put change in one group with wallet address)
<<<<<<< HEAD
void WalletModel::listCoins(std::map<QString, std::vector<COutput>>& mapCoins) const
=======
void WalletModel::listCoins(std::map<QString, std::vector<COutput> >& mapCoins) const
>>>>>>> upstream/0.16
{
    for (auto& group : wallet->ListCoins()) {
        auto& resultGroup = mapCoins[QString::fromStdString(EncodeDestination(group.first))];
        for (auto& coin : group.second) {
            resultGroup.emplace_back(std::move(coin));
        }
    }
}

bool WalletModel::isLockedCoin(uint256 hash, unsigned int n) const
{
    LOCK2(cs_main, wallet->cs_wallet);
    return wallet->IsLockedCoin(hash, n);
}

void WalletModel::lockCoin(COutPoint& output)
{
    LOCK2(cs_main, wallet->cs_wallet);
    wallet->LockCoin(output);
}

void WalletModel::unlockCoin(COutPoint& output)
{
    LOCK2(cs_main, wallet->cs_wallet);
    wallet->UnlockCoin(output);
}

void WalletModel::listLockedCoins(std::vector<COutPoint>& vOutpts)
{
    LOCK2(cs_main, wallet->cs_wallet);
    wallet->ListLockedCoins(vOutpts);
}

void WalletModel::loadReceiveRequests(std::vector<std::string>& vReceiveRequests)
{
    vReceiveRequests = wallet->GetDestValues("rr"); // receive request
}

<<<<<<< HEAD
bool WalletModel::saveReceiveRequest(const std::string& sAddress, const int64_t nId, const std::string& sRequest)
=======
bool WalletModel::saveReceiveRequest(const std::string &sAddress, const int64_t nId, const std::string &sRequest)
>>>>>>> upstream/0.16
{
    CTxDestination dest = DecodeDestination(sAddress);

    std::stringstream ss;
    ss << nId;
    std::string key = "rr" + ss.str(); // "rr" prefix = "receive request" in destdata

    LOCK(wallet->cs_wallet);
    if (sRequest.empty())
        return wallet->EraseDestData(dest, key);
    else
        return wallet->AddDestData(dest, key, sRequest);
}

bool WalletModel::transactionCanBeAbandoned(uint256 hash) const
{
    return wallet->TransactionCanBeAbandoned(hash);
}

bool WalletModel::abandonTransaction(uint256 hash) const
{
    LOCK2(cs_main, wallet->cs_wallet);
    return wallet->AbandonTransaction(hash);
}

bool WalletModel::transactionCanBeBumped(uint256 hash) const
{
    return feebumper::TransactionCanBeBumped(wallet, hash);
}

bool WalletModel::bumpFee(uint256 hash)
{
    CCoinControl coin_control;
    coin_control.signalRbf = true;
    std::vector<std::string> errors;
    CAmount old_fee;
    CAmount new_fee;
    CMutableTransaction mtx;
    if (feebumper::CreateTransaction(wallet, hash, coin_control, 0 /* totalFee */, errors, old_fee, new_fee, mtx) != feebumper::Result::OK) {
<<<<<<< HEAD
        QMessageBox::critical(0, tr("Fee bump error"), tr("Increasing transaction fee failed") + "<br />(" + (errors.size() ? QString::fromStdString(errors[0]) : "") + ")");
        return false;
=======
        QMessageBox::critical(0, tr("Fee bump error"), tr("Increasing transaction fee failed") + "<br />(" +
            (errors.size() ? QString::fromStdString(errors[0]) : "") +")");
         return false;
>>>>>>> upstream/0.16
    }

    // allow a user based fee verification
    QString questionString = tr("Do you want to increase the fee?");
    questionString.append("<br />");
    questionString.append("<table style=\"text-align: left;\">");
    questionString.append("<tr><td>");
    questionString.append(tr("Current fee:"));
    questionString.append("</td><td>");
    questionString.append(BitcoinUnits::formatHtmlWithUnit(getOptionsModel()->getDisplayUnit(), old_fee));
    questionString.append("</td></tr><tr><td>");
    questionString.append(tr("Increase:"));
    questionString.append("</td><td>");
    questionString.append(BitcoinUnits::formatHtmlWithUnit(getOptionsModel()->getDisplayUnit(), new_fee - old_fee));
    questionString.append("</td></tr><tr><td>");
    questionString.append(tr("New fee:"));
    questionString.append("</td><td>");
    questionString.append(BitcoinUnits::formatHtmlWithUnit(getOptionsModel()->getDisplayUnit(), new_fee));
    questionString.append("</td></tr></table>");
    SendConfirmationDialog confirmationDialog(tr("Confirm fee bump"), questionString);
    confirmationDialog.exec();
    QMessageBox::StandardButton retval = (QMessageBox::StandardButton)confirmationDialog.result();

    // cancel sign&broadcast if users doesn't want to bump the fee
    if (retval != QMessageBox::Yes) {
        return false;
    }

    WalletModel::UnlockContext ctx(requestUnlock());
<<<<<<< HEAD
    if (!ctx.isValid()) {
=======
    if(!ctx.isValid())
    {
>>>>>>> upstream/0.16
        return false;
    }

    // sign bumped transaction
    if (!feebumper::SignTransaction(wallet, mtx)) {
        QMessageBox::critical(0, tr("Fee bump error"), tr("Can't sign transaction."));
        return false;
    }
    // commit the bumped transaction
    uint256 txid;
    if (feebumper::CommitTransaction(wallet, hash, std::move(mtx), errors, txid) != feebumper::Result::OK) {
<<<<<<< HEAD
        QMessageBox::critical(0, tr("Fee bump error"), tr("Could not commit transaction") + "<br />(" + QString::fromStdString(errors[0]) + ")");
        return false;
=======
        QMessageBox::critical(0, tr("Fee bump error"), tr("Could not commit transaction") + "<br />(" +
            QString::fromStdString(errors[0])+")");
         return false;
>>>>>>> upstream/0.16
    }
    return true;
}

bool WalletModel::isWalletEnabled()
{
<<<<<<< HEAD
    return !gArgs.GetBoolArg("-disablewallet", DEFAULT_DISABLE_WALLET);
=======
   return !gArgs.GetBoolArg("-disablewallet", DEFAULT_DISABLE_WALLET);
>>>>>>> upstream/0.16
}

bool WalletModel::hdEnabled() const
{
    return wallet->IsHDEnabled();
}

OutputType WalletModel::getDefaultAddressType() const
{
    return g_address_type;
}

int WalletModel::getDefaultConfirmTarget() const
{
    return nTxConfirmTarget;
}
