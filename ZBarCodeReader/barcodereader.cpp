#include "barcodereader.h"
#include "ui_barcodereader.h"

BarCodeReader::BarCodeReader(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BarCodeReader)
{
    ui->setupUi(this);
    //ui->FolderListView->setViewMode(QListView::ListMode);
    fsModel = new QFileSystemModel;
    fsModel->setReadOnly(true);
    fsModel->setRootPath(QDir::currentPath());
    tree = new QTreeView(ui->FolderListView);
    tree->setModel(fsModel);
   // tree->setRootIndex(fsModel->index(QDir::currentPath()));
}

BarCodeReader::~BarCodeReader()
{
    delete ui;
    delete fsModel;
    delete tree;
}

void BarCodeReader::on_DecodeImg_clicked()
{
    QString folderPath = fsModel->filePath(tree->currentIndex());
    QDir dir(folderPath);
    QStringList files = dir.entryList(dir.Files);
    QList<QString>::iterator f;

    for (f = files.begin(); f != files.end(); f++)
    {
        process.start(cmd, QStringList() << (dir.path() + "\\" + (*f)));
        process.waitForFinished();

        getBarcodeValue();
    }
}

void BarCodeReader::getBarcodeValue()
{
    char data[1024];
    qint64 lineLength = process.read(data, sizeof(data));

    if (lineLength != -1)
    {
        ui->textEdit->append(data);
        ui->textEdit->append("\n");
    }
    else
        ui->textEdit->append("Error\n");

    process.terminate();
}


