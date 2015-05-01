#include "reportgenerator.h"
#include "ui_reportgenerator.h"
#include "QFileDialog"
#include "QClipboard"


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
          tr("Open Object File"), ".", "KML files (*_vertices.kml)");

     QFileInfo fileInfo= QFileInfo(filePath);
     QString fileName =fileInfo.fileName();
     ui->objectFileLineEdit->setText(fileName);


     //update this in the model
    model->setObjectFile(filePath.toStdString());

    model->parseObjectFile();
}


void ReportGenerator::on_loadSurfaceFileButton_clicked()
{
    qDebug() << "Load surface File";

    QString filePath = QFileDialog::getOpenFileName(this,
         tr("Open Object File"), ".", "Text files (*.txt)");

    QFileInfo fileInfo= QFileInfo(filePath);
    QString fileName =fileInfo.fileName();
    ui->surfaceFileLineEdit->setText(fileName);

    //update this in the model

    model->setSurfaceFile(filePath.toStdString());

    model->parseSurfaceFile();
}

void ReportGenerator::on_loadVolumeFile_clicked()
{
    qDebug() << "Load volume File";

    QString filePath = QFileDialog::getOpenFileName(this,
         tr("Open Object File"), ".", "Text files (*.txt)");

    QFileInfo fileInfo= QFileInfo(filePath);
    QString fileName =fileInfo.fileName();
    ui->volumeFileLineEdit->setText(fileName);

    //update this in the model
    model->setVolumeFile(filePath.toStdString());

    model->parseVolumeFile();
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

    model->parsePointImageFile();
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
   displayFeature();
}

