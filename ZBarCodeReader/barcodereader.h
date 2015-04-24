#ifndef BARCODEREADER_H
#define BARCODEREADER_H

#include <QWidget>
#include <QProcess>
#include <QFileSystemModel>
#include <QTreeView>
#include <ZBar\include\zbar.h>

namespace Ui {
class BarCodeReader;
}

class BarCodeReader : public QWidget
{
    Q_OBJECT

public:
    explicit BarCodeReader(QWidget *parent = 0);
    ~BarCodeReader();

private slots:
    void on_DecodeImg_clicked();

private:
    Ui::BarCodeReader *ui;
    QFileSystemModel *fsModel;
    QTreeView *tree;
    QProcess process;
    QFile *file;
    QTextStream *outStream;
   // zbar::ImageScanner *decoder;
    QString cmd = QDir::currentPath() + "\\..\\ZBar\\bin\\zbarimg";
    void getBarcodeValue(QString imgName);
};

#endif // BARCODEREADER_H
