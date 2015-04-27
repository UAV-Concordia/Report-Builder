#include "reportgenerator.h"
#include "ui_reportgenerator.h"
#include "QFileDialog"



ReportGenerator::ReportGenerator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReportGenerator),
    m_document(new QTextDocument()),
            m_cursor(m_document)
{
    ui->setupUi(this);
    model=new Model();


    m_cursor.insertText(QObject::tr(
                   "Report %1\n"));

          QTextTableFormat tableFormat;
          tableFormat.setCellPadding(5);
          tableFormat.setHeaderRowCount(1);
          tableFormat.setBorderStyle(
                      QTextFrameFormat::BorderStyle_Solid);
          tableFormat.setWidth(QTextLength(
                      QTextLength::PercentageLength, 100));
          m_cursor.insertTable(1, 3, tableFormat);
          m_cursor.insertText(QObject::tr("Date"));
          m_cursor.movePosition(QTextCursor::NextCell);
          m_cursor.insertText(QObject::tr("Duration (sec)"));
          m_cursor.movePosition(QTextCursor::NextCell);
          m_cursor.insertText(QObject::tr("Cost"));



}

ReportGenerator::~ReportGenerator()
{
    delete ui;
    delete m_document;
}

void ReportGenerator::write(const QString &fileName)
   {
     QTextDocumentWriter writer(fileName);



     if (writer.write(m_document))
          qDebug() << "Report written";
     else
         qDebug() << "Report not written";

   }




void ReportGenerator::on_generateReport_clicked()
{
   qDebug() << "Writing report";

     write("reporttest.odt");
}

void ReportGenerator::on_loadObjectFileButton_clicked()
{
     qDebug() << "Load object File";

     QString filePath = QFileDialog::getOpenFileName(this,
          tr("Open Object File"), ".");

     QFileInfo fileInfo= QFileInfo(filePath);
     QString fileName =fileInfo.fileName();
     ui->objectFileLineEdit->setText(fileName);


     //update this in the model
    model->setObjectFile(filePath.toStdString());
}


void ReportGenerator::on_loadSurfaceFileButton_clicked()
{
    qDebug() << "Load surface File";

    QString filePath = QFileDialog::getOpenFileName(this,
         tr("Open Object File"), ".");

    QFileInfo fileInfo= QFileInfo(filePath);
    QString fileName =fileInfo.fileName();
    ui->surfaceFileLineEdit->setText(fileName);

    //update this in the model

    model->setSurfaceFile(filePath.toStdString());
}

void ReportGenerator::on_loadVolumeFile_clicked()
{
    qDebug() << "Load volume File";

    QString filePath = QFileDialog::getOpenFileName(this,
         tr("Open Object File"), ".");

    QFileInfo fileInfo= QFileInfo(filePath);
    QString fileName =fileInfo.fileName();
    ui->volumeFileLineEdit->setText(fileName);

    //update this in the model
    model->setVolumeFile(filePath.toStdString());
}

void ReportGenerator::on_loadPointImageFile_2_clicked()
{
    qDebug() << "Load point Image File";

    QString filePath = QFileDialog::getOpenFileName(this,
         tr("Open Object File"), ".");

    QFileInfo fileInfo= QFileInfo(filePath);
    QString fileName =fileInfo.fileName();
    ui->pointImageFileLineEdit->setText(fileName);

    //update this in the model
    model->setPointToImageFile(filePath.toStdString());
}



void ReportGenerator::on_refreshListButton_clicked()
{
    //Clear feature list
    ui->featureList->clear();

    //Load features
    vector<string> featureNames=model->getFeatureNames();

    for(string x:featureNames){

        QString qstr = QString::fromStdString(x);
         qDebug() << qstr;

         ui->featureList->addItem(qstr);
    }


}

void ReportGenerator::on_featureList_clicked(const QModelIndex &index)
{
    if(ui->featureList->currentItem()){
        QListWidgetItem* currentItem=ui->featureList->currentItem();
        QString featureName=currentItem->text();

        Feature* feature=model->getFeature(featureName.toStdString());

        if(feature){
            //Display name
             QString featureName = QString::fromStdString(feature->getName());
            ui->featureNameLineEdit->setText(featureName);

            //Display type
            QString featureType = QString::fromStdString(feature->getStringType());
            ui->featureTypeLineEdit->setText(featureType);

            //Display Centroid
            vector<double> centroid=feature->getCentroid();
            QString featureCentroidLon = QString::fromStdString(to_string(centroid.at(0)));
            ui->featureCentroidLonLineEdit->setText(featureCentroidLon);

            QString featureCentroidLat = QString::fromStdString(to_string(centroid.at(1)));
            ui->featureCentroidLatLineEdit->setText(featureCentroidLat);


            //Display area
            QString featureArea = QString::fromStdString(to_string(feature->getArea()));
            ui->featureAreaLineEdit->setText(featureArea);

            //Display volume

            QString featureVolume = QString::fromStdString(to_string(feature->getVolume()));
            ui->featureVolumeLineEdit->setText(featureVolume);

            //Display anything else

        }


    }

}
