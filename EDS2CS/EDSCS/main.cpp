#include <QtGui/QApplication>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QProcess"
#include "QDebug"
#include "QString"
#include "QTextBrowser"
#include "QTextEdit"
#include "QStringList"
#include "QTimer"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.move(1202, 0);

    return a.exec();
}
