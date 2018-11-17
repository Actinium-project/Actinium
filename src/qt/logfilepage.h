#ifndef LOGFILEPAGE_H
#define LOGFILEPAGE_H

#include <sync.h>

#include <QMenu>
#include <QTimer>
#include <QWidget>
#include <QCheckBox>
#include <QIcon>
#include <QDateTime>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QRegExp>
#include <QStringList>
#include <QStandardPaths>
#include <QDebug>
#include <QDesktopServices>
#include <QUrl>
#include <QClipboard>
#include <QComboBox>
#include <QFileInfo>

#define LOGGER_UPDATE_SECONDS 1

namespace Enums
{
    namespace Logger
    {
        enum LoggerCommand {
            Unknown = 0,
            Activate,
            Deactivate
        };
    }
}
namespace Ui {
    class LogfilePage;
}

QT_BEGIN_NAMESPACE
class QModelIndex;
QT_END_NAMESPACE

/** Logger page widget */
class LogfilePage : public QWidget
{
    Q_OBJECT

public:
    explicit LogfilePage(QWidget *parent = 0);
    ~LogfilePage();
    void SendCommand(Enums::Logger::LoggerCommand cmd = Enums::Logger::LoggerCommand::Activate);

private:
    QMenu *contextMenu;
    int64_t nTimeFilterUpdated;
    qint64 qiLastPos = 0;
    std::map<QString,QString> searchEngines;
    QString selectedQuery;

public Q_SLOTS:
    void updateLogTable();

Q_SIGNALS:

private:
    QTimer *timer;
    Ui::LogfilePage *ui;

    // Protects logtable
    CCriticalSection cs_loglist;

private Q_SLOTS:
    void showContextMenu(const QPoint &);
    void onCopyEntrySelected();
    void onWebSearchSelected();
    void on_cbxSearchEngine_currentIndexChanged(int index);
    void onBtnResetLoggerClicked();
};
#endif // LogfilePage_H
