#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setStyleSheet("QPushButton { border-style: outset; border-width: 2px; border-radius: 10px; border-color: beige; "
                "font: bold 14px;  min-width: 10em;  padding: 6px; background-color: darkcyan; } "
                "QLineEdit { border-radius: 10px; background-color: darkgrey } ");
    w.show();
    return a.exec();
}
