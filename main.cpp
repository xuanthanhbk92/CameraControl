#include "mainwindow.h"
#include <QApplication>

//QPushButton
//{background-color: white;
// border-style: solid;
// border-width:1px;
// border-radius:20px;
// border-color: red;
//}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Camera control");
    w.show();

    return a.exec();
}
