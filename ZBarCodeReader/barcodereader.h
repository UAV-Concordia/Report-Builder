#ifndef BARCODEREADER_H
#define BARCODEREADER_H

#include <QWidget>
#include <QProcess>
#include <QFileSystemModel>
#include <QTreeView>

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
    QString cmd = "C:\\Users\\marco\\Documents\\Projects\\Qt\\ZBarCodeReader\\ZBar\\bin\\zbarimg";
    void getBarcodeValue();
};

#endif // BARCODEREADER_H
