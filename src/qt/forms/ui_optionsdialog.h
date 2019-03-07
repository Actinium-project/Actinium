/********************************************************************************
** Form generated from reading UI file 'optionsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONSDIALOG_H
#define UI_OPTIONSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qt/qvalidatedlineedit.h"
#include "qt/qvaluecombobox.h"

QT_BEGIN_NAMESPACE

class Ui_OptionsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tabMain;
    QVBoxLayout *verticalLayout_Main;
    QCheckBox *bitcoinAtStartup;
    QSpacerItem *horizontalSpacer_0_Main;
    QHBoxLayout *horizontalLayout_Main_Prune;
    QCheckBox *prune;
    QSpinBox *pruneSize;
    QLabel *pruneSizeUnitLabel;
    QSpacerItem *horizontalSpacer_Main_Prune;
    QLabel *pruneWarning;
    QHBoxLayout *horizontalLayout_2_Main;
    QLabel *databaseCacheLabel;
    QSpinBox *databaseCache;
    QLabel *databaseCacheUnitLabel;
    QSpacerItem *horizontalSpacer_2_Main;
    QHBoxLayout *horizontalLayout_Main_VerifyLabel;
    QLabel *threadsScriptVerifLabel;
    QSpinBox *threadsScriptVerif;
    QSpacerItem *horizontalSpacer_Main_Threads;
    QSpacerItem *verticalSpacer_Main;
    QWidget *tabWallet;
    QVBoxLayout *verticalLayout_Wallet;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *coinControlFeatures;
    QCheckBox *spendZeroConfChange;
    QSpacerItem *verticalSpacer_Wallet;
    QWidget *tabNetwork;
    QVBoxLayout *verticalLayout_Network;
    QCheckBox *mapPortUpnp;
    QCheckBox *allowIncoming;
    QCheckBox *connectSocks;
    QHBoxLayout *horizontalLayout_1_Network;
    QLabel *proxyIpLabel;
    QValidatedLineEdit *proxyIp;
    QLabel *proxyPortLabel;
    QLineEdit *proxyPort;
    QSpacerItem *horizontalSpacer_1_Network;
    QHBoxLayout *horizontalLayout_2_Network;
    QLabel *proxyActiveNets;
    QCheckBox *proxyReachIPv4;
    QLabel *proxyReachIPv4Label;
    QCheckBox *proxyReachIPv6;
    QLabel *proxyReachIPv6Label;
    QCheckBox *proxyReachTor;
    QLabel *proxyReachTorLabel;
    QSpacerItem *horizontalSpacer_2_Network;
    QCheckBox *connectSocksTor;
    QHBoxLayout *horizontalLayout_3_Network;
    QLabel *proxyIpTorLabel;
    QValidatedLineEdit *proxyIpTor;
    QLabel *proxyPortTorLabel;
    QLineEdit *proxyPortTor;
    QSpacerItem *horizontalSpacer_4_Network;
    QSpacerItem *verticalSpacer_Network;
    QWidget *tabWindow;
    QVBoxLayout *verticalLayout_Window;
    QCheckBox *hideTrayIcon;
    QCheckBox *minimizeToTray;
    QCheckBox *minimizeOnClose;
    QSpacerItem *verticalSpacer_Window;
    QWidget *tabDisplay;
    QVBoxLayout *verticalLayout_Display;
    QHBoxLayout *horizontalLayout_1_Display;
    QLabel *langLabel;
    QValueComboBox *lang;
    QHBoxLayout *horizontalLayout_2_Display;
    QLabel *unitLabel;
    QValueComboBox *unit;
    QHBoxLayout *horizontalLayout_3_Display;
    QLabel *thirdPartyTxUrlsLabel;
    QLineEdit *thirdPartyTxUrls;
    QSpacerItem *verticalSpacer_Display;
    QFrame *frame;
    QVBoxLayout *verticalLayout_Bottom;
    QHBoxLayout *horizontalLayout_Bottom;
    QLabel *overriddenByCommandLineInfoLabel;
    QSpacerItem *horizontalSpacer_Bottom;
    QLabel *overriddenByCommandLineLabel;
    QHBoxLayout *horizontalLayout_Buttons;
    QVBoxLayout *verticalLayout_Buttons;
    QPushButton *openBitcoinConfButton;
    QPushButton *resetButton;
    QSpacerItem *horizontalSpacer_1;
    QLabel *statusLabel;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *OptionsDialog)
    {
        if (OptionsDialog->objectName().isEmpty())
            OptionsDialog->setObjectName(QString::fromUtf8("OptionsDialog"));
        OptionsDialog->resize(560, 440);
        OptionsDialog->setModal(true);
        verticalLayout = new QVBoxLayout(OptionsDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(OptionsDialog);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabMain = new QWidget();
        tabMain->setObjectName(QString::fromUtf8("tabMain"));
        verticalLayout_Main = new QVBoxLayout(tabMain);
        verticalLayout_Main->setObjectName(QString::fromUtf8("verticalLayout_Main"));
        bitcoinAtStartup = new QCheckBox(tabMain);
        bitcoinAtStartup->setObjectName(QString::fromUtf8("bitcoinAtStartup"));

        verticalLayout_Main->addWidget(bitcoinAtStartup);

        horizontalSpacer_0_Main = new QSpacerItem(40, 5, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_Main->addItem(horizontalSpacer_0_Main);

        horizontalLayout_Main_Prune = new QHBoxLayout();
        horizontalLayout_Main_Prune->setObjectName(QString::fromUtf8("horizontalLayout_Main_Prune"));
        prune = new QCheckBox(tabMain);
        prune->setObjectName(QString::fromUtf8("prune"));

        horizontalLayout_Main_Prune->addWidget(prune);

        pruneSize = new QSpinBox(tabMain);
        pruneSize->setObjectName(QString::fromUtf8("pruneSize"));

        horizontalLayout_Main_Prune->addWidget(pruneSize);

        pruneSizeUnitLabel = new QLabel(tabMain);
        pruneSizeUnitLabel->setObjectName(QString::fromUtf8("pruneSizeUnitLabel"));
        pruneSizeUnitLabel->setTextFormat(Qt::PlainText);

        horizontalLayout_Main_Prune->addWidget(pruneSizeUnitLabel);

        horizontalSpacer_Main_Prune = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Main_Prune->addItem(horizontalSpacer_Main_Prune);


        verticalLayout_Main->addLayout(horizontalLayout_Main_Prune);

        pruneWarning = new QLabel(tabMain);
        pruneWarning->setObjectName(QString::fromUtf8("pruneWarning"));
        pruneWarning->setTextFormat(Qt::PlainText);

        verticalLayout_Main->addWidget(pruneWarning);

        horizontalLayout_2_Main = new QHBoxLayout();
        horizontalLayout_2_Main->setObjectName(QString::fromUtf8("horizontalLayout_2_Main"));
        databaseCacheLabel = new QLabel(tabMain);
        databaseCacheLabel->setObjectName(QString::fromUtf8("databaseCacheLabel"));
        databaseCacheLabel->setTextFormat(Qt::PlainText);

        horizontalLayout_2_Main->addWidget(databaseCacheLabel);

        databaseCache = new QSpinBox(tabMain);
        databaseCache->setObjectName(QString::fromUtf8("databaseCache"));

        horizontalLayout_2_Main->addWidget(databaseCache);

        databaseCacheUnitLabel = new QLabel(tabMain);
        databaseCacheUnitLabel->setObjectName(QString::fromUtf8("databaseCacheUnitLabel"));
        databaseCacheUnitLabel->setTextFormat(Qt::PlainText);

        horizontalLayout_2_Main->addWidget(databaseCacheUnitLabel);

        horizontalSpacer_2_Main = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2_Main->addItem(horizontalSpacer_2_Main);


        verticalLayout_Main->addLayout(horizontalLayout_2_Main);

        horizontalLayout_Main_VerifyLabel = new QHBoxLayout();
        horizontalLayout_Main_VerifyLabel->setObjectName(QString::fromUtf8("horizontalLayout_Main_VerifyLabel"));
        threadsScriptVerifLabel = new QLabel(tabMain);
        threadsScriptVerifLabel->setObjectName(QString::fromUtf8("threadsScriptVerifLabel"));
        threadsScriptVerifLabel->setTextFormat(Qt::PlainText);

        horizontalLayout_Main_VerifyLabel->addWidget(threadsScriptVerifLabel);

        threadsScriptVerif = new QSpinBox(tabMain);
        threadsScriptVerif->setObjectName(QString::fromUtf8("threadsScriptVerif"));

        horizontalLayout_Main_VerifyLabel->addWidget(threadsScriptVerif);

        horizontalSpacer_Main_Threads = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Main_VerifyLabel->addItem(horizontalSpacer_Main_Threads);


        verticalLayout_Main->addLayout(horizontalLayout_Main_VerifyLabel);

        verticalSpacer_Main = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_Main->addItem(verticalSpacer_Main);

        tabWidget->addTab(tabMain, QString());
        tabWallet = new QWidget();
        tabWallet->setObjectName(QString::fromUtf8("tabWallet"));
        verticalLayout_Wallet = new QVBoxLayout(tabWallet);
        verticalLayout_Wallet->setObjectName(QString::fromUtf8("verticalLayout_Wallet"));
        groupBox = new QGroupBox(tabWallet);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        coinControlFeatures = new QCheckBox(groupBox);
        coinControlFeatures->setObjectName(QString::fromUtf8("coinControlFeatures"));

        verticalLayout_2->addWidget(coinControlFeatures);

        spendZeroConfChange = new QCheckBox(groupBox);
        spendZeroConfChange->setObjectName(QString::fromUtf8("spendZeroConfChange"));

        verticalLayout_2->addWidget(spendZeroConfChange);


        verticalLayout_Wallet->addWidget(groupBox);

        verticalSpacer_Wallet = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_Wallet->addItem(verticalSpacer_Wallet);

        tabWidget->addTab(tabWallet, QString());
        tabNetwork = new QWidget();
        tabNetwork->setObjectName(QString::fromUtf8("tabNetwork"));
        verticalLayout_Network = new QVBoxLayout(tabNetwork);
        verticalLayout_Network->setObjectName(QString::fromUtf8("verticalLayout_Network"));
        mapPortUpnp = new QCheckBox(tabNetwork);
        mapPortUpnp->setObjectName(QString::fromUtf8("mapPortUpnp"));

        verticalLayout_Network->addWidget(mapPortUpnp);

        allowIncoming = new QCheckBox(tabNetwork);
        allowIncoming->setObjectName(QString::fromUtf8("allowIncoming"));

        verticalLayout_Network->addWidget(allowIncoming);

        connectSocks = new QCheckBox(tabNetwork);
        connectSocks->setObjectName(QString::fromUtf8("connectSocks"));

        verticalLayout_Network->addWidget(connectSocks);

        horizontalLayout_1_Network = new QHBoxLayout();
        horizontalLayout_1_Network->setObjectName(QString::fromUtf8("horizontalLayout_1_Network"));
        proxyIpLabel = new QLabel(tabNetwork);
        proxyIpLabel->setObjectName(QString::fromUtf8("proxyIpLabel"));
        proxyIpLabel->setTextFormat(Qt::PlainText);

        horizontalLayout_1_Network->addWidget(proxyIpLabel);

        proxyIp = new QValidatedLineEdit(tabNetwork);
        proxyIp->setObjectName(QString::fromUtf8("proxyIp"));
        proxyIp->setMinimumSize(QSize(140, 0));
        proxyIp->setMaximumSize(QSize(140, 16777215));

        horizontalLayout_1_Network->addWidget(proxyIp);

        proxyPortLabel = new QLabel(tabNetwork);
        proxyPortLabel->setObjectName(QString::fromUtf8("proxyPortLabel"));
        proxyPortLabel->setTextFormat(Qt::PlainText);

        horizontalLayout_1_Network->addWidget(proxyPortLabel);

        proxyPort = new QLineEdit(tabNetwork);
        proxyPort->setObjectName(QString::fromUtf8("proxyPort"));
        proxyPort->setMinimumSize(QSize(55, 0));
        proxyPort->setMaximumSize(QSize(55, 16777215));

        horizontalLayout_1_Network->addWidget(proxyPort);

        horizontalSpacer_1_Network = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_1_Network->addItem(horizontalSpacer_1_Network);


        verticalLayout_Network->addLayout(horizontalLayout_1_Network);

        horizontalLayout_2_Network = new QHBoxLayout();
        horizontalLayout_2_Network->setObjectName(QString::fromUtf8("horizontalLayout_2_Network"));
        proxyActiveNets = new QLabel(tabNetwork);
        proxyActiveNets->setObjectName(QString::fromUtf8("proxyActiveNets"));
        proxyActiveNets->setTextFormat(Qt::PlainText);

        horizontalLayout_2_Network->addWidget(proxyActiveNets);

        proxyReachIPv4 = new QCheckBox(tabNetwork);
        proxyReachIPv4->setObjectName(QString::fromUtf8("proxyReachIPv4"));
        proxyReachIPv4->setEnabled(false);

        horizontalLayout_2_Network->addWidget(proxyReachIPv4);

        proxyReachIPv4Label = new QLabel(tabNetwork);
        proxyReachIPv4Label->setObjectName(QString::fromUtf8("proxyReachIPv4Label"));
        proxyReachIPv4Label->setTextFormat(Qt::PlainText);

        horizontalLayout_2_Network->addWidget(proxyReachIPv4Label);

        proxyReachIPv6 = new QCheckBox(tabNetwork);
        proxyReachIPv6->setObjectName(QString::fromUtf8("proxyReachIPv6"));
        proxyReachIPv6->setEnabled(false);

        horizontalLayout_2_Network->addWidget(proxyReachIPv6);

        proxyReachIPv6Label = new QLabel(tabNetwork);
        proxyReachIPv6Label->setObjectName(QString::fromUtf8("proxyReachIPv6Label"));
        proxyReachIPv6Label->setTextFormat(Qt::PlainText);

        horizontalLayout_2_Network->addWidget(proxyReachIPv6Label);

        proxyReachTor = new QCheckBox(tabNetwork);
        proxyReachTor->setObjectName(QString::fromUtf8("proxyReachTor"));
        proxyReachTor->setEnabled(false);

        horizontalLayout_2_Network->addWidget(proxyReachTor);

        proxyReachTorLabel = new QLabel(tabNetwork);
        proxyReachTorLabel->setObjectName(QString::fromUtf8("proxyReachTorLabel"));
        proxyReachTorLabel->setTextFormat(Qt::PlainText);

        horizontalLayout_2_Network->addWidget(proxyReachTorLabel);

        horizontalSpacer_2_Network = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2_Network->addItem(horizontalSpacer_2_Network);


        verticalLayout_Network->addLayout(horizontalLayout_2_Network);

        connectSocksTor = new QCheckBox(tabNetwork);
        connectSocksTor->setObjectName(QString::fromUtf8("connectSocksTor"));

        verticalLayout_Network->addWidget(connectSocksTor);

        horizontalLayout_3_Network = new QHBoxLayout();
        horizontalLayout_3_Network->setObjectName(QString::fromUtf8("horizontalLayout_3_Network"));
        proxyIpTorLabel = new QLabel(tabNetwork);
        proxyIpTorLabel->setObjectName(QString::fromUtf8("proxyIpTorLabel"));
        proxyIpTorLabel->setTextFormat(Qt::PlainText);

        horizontalLayout_3_Network->addWidget(proxyIpTorLabel);

        proxyIpTor = new QValidatedLineEdit(tabNetwork);
        proxyIpTor->setObjectName(QString::fromUtf8("proxyIpTor"));
        proxyIpTor->setMinimumSize(QSize(140, 0));
        proxyIpTor->setMaximumSize(QSize(140, 16777215));

        horizontalLayout_3_Network->addWidget(proxyIpTor);

        proxyPortTorLabel = new QLabel(tabNetwork);
        proxyPortTorLabel->setObjectName(QString::fromUtf8("proxyPortTorLabel"));
        proxyPortTorLabel->setTextFormat(Qt::PlainText);

        horizontalLayout_3_Network->addWidget(proxyPortTorLabel);

        proxyPortTor = new QLineEdit(tabNetwork);
        proxyPortTor->setObjectName(QString::fromUtf8("proxyPortTor"));
        proxyPortTor->setMinimumSize(QSize(55, 0));
        proxyPortTor->setMaximumSize(QSize(55, 16777215));

        horizontalLayout_3_Network->addWidget(proxyPortTor);

        horizontalSpacer_4_Network = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3_Network->addItem(horizontalSpacer_4_Network);


        verticalLayout_Network->addLayout(horizontalLayout_3_Network);

        verticalSpacer_Network = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_Network->addItem(verticalSpacer_Network);

        tabWidget->addTab(tabNetwork, QString());
        tabWindow = new QWidget();
        tabWindow->setObjectName(QString::fromUtf8("tabWindow"));
        verticalLayout_Window = new QVBoxLayout(tabWindow);
        verticalLayout_Window->setObjectName(QString::fromUtf8("verticalLayout_Window"));
        hideTrayIcon = new QCheckBox(tabWindow);
        hideTrayIcon->setObjectName(QString::fromUtf8("hideTrayIcon"));

        verticalLayout_Window->addWidget(hideTrayIcon);

        minimizeToTray = new QCheckBox(tabWindow);
        minimizeToTray->setObjectName(QString::fromUtf8("minimizeToTray"));

        verticalLayout_Window->addWidget(minimizeToTray);

        minimizeOnClose = new QCheckBox(tabWindow);
        minimizeOnClose->setObjectName(QString::fromUtf8("minimizeOnClose"));

        verticalLayout_Window->addWidget(minimizeOnClose);

        verticalSpacer_Window = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_Window->addItem(verticalSpacer_Window);

        tabWidget->addTab(tabWindow, QString());
        tabDisplay = new QWidget();
        tabDisplay->setObjectName(QString::fromUtf8("tabDisplay"));
        verticalLayout_Display = new QVBoxLayout(tabDisplay);
        verticalLayout_Display->setObjectName(QString::fromUtf8("verticalLayout_Display"));
        horizontalLayout_1_Display = new QHBoxLayout();
        horizontalLayout_1_Display->setObjectName(QString::fromUtf8("horizontalLayout_1_Display"));
        langLabel = new QLabel(tabDisplay);
        langLabel->setObjectName(QString::fromUtf8("langLabel"));
        langLabel->setTextFormat(Qt::PlainText);

        horizontalLayout_1_Display->addWidget(langLabel);

        lang = new QValueComboBox(tabDisplay);
        lang->setObjectName(QString::fromUtf8("lang"));

        horizontalLayout_1_Display->addWidget(lang);


        verticalLayout_Display->addLayout(horizontalLayout_1_Display);

        horizontalLayout_2_Display = new QHBoxLayout();
        horizontalLayout_2_Display->setObjectName(QString::fromUtf8("horizontalLayout_2_Display"));
        unitLabel = new QLabel(tabDisplay);
        unitLabel->setObjectName(QString::fromUtf8("unitLabel"));
        unitLabel->setTextFormat(Qt::PlainText);

        horizontalLayout_2_Display->addWidget(unitLabel);

        unit = new QValueComboBox(tabDisplay);
        unit->setObjectName(QString::fromUtf8("unit"));

        horizontalLayout_2_Display->addWidget(unit);


        verticalLayout_Display->addLayout(horizontalLayout_2_Display);

        horizontalLayout_3_Display = new QHBoxLayout();
        horizontalLayout_3_Display->setObjectName(QString::fromUtf8("horizontalLayout_3_Display"));
        thirdPartyTxUrlsLabel = new QLabel(tabDisplay);
        thirdPartyTxUrlsLabel->setObjectName(QString::fromUtf8("thirdPartyTxUrlsLabel"));

        horizontalLayout_3_Display->addWidget(thirdPartyTxUrlsLabel);

        thirdPartyTxUrls = new QLineEdit(tabDisplay);
        thirdPartyTxUrls->setObjectName(QString::fromUtf8("thirdPartyTxUrls"));

        horizontalLayout_3_Display->addWidget(thirdPartyTxUrls);


        verticalLayout_Display->addLayout(horizontalLayout_3_Display);

        verticalSpacer_Display = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_Display->addItem(verticalSpacer_Display);

        tabWidget->addTab(tabDisplay, QString());

        verticalLayout->addWidget(tabWidget);

        frame = new QFrame(OptionsDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        verticalLayout_Bottom = new QVBoxLayout(frame);
        verticalLayout_Bottom->setObjectName(QString::fromUtf8("verticalLayout_Bottom"));
        horizontalLayout_Bottom = new QHBoxLayout();
        horizontalLayout_Bottom->setObjectName(QString::fromUtf8("horizontalLayout_Bottom"));
        overriddenByCommandLineInfoLabel = new QLabel(frame);
        overriddenByCommandLineInfoLabel->setObjectName(QString::fromUtf8("overriddenByCommandLineInfoLabel"));
        overriddenByCommandLineInfoLabel->setTextFormat(Qt::PlainText);

        horizontalLayout_Bottom->addWidget(overriddenByCommandLineInfoLabel);

        horizontalSpacer_Bottom = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Bottom->addItem(horizontalSpacer_Bottom);


        verticalLayout_Bottom->addLayout(horizontalLayout_Bottom);

        overriddenByCommandLineLabel = new QLabel(frame);
        overriddenByCommandLineLabel->setObjectName(QString::fromUtf8("overriddenByCommandLineLabel"));
        overriddenByCommandLineLabel->setTextFormat(Qt::PlainText);
        overriddenByCommandLineLabel->setWordWrap(true);

        verticalLayout_Bottom->addWidget(overriddenByCommandLineLabel);


        verticalLayout->addWidget(frame);

        horizontalLayout_Buttons = new QHBoxLayout();
        horizontalLayout_Buttons->setObjectName(QString::fromUtf8("horizontalLayout_Buttons"));
        verticalLayout_Buttons = new QVBoxLayout();
        verticalLayout_Buttons->setObjectName(QString::fromUtf8("verticalLayout_Buttons"));
        openBitcoinConfButton = new QPushButton(OptionsDialog);
        openBitcoinConfButton->setObjectName(QString::fromUtf8("openBitcoinConfButton"));
        openBitcoinConfButton->setAutoDefault(false);

        verticalLayout_Buttons->addWidget(openBitcoinConfButton);

        resetButton = new QPushButton(OptionsDialog);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));
        resetButton->setAutoDefault(false);

        verticalLayout_Buttons->addWidget(resetButton);


        horizontalLayout_Buttons->addLayout(verticalLayout_Buttons);

        horizontalSpacer_1 = new QSpacerItem(40, 48, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Buttons->addItem(horizontalSpacer_1);

        statusLabel = new QLabel(OptionsDialog);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        statusLabel->setMinimumSize(QSize(200, 0));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        statusLabel->setFont(font);
        statusLabel->setTextFormat(Qt::PlainText);
        statusLabel->setWordWrap(true);

        horizontalLayout_Buttons->addWidget(statusLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 48, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Buttons->addItem(horizontalSpacer_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        okButton = new QPushButton(OptionsDialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setAutoDefault(false);

        horizontalLayout->addWidget(okButton);

        cancelButton = new QPushButton(OptionsDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setAutoDefault(false);

        horizontalLayout->addWidget(cancelButton);


        verticalLayout_4->addLayout(horizontalLayout);


        horizontalLayout_Buttons->addLayout(verticalLayout_4);


        verticalLayout->addLayout(horizontalLayout_Buttons);

#ifndef QT_NO_SHORTCUT
        databaseCacheLabel->setBuddy(databaseCache);
        threadsScriptVerifLabel->setBuddy(threadsScriptVerif);
        proxyIpLabel->setBuddy(proxyIp);
        proxyPortLabel->setBuddy(proxyPort);
        proxyIpTorLabel->setBuddy(proxyIpTor);
        proxyPortTorLabel->setBuddy(proxyPortTor);
        langLabel->setBuddy(lang);
        unitLabel->setBuddy(unit);
        thirdPartyTxUrlsLabel->setBuddy(thirdPartyTxUrls);
#endif // QT_NO_SHORTCUT

        retranslateUi(OptionsDialog);

        tabWidget->setCurrentIndex(0);
        okButton->setDefault(true);


        QMetaObject::connectSlotsByName(OptionsDialog);
    } // setupUi

    void retranslateUi(QDialog *OptionsDialog)
    {
        OptionsDialog->setWindowTitle(QApplication::translate("OptionsDialog", "Options", nullptr));
#ifndef QT_NO_TOOLTIP
        bitcoinAtStartup->setToolTip(QApplication::translate("OptionsDialog", "Automatically start %1 after logging in to the system.", nullptr));
#endif // QT_NO_TOOLTIP
        bitcoinAtStartup->setText(QApplication::translate("OptionsDialog", "&Start %1 on system login", nullptr));
#ifndef QT_NO_TOOLTIP
        prune->setToolTip(QApplication::translate("OptionsDialog", "Disables some advanced features but all blocks will still be fully validated. Reverting this setting requires re-downloading the entire blockchain. Actual disk usage may be somewhat higher.", nullptr));
#endif // QT_NO_TOOLTIP
        prune->setText(QApplication::translate("OptionsDialog", "Prune &block storage to", nullptr));
        pruneSizeUnitLabel->setText(QApplication::translate("OptionsDialog", "GB", nullptr));
        pruneWarning->setText(QApplication::translate("OptionsDialog", "Reverting this setting requires re-downloading the entire blockchain.", nullptr));
        databaseCacheLabel->setText(QApplication::translate("OptionsDialog", "Size of &database cache", nullptr));
        databaseCacheUnitLabel->setText(QApplication::translate("OptionsDialog", "MB", nullptr));
        threadsScriptVerifLabel->setText(QApplication::translate("OptionsDialog", "Number of script &verification threads", nullptr));
#ifndef QT_NO_TOOLTIP
        threadsScriptVerif->setToolTip(QApplication::translate("OptionsDialog", "(0 = auto, <0 = leave that many cores free)", nullptr));
#endif // QT_NO_TOOLTIP
        tabWidget->setTabText(tabWidget->indexOf(tabMain), QApplication::translate("OptionsDialog", "&Main", nullptr));
        groupBox->setTitle(QApplication::translate("OptionsDialog", "Expert", nullptr));
#ifndef QT_NO_TOOLTIP
        coinControlFeatures->setToolTip(QApplication::translate("OptionsDialog", "Whether to show coin control features or not.", nullptr));
#endif // QT_NO_TOOLTIP
        coinControlFeatures->setText(QApplication::translate("OptionsDialog", "Enable coin &control features", nullptr));
#ifndef QT_NO_TOOLTIP
        spendZeroConfChange->setToolTip(QApplication::translate("OptionsDialog", "If you disable the spending of unconfirmed change, the change from a transaction cannot be used until that transaction has at least one confirmation. This also affects how your balance is computed.", nullptr));
#endif // QT_NO_TOOLTIP
        spendZeroConfChange->setText(QApplication::translate("OptionsDialog", "&Spend unconfirmed change", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabWallet), QApplication::translate("OptionsDialog", "W&allet", nullptr));
#ifndef QT_NO_TOOLTIP
        mapPortUpnp->setToolTip(QApplication::translate("OptionsDialog", "Automatically open the Actinium client port on the router. This only works when your router supports UPnP and it is enabled.", nullptr));
#endif // QT_NO_TOOLTIP
        mapPortUpnp->setText(QApplication::translate("OptionsDialog", "Map port using &UPnP", nullptr));
#ifndef QT_NO_TOOLTIP
        allowIncoming->setToolTip(QApplication::translate("OptionsDialog", "Accept connections from outside.", nullptr));
#endif // QT_NO_TOOLTIP
        allowIncoming->setText(QApplication::translate("OptionsDialog", "Allow incomin&g connections", nullptr));
#ifndef QT_NO_TOOLTIP
        connectSocks->setToolTip(QApplication::translate("OptionsDialog", "Connect to the Actinium network through a SOCKS5 proxy.", nullptr));
#endif // QT_NO_TOOLTIP
        connectSocks->setText(QApplication::translate("OptionsDialog", "&Connect through SOCKS5 proxy (default proxy):", nullptr));
        proxyIpLabel->setText(QApplication::translate("OptionsDialog", "Proxy &IP:", nullptr));
#ifndef QT_NO_TOOLTIP
        proxyIp->setToolTip(QApplication::translate("OptionsDialog", "IP address of the proxy (e.g. IPv4: 127.0.0.1 / IPv6: ::1)", nullptr));
#endif // QT_NO_TOOLTIP
        proxyPortLabel->setText(QApplication::translate("OptionsDialog", "&Port:", nullptr));
#ifndef QT_NO_TOOLTIP
        proxyPort->setToolTip(QApplication::translate("OptionsDialog", "Port of the proxy (e.g. 9050)", nullptr));
#endif // QT_NO_TOOLTIP
        proxyActiveNets->setText(QApplication::translate("OptionsDialog", "Used for reaching peers via:", nullptr));
#ifndef QT_NO_TOOLTIP
        proxyReachIPv4->setToolTip(QApplication::translate("OptionsDialog", "Shows if the supplied default SOCKS5 proxy is used to reach peers via this network type.", nullptr));
#endif // QT_NO_TOOLTIP
        proxyReachIPv4->setText(QString());
        proxyReachIPv4Label->setText(QApplication::translate("OptionsDialog", "IPv4", nullptr));
#ifndef QT_NO_TOOLTIP
        proxyReachIPv6->setToolTip(QApplication::translate("OptionsDialog", "Shows if the supplied default SOCKS5 proxy is used to reach peers via this network type.", nullptr));
#endif // QT_NO_TOOLTIP
        proxyReachIPv6->setText(QString());
        proxyReachIPv6Label->setText(QApplication::translate("OptionsDialog", "IPv6", nullptr));
#ifndef QT_NO_TOOLTIP
        proxyReachTor->setToolTip(QApplication::translate("OptionsDialog", "Shows if the supplied default SOCKS5 proxy is used to reach peers via this network type.", nullptr));
#endif // QT_NO_TOOLTIP
        proxyReachTor->setText(QString());
        proxyReachTorLabel->setText(QApplication::translate("OptionsDialog", "Tor", nullptr));
#ifndef QT_NO_TOOLTIP
        connectSocksTor->setToolTip(QApplication::translate("OptionsDialog", "Connect to the Actinium network through a separate SOCKS5 proxy for Tor hidden services.", nullptr));
#endif // QT_NO_TOOLTIP
        connectSocksTor->setText(QApplication::translate("OptionsDialog", "Use separate SOCKS5 proxy to reach peers via Tor hidden services:", nullptr));
        proxyIpTorLabel->setText(QApplication::translate("OptionsDialog", "Proxy &IP:", nullptr));
#ifndef QT_NO_TOOLTIP
        proxyIpTor->setToolTip(QApplication::translate("OptionsDialog", "IP address of the proxy (e.g. IPv4: 127.0.0.1 / IPv6: ::1)", nullptr));
#endif // QT_NO_TOOLTIP
        proxyPortTorLabel->setText(QApplication::translate("OptionsDialog", "&Port:", nullptr));
#ifndef QT_NO_TOOLTIP
        proxyPortTor->setToolTip(QApplication::translate("OptionsDialog", "Port of the proxy (e.g. 9050)", nullptr));
#endif // QT_NO_TOOLTIP
        tabWidget->setTabText(tabWidget->indexOf(tabNetwork), QApplication::translate("OptionsDialog", "&Network", nullptr));
#ifndef QT_NO_TOOLTIP
        hideTrayIcon->setToolTip(QApplication::translate("OptionsDialog", "Hide the icon from the system tray.", nullptr));
#endif // QT_NO_TOOLTIP
        hideTrayIcon->setText(QApplication::translate("OptionsDialog", "&Hide tray icon", nullptr));
#ifndef QT_NO_TOOLTIP
        minimizeToTray->setToolTip(QApplication::translate("OptionsDialog", "Show only a tray icon after minimizing the window.", nullptr));
#endif // QT_NO_TOOLTIP
        minimizeToTray->setText(QApplication::translate("OptionsDialog", "&Minimize to the tray instead of the taskbar", nullptr));
#ifndef QT_NO_TOOLTIP
        minimizeOnClose->setToolTip(QApplication::translate("OptionsDialog", "Minimize instead of exit the application when the window is closed. When this option is enabled, the application will be closed only after selecting Exit in the menu.", nullptr));
#endif // QT_NO_TOOLTIP
        minimizeOnClose->setText(QApplication::translate("OptionsDialog", "M&inimize on close", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabWindow), QApplication::translate("OptionsDialog", "&Window", nullptr));
        langLabel->setText(QApplication::translate("OptionsDialog", "User Interface &language:", nullptr));
#ifndef QT_NO_TOOLTIP
        lang->setToolTip(QApplication::translate("OptionsDialog", "The user interface language can be set here. This setting will take effect after restarting %1.", nullptr));
#endif // QT_NO_TOOLTIP
        unitLabel->setText(QApplication::translate("OptionsDialog", "&Unit to show amounts in:", nullptr));
#ifndef QT_NO_TOOLTIP
        unit->setToolTip(QApplication::translate("OptionsDialog", "Choose the default subdivision unit to show in the interface and when sending coins.", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        thirdPartyTxUrlsLabel->setToolTip(QApplication::translate("OptionsDialog", "Third party URLs (e.g. a block explorer) that appear in the transactions tab as context menu items. %s in the URL is replaced by transaction hash. Multiple URLs are separated by vertical bar |.", nullptr));
#endif // QT_NO_TOOLTIP
        thirdPartyTxUrlsLabel->setText(QApplication::translate("OptionsDialog", "&Third party transaction URLs", nullptr));
#ifndef QT_NO_TOOLTIP
        thirdPartyTxUrls->setToolTip(QApplication::translate("OptionsDialog", "Third party URLs (e.g. a block explorer) that appear in the transactions tab as context menu items. %s in the URL is replaced by transaction hash. Multiple URLs are separated by vertical bar |.", nullptr));
#endif // QT_NO_TOOLTIP
        tabWidget->setTabText(tabWidget->indexOf(tabDisplay), QApplication::translate("OptionsDialog", "&Display", nullptr));
        overriddenByCommandLineInfoLabel->setText(QApplication::translate("OptionsDialog", "Active command-line options that override above options:", nullptr));
        overriddenByCommandLineLabel->setText(QString());
#ifndef QT_NO_TOOLTIP
        openBitcoinConfButton->setToolTip(QApplication::translate("OptionsDialog", "Open the %1 configuration file from the working directory.", nullptr));
#endif // QT_NO_TOOLTIP
        openBitcoinConfButton->setText(QApplication::translate("OptionsDialog", "Open Configuration File", nullptr));
#ifndef QT_NO_TOOLTIP
        resetButton->setToolTip(QApplication::translate("OptionsDialog", "Reset all client options to default.", nullptr));
#endif // QT_NO_TOOLTIP
        resetButton->setText(QApplication::translate("OptionsDialog", "&Reset Options", nullptr));
        statusLabel->setText(QString());
        okButton->setText(QApplication::translate("OptionsDialog", "&OK", nullptr));
        cancelButton->setText(QApplication::translate("OptionsDialog", "&Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OptionsDialog: public Ui_OptionsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONSDIALOG_H
