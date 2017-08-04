#ifndef COMMON_H
#define COMMON_H


#include <QDebug>
#include <QLoggingCategory>
#include <QString>

#define QT_MESSAGE_PATTERN "[%{time yyyyMMdd h:mm:ss.zzz t} %{if-debug}D%{endif}" \
                                                      "%{if-info}I%{endif}%{if-warning}W%{endif}%{if-critical}C%{endif}" \
                                                       "%{if-fatal}F%{endif}] %{file}:%{line} - %{message}" \
                                                       "- %{category}"

Q_DECLARE_LOGGING_CATEGORY(CoreFeature)
#define REDIRECT_DEBUG_TO_LOG 1
#define USE_OLD_TIME_LIMIT_LICENSE
#ifdef USE_OLD_TIME_LIMIT_LICENSE
static const QString time_limit = "06082017";
#endif

void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg);
void licenseChecker();

#endif // COMMON_H
