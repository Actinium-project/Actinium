/********************************************************************************
** Form generated from reading UI file 'coincontroldialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COINCONTROLDIALOG_H
#define UI_COINCONTROLDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include "qt/coincontroltreewidget.h"

QT_BEGIN_NAMESPACE

class Ui_CoinControlDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayoutTop;
    QFormLayout *formLayoutCoinControl1;
    QLabel *labelCoinControlQuantityText;
    QLabel *labelCoinControlQuantity;
    QLabel *labelCoinControlBytesText;
    QLabel *labelCoinControlBytes;
    QFormLayout *formLayoutCoinControl2;
    QLabel *labelCoinControlAmountText;
    QLabel *labelCoinControlAmount;
    QLabel *labelCoinControlLowOutputText;
    QLabel *labelCoinControlLowOutput;
    QFormLayout *formLayoutCoinControl3;
    QLabel *labelCoinControlFeeText;
    QLabel *labelCoinControlFee;
    QFormLayout *formLayoutCoinControl4;
    QLabel *labelCoinControlAfterFeeText;
    QLabel *labelCoinControlAfterFee;
    QLabel *labelCoinControlChangeText;
    QLabel *labelCoinControlChange;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayoutPanel;
    QPushButton *pushButtonSelectAll;
    QRadioButton *radioTreeMode;
    QRadioButton *radioListMode;
    QLabel *labelLocked;
    QSpacerItem *horizontalSpacer;
    CoinControlTreeWidget *treeWidget;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CoinControlDialog)
    {
        if (CoinControlDialog->objectName().isEmpty())
            CoinControlDialog->setObjectName(QString::fromUtf8("CoinControlDialog"));
        CoinControlDialog->resize(1000, 500);
        verticalLayout = new QVBoxLayout(CoinControlDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayoutTop = new QHBoxLayout();
        horizontalLayoutTop->setObjectName(QString::fromUtf8("horizontalLayoutTop"));
        horizontalLayoutTop->setContentsMargins(-1, 0, -1, 10);
        formLayoutCoinControl1 = new QFormLayout();
        formLayoutCoinControl1->setObjectName(QString::fromUtf8("formLayoutCoinControl1"));
        formLayoutCoinControl1->setHorizontalSpacing(10);
        formLayoutCoinControl1->setVerticalSpacing(10);
        formLayoutCoinControl1->setContentsMargins(6, -1, 6, -1);
        labelCoinControlQuantityText = new QLabel(CoinControlDialog);
        labelCoinControlQuantityText->setObjectName(QString::fromUtf8("labelCoinControlQuantityText"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        labelCoinControlQuantityText->setFont(font);

        formLayoutCoinControl1->setWidget(0, QFormLayout::LabelRole, labelCoinControlQuantityText);

        labelCoinControlQuantity = new QLabel(CoinControlDialog);
        labelCoinControlQuantity->setObjectName(QString::fromUtf8("labelCoinControlQuantity"));
        labelCoinControlQuantity->setCursor(QCursor(Qt::IBeamCursor));
        labelCoinControlQuantity->setContextMenuPolicy(Qt::ActionsContextMenu);
        labelCoinControlQuantity->setText(QString::fromUtf8("0"));
        labelCoinControlQuantity->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayoutCoinControl1->setWidget(0, QFormLayout::FieldRole, labelCoinControlQuantity);

        labelCoinControlBytesText = new QLabel(CoinControlDialog);
        labelCoinControlBytesText->setObjectName(QString::fromUtf8("labelCoinControlBytesText"));
        labelCoinControlBytesText->setFont(font);

        formLayoutCoinControl1->setWidget(1, QFormLayout::LabelRole, labelCoinControlBytesText);

        labelCoinControlBytes = new QLabel(CoinControlDialog);
        labelCoinControlBytes->setObjectName(QString::fromUtf8("labelCoinControlBytes"));
        labelCoinControlBytes->setCursor(QCursor(Qt::IBeamCursor));
        labelCoinControlBytes->setContextMenuPolicy(Qt::ActionsContextMenu);
        labelCoinControlBytes->setText(QString::fromUtf8("0"));
        labelCoinControlBytes->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayoutCoinControl1->setWidget(1, QFormLayout::FieldRole, labelCoinControlBytes);


        horizontalLayoutTop->addLayout(formLayoutCoinControl1);

        formLayoutCoinControl2 = new QFormLayout();
        formLayoutCoinControl2->setObjectName(QString::fromUtf8("formLayoutCoinControl2"));
        formLayoutCoinControl2->setHorizontalSpacing(10);
        formLayoutCoinControl2->setVerticalSpacing(10);
        formLayoutCoinControl2->setContentsMargins(6, -1, 6, -1);
        labelCoinControlAmountText = new QLabel(CoinControlDialog);
        labelCoinControlAmountText->setObjectName(QString::fromUtf8("labelCoinControlAmountText"));
        labelCoinControlAmountText->setFont(font);

        formLayoutCoinControl2->setWidget(0, QFormLayout::LabelRole, labelCoinControlAmountText);

        labelCoinControlAmount = new QLabel(CoinControlDialog);
        labelCoinControlAmount->setObjectName(QString::fromUtf8("labelCoinControlAmount"));
        labelCoinControlAmount->setCursor(QCursor(Qt::IBeamCursor));
        labelCoinControlAmount->setContextMenuPolicy(Qt::ActionsContextMenu);
        labelCoinControlAmount->setText(QString::fromUtf8("0.00 ACM"));
        labelCoinControlAmount->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayoutCoinControl2->setWidget(0, QFormLayout::FieldRole, labelCoinControlAmount);

        labelCoinControlLowOutputText = new QLabel(CoinControlDialog);
        labelCoinControlLowOutputText->setObjectName(QString::fromUtf8("labelCoinControlLowOutputText"));
        labelCoinControlLowOutputText->setEnabled(false);
        labelCoinControlLowOutputText->setFont(font);

        formLayoutCoinControl2->setWidget(1, QFormLayout::LabelRole, labelCoinControlLowOutputText);

        labelCoinControlLowOutput = new QLabel(CoinControlDialog);
        labelCoinControlLowOutput->setObjectName(QString::fromUtf8("labelCoinControlLowOutput"));
        labelCoinControlLowOutput->setEnabled(false);
        labelCoinControlLowOutput->setCursor(QCursor(Qt::IBeamCursor));
        labelCoinControlLowOutput->setContextMenuPolicy(Qt::ActionsContextMenu);
        labelCoinControlLowOutput->setText(QString::fromUtf8("no"));
        labelCoinControlLowOutput->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayoutCoinControl2->setWidget(1, QFormLayout::FieldRole, labelCoinControlLowOutput);


        horizontalLayoutTop->addLayout(formLayoutCoinControl2);

        formLayoutCoinControl3 = new QFormLayout();
        formLayoutCoinControl3->setObjectName(QString::fromUtf8("formLayoutCoinControl3"));
        formLayoutCoinControl3->setHorizontalSpacing(10);
        formLayoutCoinControl3->setVerticalSpacing(10);
        formLayoutCoinControl3->setContentsMargins(6, -1, 6, -1);
        labelCoinControlFeeText = new QLabel(CoinControlDialog);
        labelCoinControlFeeText->setObjectName(QString::fromUtf8("labelCoinControlFeeText"));
        labelCoinControlFeeText->setFont(font);

        formLayoutCoinControl3->setWidget(0, QFormLayout::LabelRole, labelCoinControlFeeText);

        labelCoinControlFee = new QLabel(CoinControlDialog);
        labelCoinControlFee->setObjectName(QString::fromUtf8("labelCoinControlFee"));
        labelCoinControlFee->setCursor(QCursor(Qt::IBeamCursor));
        labelCoinControlFee->setContextMenuPolicy(Qt::ActionsContextMenu);
        labelCoinControlFee->setText(QString::fromUtf8("0.00 ACM"));
        labelCoinControlFee->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayoutCoinControl3->setWidget(0, QFormLayout::FieldRole, labelCoinControlFee);


        horizontalLayoutTop->addLayout(formLayoutCoinControl3);

        formLayoutCoinControl4 = new QFormLayout();
        formLayoutCoinControl4->setObjectName(QString::fromUtf8("formLayoutCoinControl4"));
        formLayoutCoinControl4->setHorizontalSpacing(10);
        formLayoutCoinControl4->setVerticalSpacing(10);
        formLayoutCoinControl4->setContentsMargins(6, -1, 6, -1);
        labelCoinControlAfterFeeText = new QLabel(CoinControlDialog);
        labelCoinControlAfterFeeText->setObjectName(QString::fromUtf8("labelCoinControlAfterFeeText"));
        labelCoinControlAfterFeeText->setFont(font);

        formLayoutCoinControl4->setWidget(0, QFormLayout::LabelRole, labelCoinControlAfterFeeText);

        labelCoinControlAfterFee = new QLabel(CoinControlDialog);
        labelCoinControlAfterFee->setObjectName(QString::fromUtf8("labelCoinControlAfterFee"));
        labelCoinControlAfterFee->setCursor(QCursor(Qt::IBeamCursor));
        labelCoinControlAfterFee->setContextMenuPolicy(Qt::ActionsContextMenu);
        labelCoinControlAfterFee->setText(QString::fromUtf8("0.00 ACM"));
        labelCoinControlAfterFee->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayoutCoinControl4->setWidget(0, QFormLayout::FieldRole, labelCoinControlAfterFee);

        labelCoinControlChangeText = new QLabel(CoinControlDialog);
        labelCoinControlChangeText->setObjectName(QString::fromUtf8("labelCoinControlChangeText"));
        labelCoinControlChangeText->setEnabled(false);
        labelCoinControlChangeText->setFont(font);

        formLayoutCoinControl4->setWidget(1, QFormLayout::LabelRole, labelCoinControlChangeText);

        labelCoinControlChange = new QLabel(CoinControlDialog);
        labelCoinControlChange->setObjectName(QString::fromUtf8("labelCoinControlChange"));
        labelCoinControlChange->setEnabled(false);
        labelCoinControlChange->setCursor(QCursor(Qt::IBeamCursor));
        labelCoinControlChange->setContextMenuPolicy(Qt::ActionsContextMenu);
        labelCoinControlChange->setText(QString::fromUtf8("0.00 ACM"));
        labelCoinControlChange->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayoutCoinControl4->setWidget(1, QFormLayout::FieldRole, labelCoinControlChange);


        horizontalLayoutTop->addLayout(formLayoutCoinControl4);


        verticalLayout->addLayout(horizontalLayoutTop);

        frame = new QFrame(CoinControlDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(0, 40));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Sunken);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayoutPanel = new QHBoxLayout();
        horizontalLayoutPanel->setSpacing(14);
        horizontalLayoutPanel->setObjectName(QString::fromUtf8("horizontalLayoutPanel"));
        pushButtonSelectAll = new QPushButton(frame);
        pushButtonSelectAll->setObjectName(QString::fromUtf8("pushButtonSelectAll"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButtonSelectAll->sizePolicy().hasHeightForWidth());
        pushButtonSelectAll->setSizePolicy(sizePolicy);
        pushButtonSelectAll->setAutoDefault(false);

        horizontalLayoutPanel->addWidget(pushButtonSelectAll);

        radioTreeMode = new QRadioButton(frame);
        radioTreeMode->setObjectName(QString::fromUtf8("radioTreeMode"));
        sizePolicy.setHeightForWidth(radioTreeMode->sizePolicy().hasHeightForWidth());
        radioTreeMode->setSizePolicy(sizePolicy);

        horizontalLayoutPanel->addWidget(radioTreeMode);

        radioListMode = new QRadioButton(frame);
        radioListMode->setObjectName(QString::fromUtf8("radioListMode"));
        sizePolicy.setHeightForWidth(radioListMode->sizePolicy().hasHeightForWidth());
        radioListMode->setSizePolicy(sizePolicy);
        radioListMode->setChecked(true);

        horizontalLayoutPanel->addWidget(radioListMode);

        labelLocked = new QLabel(frame);
        labelLocked->setObjectName(QString::fromUtf8("labelLocked"));
        labelLocked->setText(QString::fromUtf8("(1 locked)"));

        horizontalLayoutPanel->addWidget(labelLocked);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutPanel->addItem(horizontalSpacer);


        horizontalLayout->addLayout(horizontalLayoutPanel);


        verticalLayout->addWidget(frame);

        treeWidget = new CoinControlTreeWidget(CoinControlDialog);
        treeWidget->headerItem()->setText(0, QString());
        treeWidget->headerItem()->setText(6, QString());
        treeWidget->headerItem()->setText(7, QString());
        treeWidget->headerItem()->setText(8, QString());
        treeWidget->headerItem()->setText(9, QString());
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);
        treeWidget->setSortingEnabled(false);
        treeWidget->setColumnCount(10);
        treeWidget->header()->setProperty("showSortIndicator", QVariant(true));
        treeWidget->header()->setStretchLastSection(false);

        verticalLayout->addWidget(treeWidget);

        buttonBox = new QDialogButtonBox(CoinControlDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        sizePolicy.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(CoinControlDialog);

        QMetaObject::connectSlotsByName(CoinControlDialog);
    } // setupUi

    void retranslateUi(QDialog *CoinControlDialog)
    {
        CoinControlDialog->setWindowTitle(QApplication::translate("CoinControlDialog", "Coin Selection", nullptr));
        labelCoinControlQuantityText->setText(QApplication::translate("CoinControlDialog", "Quantity:", nullptr));
        labelCoinControlBytesText->setText(QApplication::translate("CoinControlDialog", "Bytes:", nullptr));
        labelCoinControlAmountText->setText(QApplication::translate("CoinControlDialog", "Amount:", nullptr));
        labelCoinControlLowOutputText->setText(QApplication::translate("CoinControlDialog", "Dust:", nullptr));
        labelCoinControlFeeText->setText(QApplication::translate("CoinControlDialog", "Fee:", nullptr));
        labelCoinControlAfterFeeText->setText(QApplication::translate("CoinControlDialog", "After Fee:", nullptr));
        labelCoinControlChangeText->setText(QApplication::translate("CoinControlDialog", "Change:", nullptr));
        pushButtonSelectAll->setText(QApplication::translate("CoinControlDialog", "(un)select all", nullptr));
        radioTreeMode->setText(QApplication::translate("CoinControlDialog", "Tree mode", nullptr));
        radioListMode->setText(QApplication::translate("CoinControlDialog", "List mode", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(5, QApplication::translate("CoinControlDialog", "Confirmations", nullptr));
        ___qtreewidgetitem->setText(4, QApplication::translate("CoinControlDialog", "Date", nullptr));
        ___qtreewidgetitem->setText(3, QApplication::translate("CoinControlDialog", "Received with address", nullptr));
        ___qtreewidgetitem->setText(2, QApplication::translate("CoinControlDialog", "Received with label", nullptr));
        ___qtreewidgetitem->setText(1, QApplication::translate("CoinControlDialog", "Amount", nullptr));
#ifndef QT_NO_TOOLTIP
        ___qtreewidgetitem->setToolTip(5, QApplication::translate("CoinControlDialog", "Confirmed", nullptr));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class CoinControlDialog: public Ui_CoinControlDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COINCONTROLDIALOG_H
