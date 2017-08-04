#include "mainwindow.h"
#include "common.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    licenseChecker();
    /** Init log */
    qSetMessagePattern(QT_MESSAGE_PATTERN);
#if REDIRECT_DEBUG_TO_LOG
    qInstallMessageHandler(myMessageOutput); // Install the handler
#endif
    MainWindow w;
    w.setWindowTitle("Camera control");
    w.show();
    qDebug("App start %d %d",100,200);
    qDebug(CoreFeature, "Debug logging");
    qWarning("Warning log");
    qInfo("Infomation log");
    qCritical("Critical log");
//    qFatal("Falal log");
    return a.exec();
}
