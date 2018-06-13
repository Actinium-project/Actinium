<<<<<<< HEAD
// Copyright (c) 2011-2014 The Bitcoin Core developers
=======
// Copyright (c) 2011-2017 The Bitcoin Core developers
>>>>>>> upstream/0.16
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_QT_MACNOTIFICATIONHANDLER_H
#define BITCOIN_QT_MACNOTIFICATIONHANDLER_H

#include <QObject>

<<<<<<< HEAD
/** Macintosh-specific notification handler (supports UserNotificationCenter and Growl).
=======
/** Macintosh-specific notification handler (supports UserNotificationCenter).
>>>>>>> upstream/0.16
 */
class MacNotificationHandler : public QObject
{
    Q_OBJECT

public:
<<<<<<< HEAD
    /** shows a 10.8+ UserNotification in the UserNotificationCenter
     */
    void showNotification(const QString &title, const QString &text);

    /** executes AppleScript */
    void sendAppleScript(const QString &script);

=======
    /** shows a macOS 10.8+ UserNotification in the UserNotificationCenter
     */
    void showNotification(const QString &title, const QString &text);

>>>>>>> upstream/0.16
    /** check if OS can handle UserNotifications */
    bool hasUserNotificationCenterSupport(void);
    static MacNotificationHandler *instance();
};


#endif // BITCOIN_QT_MACNOTIFICATIONHANDLER_H
