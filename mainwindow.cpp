#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug("Add style sheet");
    QFile f(":qdarkstyle/style.qss");
    if (!f.exists()) {
        qWarning("Unable to set stylesheet, file not found");
    } else {
        f.open(QFile::ReadOnly | QFile::Text);
        QTextStream ts(&f);
        qApp->setStyleSheet(ts.readAll());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnQuit_clicked()
{
    qApp->quit();
}