void ReportGenerator::displayFeature(){
    if(ui->featureList->currentItem()){
        QPalette *palette = new QPalette();
        QListWidgetItem* currentItem=ui->featureList->currentItem();
        QString featureName=currentItem->text();

        Feature* feature=model->getFeature(featureName.toStdString());

        if(feature){
            //Display name
             QString featureName = QString::fromStdString(feature->getName());
            ui->featureNameLineEdit->setText(featureName);

            ui->featureNameLineEdit->setReadOnly(true);


            palette->setColor(QPalette::Base,Qt::gray);
            palette->setColor(QPalette::Text,Qt::black);
            ui->featureNameLineEdit->setPalette(*palette);



            //Display type
            QString featureType = QString::fromStdString(feature->getStringType());

            int featureTypeIndex = -1;

            if (featureType==QString("Contaminated Area"))
                    featureTypeIndex =  ui->featureTypeComboBox->findText(QString("CONTAMINED_AREA"));
            else if (featureType==QString("Debris Pile"))
                     featureTypeIndex =  ui->featureTypeComboBox->findText(QString("DEBRIS_PILE"));
            else if (featureType==QString("Object"))
                     featureTypeIndex =  ui->featureTypeComboBox->findText(QString("OBJECT"));
            else if (featureType==QString("Person"))
                     featureTypeIndex =  ui->featureTypeComboBox->findText(QString("PERSON"));
            else if (featureType==QString("Structure"))
                     featureTypeIndex =  ui->featureTypeComboBox->findText(QString("STRUCTURE"));
            else if (featureType==QString("Train"))
                     featureTypeIndex =  ui->featureTypeComboBox->findText(QString("TRAIN"));
            else
                featureTypeIndex=-1;

            if ( featureTypeIndex != -1 ) { // -1 for not found
                qDebug() << "found";
               ui->featureTypeComboBox->setCurrentIndex(featureTypeIndex);
            }else{
                qDebug() << "not found";
                ui->featureTypeComboBox->setCurrentIndex(0);
            }

            //Display Structure State

             if (featureType==QString("Structure")){
                QString structureState = QString::fromStdString(feature->getStringStructureState());
                int structureStateIndex = -1;

                if (structureState==QString("Damaged"))
                    structureStateIndex =  ui->structureStateComboBox->findText(QString("DAMAGED"));
                else if (structureState==QString("Undamaged"))
                    structureStateIndex =  ui->structureStateComboBox->findText(QString("UNDAMAGED"));
                else
                    structureStateIndex=-1;

                if ( structureStateIndex != -1 ) { // -1 for not found
                    qDebug() << "found";
                   ui->structureStateComboBox->setCurrentIndex(structureStateIndex);
                }else{
                    qDebug() << "not found";
                    ui->structureStateComboBox->setCurrentIndex(0) ;
                }
                 ui->structureStateComboBox->setEnabled(true);
             }else{
                  ui->structureStateComboBox->setCurrentIndex(0);
                  ui->structureStateComboBox->setEnabled(false);
             }

             //Display object type

             if (featureType==QString("Object")){
                QString objectType = QString::fromStdString(feature->getStringObjectType());
                int objectTypeIndex = -1;

                if (objectType==QString("Boat"))
                    objectTypeIndex =  ui->objectTypeComboBox->findText(QString("BOAT"));
                else if (objectType==QString("Car"))
                    objectTypeIndex =  ui->objectTypeComboBox->findText(QString("CAR"));
                else if (objectType==QString("Fire"))
                    objectTypeIndex =  ui->objectTypeComboBox->findText(QString("FIRE"));
                else if (objectType==QString("Tent"))
                    objectTypeIndex =  ui->objectTypeComboBox->findText(QString("TENT"));
                else
                    objectTypeIndex=-1;

                if ( objectTypeIndex != -1 ) { // -1 for not found
                    qDebug() << "found";
                   ui->objectTypeComboBox->setCurrentIndex(objectTypeIndex);
                }else{
                    qDebug() << "not found";
                    ui->objectTypeComboBox->setCurrentIndex(0) ;
                }

                 ui->objectTypeComboBox->setEnabled(true);

             }else{
                  ui->objectTypeComboBox->setCurrentIndex(0);
                  ui->objectTypeComboBox->setEnabled(false);
             }

            //Display Barcode
             if (featureType==QString("Train")){
                 QString featureBarCode = QString::fromStdString(feature->getQRCode());
                 ui->featureBarCodeLineEdit->setText(featureBarCode);


                 ui->featureBarCodeLineEdit->setReadOnly(false);
                 palette->setColor(QPalette::Base,Qt::white);
                 palette->setColor(QPalette::Text,Qt::black);
                 ui->featureBarCodeLineEdit->setPalette(*palette);


             }else{
                  ui->featureBarCodeLineEdit->setText(QString::fromStdString(""));
                  ui->featureBarCodeLineEdit->setReadOnly(true);


                  palette->setColor(QPalette::Base,Qt::gray);
                  palette->setColor(QPalette::Text,Qt::black);
                  ui->featureBarCodeLineEdit->setPalette(*palette);
             }

            //Display Centroid
            vector<double> centroid=feature->getCentroid();
            QString featureCentroidLon = QString::fromStdString(to_string(centroid.at(0)));
            ui->featureCentroidLonLineEdit->setText(featureCentroidLon);

            ui->featureCentroidLonLineEdit->setReadOnly(true);

            palette->setColor(QPalette::Base,Qt::gray);
            palette->setColor(QPalette::Text,Qt::black);
            ui->featureCentroidLonLineEdit->setPalette(*palette);


            QString featureCentroidLat = QString::fromStdString(to_string(centroid.at(1)));
            ui->featureCentroidLatLineEdit->setText(featureCentroidLat);

            ui->featureCentroidLatLineEdit->setReadOnly(true);

            palette->setColor(QPalette::Base,Qt::gray);
            palette->setColor(QPalette::Text,Qt::black);
            ui->featureCentroidLatLineEdit->setPalette(*palette);


            //Display area
            QString featureArea = QString::fromStdString(to_string(feature->getArea()));
            ui->featureAreaLineEdit->setText(featureArea);

            ui->featureAreaLineEdit->setReadOnly(true);

            palette->setColor(QPalette::Base,Qt::gray);
            palette->setColor(QPalette::Text,Qt::black);
            ui->featureAreaLineEdit->setPalette(*palette);


            //Display volume

            QString featureVolume = QString::fromStdString(to_string(feature->getVolume()));
            ui->featureVolumeLineEdit->setText(featureVolume);


            ui->featureVolumeLineEdit->setReadOnly(true);

            palette->setColor(QPalette::Base,Qt::gray);
            palette->setColor(QPalette::Text,Qt::black);
            ui->featureVolumeLineEdit->setPalette(*palette);


            //Display bounding points
            //Clear bounding points list
            ui->boundingPointList->clear();

           vector<BoundingPoint> boundingPoints=feature->getBoundingPoints();

            for(BoundingPoint x:boundingPoints){

                QString qstr = QString::fromStdString(x.name);
                 qDebug() << qstr;
                 ui->boundingPointList->addItem(qstr);
            }

            //Display image
            //Clear image list
             ui->imageList->clear();

             vector<string> images=feature->getImagePaths();

             for(string x: images){

                 QString qstr = QString::fromStdString(x);
                  qDebug() << qstr;
                  ui->imageList->addItem(qstr);
             }

            //Display anything else



        }


    }
}


