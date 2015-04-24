#include "barcodereader.h"
#include "ui_barcodereader.h"
#include <QFile>
#include <QTextStream>

BarCodeReader::BarCodeReader(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BarCodeReader)
{
    ui->setupUi(this);
    //ui->FolderListView->setViewMode(QListView::ListMode);
    fsModel = new QFileSystemModel;
    fsModel->setReadOnly(true);
    //fsModel->setFilter(QDir::AllDirs);
    fsModel->setRootPath(QDir::currentPath());
    tree = new QTreeView(ui->FolderListView);
    tree->setModel(fsModel);
   // tree->setRootIndex(fsModel->index(QDir::currentPath()));

    //decoder->set_config(zbar::ZBAR_NONE, zbar::ZBAR_CFG_ENABLE, 1);

    file = new QFile("testResults.txt");
}

BarCodeReader::~BarCodeReader()
{
    delete ui;
    delete fsModel;
    delete tree;
    delete file;
    delete outStream;
}

void BarCodeReader::on_DecodeImg_clicked()
{
    QString folderPath = fsModel->filePath(tree->currentIndex());
    QDir dir(folderPath);
    QStringList files = dir.entryList(dir.Files);
    QList<QString>::iterator f;

    file->open(QIODevice::WriteOnly);
    outStream = new QTextStream(file);

    for (f = files.begin(); f != files.end(); f++)
    {
        process.start(cmd, QStringList() << (dir.path() + "\\" + (*f)));
        process.waitForFinished();

        getBarcodeValue(*f);
    }

    file->close();
}

void BarCodeReader::getBarcodeValue(QString imgName)
{
    char data[1024];
    qint64 lineLength = process.read(data, sizeof(data));

    *outStream << (imgName);
    *outStream << (": \r\n");

    if (lineLength != -1)
    {
        ui->textEdit->append(imgName + ": " + data);
        ui->textEdit->append("\n");
        *outStream << (data);
        *outStream << ("\n");
    }
    else
    {
        ui->textEdit->append("Error\n");
       *outStream << ("Error\n");
    }

    *outStream << ("-------------------------------------------- \r\n");
    process.terminate();
}


