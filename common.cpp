#include "common.h"
#include <stdio.h>
#include <QFile>
#include <QDir>
#include <QApplication>
#include <QTextStream>
#include <QDateTime>
#include <QMessageBox>

#define MAX_LOG_SIZE 500000

Q_LOGGING_CATEGORY(CoreFeature, "CoreFeature")

void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QDir logDir(QApplication::applicationDirPath()+"/log");
    if (!logDir.exists()) {
        logDir.mkpath(".");
    }
    QFile output(QApplication::applicationDirPath()+"/log/log.log");
    QTextStream stream(&output);
    if (!output.open(QIODevice::ReadWrite | QIODevice::Append)) {
        qDebug() << "cannot open log file";
        return;
    }
    QByteArray localMsg = msg.toLocal8Bit();
    QString message;
    switch (type) {
    case QtDebugMsg:
        message = QString("DEB: %1 %2 (%3:%4, %5)\n").arg(QDateTime::currentDateTime().toString("yyyyMMdd h:mm:ss.zzz t")).arg(localMsg.constData()).arg(context.file).arg(context.line).arg(context.function);
        break;
    case QtInfoMsg:
        message = QString("INF: %1 %2 (%3:%4, %5)\n").arg(QDateTime::currentDateTime().toString("yyyyMMdd h:mm:ss.zzz t")).arg(localMsg.constData()).arg(context.file).arg(context.line).arg(context.function);
        break;
    case QtWarningMsg:
        message = QString("WAR: %1 %2 (%3:%4, %5)\n").arg(QDateTime::currentDateTime().toString("yyyyMMdd h:mm:ss.zzz t")).arg(localMsg.constData()).arg(context.file).arg(context.line).arg(context.function);
        break;
    case QtCriticalMsg:
        message = QString("CRI: %1 %2 (%3:%4, %5)\n").arg(QDateTime::currentDateTime().toString("yyyyMMdd h:mm:ss.zzz t")).arg(localMsg.constData()).arg(context.file).arg(context.line).arg(context.function);
        break;
    case QtFatalMsg:
        message = QString("FAL: %1 %2 (%3:%4, %5)\n").arg(QDateTime::currentDateTime().toString("yyyyMMdd h:mm:ss.zzz t")).arg(localMsg.constData()).arg(context.file).arg(context.line).arg(context.function);
        stream << message;
        abort();
    }
    stream << message;
    /** Backup if file too large */
    if (output.size() > MAX_LOG_SIZE) {
        QString backupPath = QApplication::applicationDirPath()+"/log/"+QDateTime::currentDateTime().toString("yyyy_MM_dd_hh_mm_ss_zzz")+".log";
        QFile backup(backupPath);
        QTextStream backupStream(&backup);
        if (!backup.open(QIODevice::WriteOnly | QIODevice::Append)) {
            qWarning() << "could not copy log file to archive.";
        } else {
            stream.seek(0);
            backupStream << stream.readAll();
            backup.close();
            //            printf("File size %d\n",output.size());
            output.remove();
        }
    }
    if (output.size() > 2*MAX_LOG_SIZE) {
        output.remove();
    }
}

void licenseChecker()
{
#ifdef USE_OLD_TIME_LIMIT_LICENSE
    QDate current = QDate::currentDate();
    QDate limit = QDate::fromString(time_limit, "ddMMyyyy");
    QDate actual = limit;
    actual = actual.addDays(qint64(-1));
    if (limit.isValid()) {
        if (current > limit) {
            QMessageBox::warning(nullptr,"License checker warning","License expired");
            exit(1);
        }
    }
#endif
}
