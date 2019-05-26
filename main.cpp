#include "widget.h"
#include <QApplication>
#include <QPropertyAnimation>
#include <QDateTime>
#include <QScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    w.show();


    return a.exec();
}




