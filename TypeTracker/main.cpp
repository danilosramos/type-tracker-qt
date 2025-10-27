#include "typetracker.h"
#include <QApplication>
#include <chrono>
#include <QString>
#include <QVector>
#include <iomanip>
#include <cstdlib>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TypeTracker w;
    w.show();
    return a.exec();

}

