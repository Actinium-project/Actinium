/********************************************************************************
** Form generated from reading UI file 'addressbookpage.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDRESSBOOKPAGE_H
#define UI_ADDRESSBOOKPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddressBookPage
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *labelExplanation;
    QLineEdit *searchLineEdit;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QPushButton *newAddress;
    QPushButton *copyAddress;
    QPushButton *deleteAddress;
    QSpacerItem *horizontalSpacer;
    QPushButton *exportButton;

    void setupUi(QWidget *AddressBookPage)
    {
        if (AddressBookPage->objectName().isEmpty())
            AddressBookPage->setObjectName(QStringLiteral("AddressBookPage"));
        AddressBookPage->resize(760, 380);
        verticalLayout = new QVBoxLayout(AddressBookPage);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        labelExplanation = new QLabel(AddressBookPage);
        labelExplanation->setObjectName(QStringLiteral("labelExplanation"));
        labelExplanation->setTextFormat(Qt::PlainText);
        labelExplanation->setWordWrap(true);

        verticalLayout->addWidget(labelExplanation);

        searchLineEdit = new QLineEdit(AddressBookPage);
        searchLineEdit->setObjectName(QStringLiteral("searchLineEdit"));

        verticalLayout->addWidget(searchLineEdit);

        tableView = new QTableView(AddressBookPage);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setContextMenuPolicy(Qt::CustomContextMenu);
        tableView->setTabKeyNavigation(false);
        tableView->setAlternatingRowColors(true);
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setSortingEnabled(true);
        tableView->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tableView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        newAddress = new QPushButton(AddressBookPage);
        newAddress->setObjectName(QStringLiteral("newAddress"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/add"), QSize(), QIcon::Normal, QIcon::Off);
        newAddress->setIcon(icon);
        newAddress->setAutoDefault(false);

        horizontalLayout->addWidget(newAddress);

        copyAddress = new QPushButton(AddressBookPage);
        copyAddress->setObjectName(QStringLiteral("copyAddress"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/editcopy"), QSize(), QIcon::Normal, QIcon::Off);
        copyAddress->setIcon(icon1);
        copyAddress->setAutoDefault(false);

        horizontalLayout->addWidget(copyAddress);

        deleteAddress = new QPushButton(AddressBookPage);
        deleteAddress->setObjectName(QStringLiteral("deleteAddress"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/remove"), QSize(), QIcon::Normal, QIcon::Off);
        deleteAddress->setIcon(icon2);
        deleteAddress->setAutoDefault(false);

        horizontalLayout->addWidget(deleteAddress);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        exportButton = new QPushButton(AddressBookPage);
        exportButton->setObjectName(QStringLiteral("exportButton"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/export"), QSize(), QIcon::Normal, QIcon::Off);
        exportButton->setIcon(icon3);
        exportButton->setAutoDefault(false);

        horizontalLayout->addWidget(exportButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(AddressBookPage);

        QMetaObject::connectSlotsByName(AddressBookPage);
    } // setupUi

    void retranslateUi(QWidget *AddressBookPage)
    {
        searchLineEdit->setPlaceholderText(QApplication::translate("AddressBookPage", "Enter address or label to search", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        tableView->setToolTip(QApplication::translate("AddressBookPage", "Right-click to edit address or label", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        newAddress->setToolTip(QApplication::translate("AddressBookPage", "Create a new address", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        newAddress->setText(QApplication::translate("AddressBookPage", "&New", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        copyAddress->setToolTip(QApplication::translate("AddressBookPage", "Copy the currently selected address to the system clipboard", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        copyAddress->setText(QApplication::translate("AddressBookPage", "&Copy", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        deleteAddress->setToolTip(QApplication::translate("AddressBookPage", "Delete the currently selected address from the list", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        deleteAddress->setText(QApplication::translate("AddressBookPage", "&Delete", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        exportButton->setToolTip(QApplication::translate("AddressBookPage", "Export the data in the current tab to a file", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        exportButton->setText(QApplication::translate("AddressBookPage", "&Export", Q_NULLPTR));
        Q_UNUSED(AddressBookPage);
    } // retranslateUi

};

namespace Ui {
    class AddressBookPage: public Ui_AddressBookPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDRESSBOOKPAGE_H
