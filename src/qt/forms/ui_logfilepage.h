/********************************************************************************
** Form generated from reading UI file 'logfilepage.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGFILEPAGE_H
#define UI_LOGFILEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LogfilePage
{
public:
    QVBoxLayout *verticalLayout_3;
    QTableWidget *tblLogs;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lblLoggerStatus;
    QPushButton *btnRefreshLogger;
    QComboBox *cbxSearchEngine;

    void setupUi(QWidget *LogfilePage)
    {
        if (LogfilePage->objectName().isEmpty())
            LogfilePage->setObjectName(QStringLiteral("LogfilePage"));
        LogfilePage->resize(1051, 632);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LogfilePage->sizePolicy().hasHeightForWidth());
        LogfilePage->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(LogfilePage);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        tblLogs = new QTableWidget(LogfilePage);
        if (tblLogs->columnCount() < 3)
            tblLogs->setColumnCount(3);
        tblLogs->setObjectName(QStringLiteral("tblLogs"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tblLogs->sizePolicy().hasHeightForWidth());
        tblLogs->setSizePolicy(sizePolicy1);
        tblLogs->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblLogs->setTabKeyNavigation(true);
        tblLogs->setProperty("showDropIndicator", QVariant(false));
        tblLogs->setDragDropOverwriteMode(false);
        tblLogs->setAlternatingRowColors(true);
        tblLogs->setSortingEnabled(true);
        tblLogs->setColumnCount(3);
        tblLogs->horizontalHeader()->setStretchLastSection(true);
        tblLogs->verticalHeader()->setStretchLastSection(false);

        verticalLayout_3->addWidget(tblLogs);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lblLoggerStatus = new QLabel(LogfilePage);
        lblLoggerStatus->setObjectName(QStringLiteral("lblLoggerStatus"));

        horizontalLayout_3->addWidget(lblLoggerStatus);

        btnRefreshLogger = new QPushButton(LogfilePage);
        btnRefreshLogger->setObjectName(QStringLiteral("btnRefreshLogger"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btnRefreshLogger->sizePolicy().hasHeightForWidth());
        btnRefreshLogger->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(btnRefreshLogger);

        cbxSearchEngine = new QComboBox(LogfilePage);
        cbxSearchEngine->setObjectName(QStringLiteral("cbxSearchEngine"));
        sizePolicy2.setHeightForWidth(cbxSearchEngine->sizePolicy().hasHeightForWidth());
        cbxSearchEngine->setSizePolicy(sizePolicy2);
        cbxSearchEngine->setContextMenuPolicy(Qt::NoContextMenu);
        cbxSearchEngine->setLayoutDirection(Qt::LeftToRight);
        cbxSearchEngine->setCurrentText(QStringLiteral("DuckDuckGo"));

        horizontalLayout_3->addWidget(cbxSearchEngine);


        verticalLayout_3->addLayout(horizontalLayout_3);


        retranslateUi(LogfilePage);

        QMetaObject::connectSlotsByName(LogfilePage);
    } // setupUi

    void retranslateUi(QWidget *LogfilePage)
    {
        LogfilePage->setWindowTitle(QApplication::translate("LogfilePage", "Logger", Q_NULLPTR));
        lblLoggerStatus->setText(QString());
        btnRefreshLogger->setText(QApplication::translate("LogfilePage", "Refresh", Q_NULLPTR));
        cbxSearchEngine->clear();
        cbxSearchEngine->insertItems(0, QStringList()
         << QApplication::translate("LogfilePage", "DuckDuckGo", Q_NULLPTR)
         << QApplication::translate("LogfilePage", "Google", Q_NULLPTR)
        );
#ifndef QT_NO_TOOLTIP
        cbxSearchEngine->setToolTip(QApplication::translate("LogfilePage", "<html><head/><body><p>Search Engine</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class LogfilePage: public Ui_LogfilePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGFILEPAGE_H
