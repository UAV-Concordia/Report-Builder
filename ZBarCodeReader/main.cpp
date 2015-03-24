#include "barcodereader.h"
#include "reportgenerator.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BarCodeReader w;
    w.show();

    ReportGenerator repGen;
    repGen.show();

    return a.exec();
}
