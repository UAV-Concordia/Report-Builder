#include "barcodereader.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BarCodeReader w;
    w.show();

    return a.exec();
}