void ReportGenerator::on_copyToClipboardButton_clicked()
{
    QClipboard *clipboard = QApplication::clipboard();

    //Build Excel text according to type




    if(ui->featureList->currentItem()){
        QListWidgetItem* currentItem=ui->featureList->currentItem();
        QString featureName=currentItem->text();

        Feature* feature=model->getFeature(featureName.toStdString());
        QString clipboardText;
        if(feature){
            switch (feature->getType()){

            case CONTAMINED_AREA:
               clipboardText=QString::fromStdString(feature->getName()+"\t");
               clipboardText.append(QString::fromStdString(to_string(feature->getCentroid().at(0))+"\t"));
               clipboardText.append(QString::fromStdString(to_string(feature->getCentroid().at(1))+"\t"));
               clipboardText.append(QString::fromStdString(to_string(feature->getArea())+"\t"));

                break;
            case DEBRIS_PILE:
                clipboardText=QString::fromStdString(feature->getName()+"\t");
                clipboardText.append(QString::fromStdString(to_string(feature->getCentroid().at(0))+"\t"));
                clipboardText.append(QString::fromStdString(to_string(feature->getCentroid().at(1))+"\t"));
                clipboardText.append(QString::fromStdString(to_string(feature->getVolume())+"\t"));

                break;
            case OBJECT:
                clipboardText=QString::fromStdString(feature->getName()+"\t");
                clipboardText.append(QString::fromStdString(to_string(feature->getCentroid().at(0))+"\t"));
                clipboardText.append(QString::fromStdString(to_string(feature->getCentroid().at(1))+"\t"));
                clipboardText.append(QString::fromStdString(feature->getStringObjectType()+"\t"));
                break;
            case PERSON:
                clipboardText=QString::fromStdString(feature->getName()+"\t");
                clipboardText.append(QString::fromStdString(to_string(feature->getCentroid().at(0))+"\t"));
                clipboardText.append(QString::fromStdString(to_string(feature->getCentroid().at(1))+"\t"));
                break;
            case STRUCTURE:
                clipboardText=QString::fromStdString(feature->getName()+"\t");
                clipboardText.append(QString::fromStdString(to_string(feature->getCentroid().at(0))+"\t"));
                clipboardText.append(QString::fromStdString(to_string(feature->getCentroid().at(1))+"\t"));
                clipboardText.append(QString::fromStdString(feature->getStringStructureState()+"\t"));
                break;
            case TRAIN:
                clipboardText=QString::fromStdString(feature->getName()+"\t");
                clipboardText.append(QString::fromStdString(to_string(feature->getCentroid().at(0))+"\t"));
                clipboardText.append(QString::fromStdString(to_string(feature->getCentroid().at(1))+"\t"));
                clipboardText.append(QString::fromStdString(feature->getQRCode()+"\t"));
                break;
            default:
                clipboardText=QString::fromStdString("No feature");
                break;

            }
        }


    clipboard->setText(clipboardText);
    }
}

void ReportGenerator::on_pushButton_clicked()
{
    if (!ui->objectFileLineEdit->text().trimmed().isEmpty()){
        qDebug() << "Parsing Data";
        model->parseData();

    }

}

void ReportGenerator::on_featureTypeComboBox_activated(const QString &featureType)
{
    qDebug() << "type chosen" << featureType;
    //Save new Type

    QListWidgetItem* currentItem=ui->featureList->currentItem();
    QString featureName=currentItem->text();

    Feature* feature=model->getFeature(featureName.toStdString());

    if(feature){

        if (featureType==QString("CONTAMINED_AREA"))
                feature->setType(CONTAMINED_AREA);
        else if (featureType==QString("DEBRIS_PILE"))
                  feature->setType(DEBRIS_PILE);
        else if (featureType==QString("OBJECT"))
                 feature->setType(OBJECT);
        else if (featureType==QString("PERSON"))
                  feature->setType(PERSON);
        else if (featureType==QString("STRUCTURE"))
                 feature->setType(STRUCTURE);
        else if (featureType==QString("TRAIN"))
                feature->setType(TRAIN);
        else
                feature->setType(NO_FEATURE);


        displayFeature();
    }


}

void ReportGenerator::on_structureStateComboBox_activated(const QString &structureState)
{

    qDebug() << "structure state chosen" << structureState;
    //Save new Type

    QListWidgetItem* currentItem=ui->featureList->currentItem();
    QString featureName=currentItem->text();

    Feature* feature=model->getFeature(featureName.toStdString());

    if(feature){

        if (structureState==QString("DAMAGED"))
                feature->setStructureState(DAMAGED);
        else if (structureState==QString("UNDAMAGED"))
                  feature->setStructureState(UNDAMAGED);
        else
                feature->setStructureState(NO_STRUCTURE);


        displayFeature();
    }




}

void ReportGenerator::on_objectTypeComboBox_activated(const QString &objectType)
{

    qDebug() << "object type chosen" << objectType;
    //Save new Type

    QListWidgetItem* currentItem=ui->featureList->currentItem();
    QString featureName=currentItem->text();

    Feature* feature=model->getFeature(featureName.toStdString());

    if(feature){

        if (objectType==QString("BOAT"))
                feature->setObjectType(BOAT);
        else if (objectType==QString("CAR"))
                  feature->setObjectType(CAR);
        else if (objectType==QString("FIRE"))
                  feature->setObjectType(FIRE);
        else if (objectType==QString("TENT"))
                  feature->setObjectType(TENT);
        else
                feature->setObjectType(NO_OBJECT);


        displayFeature();
    }


}

void ReportGenerator::on_featureBarCodeLineEdit_editingFinished()
{
    qDebug() << "editing finished" ;

    QListWidgetItem* currentItem=ui->featureList->currentItem();
    QString featureName=currentItem->text();

    Feature* feature=model->getFeature(featureName.toStdString());

    if(feature){
       QString barCode= ui->featureBarCodeLineEdit->text();
       feature->setQRCode(barCode.toStdString());

        displayFeature();
    }


}

void ReportGenerator::on_featureList_activated(const QModelIndex &index)
{

}
