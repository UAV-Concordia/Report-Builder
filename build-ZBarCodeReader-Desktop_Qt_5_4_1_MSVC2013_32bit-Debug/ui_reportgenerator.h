/********************************************************************************
** Form generated from reading UI file 'reportgenerator.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTGENERATOR_H
#define UI_REPORTGENERATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReportGenerator
{
public:
    QPushButton *generateReport;
    QPushButton *loadObjectFileButton;
    QPushButton *loadSurfaceFileButton;
    QPushButton *loadPointImageFile_2;
    QLineEdit *objectFileLineEdit;
    QLineEdit *surfaceFileLineEdit;
    QLineEdit *volumeFileLineEdit;
    QPushButton *loadVolumeFile;
    QLineEdit *pointImageFileLineEdit;
    QFrame *line;
    QListWidget *featureList;
    QLineEdit *featureNameLineEdit;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *featureCentroidLatLineEdit;
    QLineEdit *featureCentroidLonLineEdit;
    QLabel *label_4;
    QLineEdit *featureAreaLineEdit;
    QLabel *label_5;
    QLineEdit *featureVolumeLineEdit;
    QPushButton *pushButton;
    QPushButton *refreshListButton;
    QPushButton *copyToClipboardButton;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QComboBox *featureTypeComboBox;
    QComboBox *structureStateComboBox;
    QComboBox *objectTypeComboBox;
    QFrame *line_2;
    QListWidget *imageList;
    QLabel *label_10;
    QLineEdit *featureBarCodeLineEdit;
    QLabel *label_6;
    QListWidget *boundingPointList;
    QLabel *label_11;

    void setupUi(QWidget *ReportGenerator)
    {
        if (ReportGenerator->objectName().isEmpty())
            ReportGenerator->setObjectName(QStringLiteral("ReportGenerator"));
        ReportGenerator->resize(769, 603);
        generateReport = new QPushButton(ReportGenerator);
        generateReport->setObjectName(QStringLiteral("generateReport"));
        generateReport->setGeometry(QRect(110, 240, 121, 23));
        loadObjectFileButton = new QPushButton(ReportGenerator);
        loadObjectFileButton->setObjectName(QStringLiteral("loadObjectFileButton"));
        loadObjectFileButton->setGeometry(QRect(190, 20, 111, 23));
        loadSurfaceFileButton = new QPushButton(ReportGenerator);
        loadSurfaceFileButton->setObjectName(QStringLiteral("loadSurfaceFileButton"));
        loadSurfaceFileButton->setGeometry(QRect(190, 60, 111, 23));
        loadPointImageFile_2 = new QPushButton(ReportGenerator);
        loadPointImageFile_2->setObjectName(QStringLiteral("loadPointImageFile_2"));
        loadPointImageFile_2->setGeometry(QRect(190, 140, 111, 23));
        objectFileLineEdit = new QLineEdit(ReportGenerator);
        objectFileLineEdit->setObjectName(QStringLiteral("objectFileLineEdit"));
        objectFileLineEdit->setGeometry(QRect(50, 20, 113, 20));
        surfaceFileLineEdit = new QLineEdit(ReportGenerator);
        surfaceFileLineEdit->setObjectName(QStringLiteral("surfaceFileLineEdit"));
        surfaceFileLineEdit->setGeometry(QRect(50, 60, 113, 20));
        volumeFileLineEdit = new QLineEdit(ReportGenerator);
        volumeFileLineEdit->setObjectName(QStringLiteral("volumeFileLineEdit"));
        volumeFileLineEdit->setGeometry(QRect(50, 100, 113, 20));
        loadVolumeFile = new QPushButton(ReportGenerator);
        loadVolumeFile->setObjectName(QStringLiteral("loadVolumeFile"));
        loadVolumeFile->setGeometry(QRect(190, 100, 111, 23));
        pointImageFileLineEdit = new QLineEdit(ReportGenerator);
        pointImageFileLineEdit->setObjectName(QStringLiteral("pointImageFileLineEdit"));
        pointImageFileLineEdit->setGeometry(QRect(50, 140, 113, 20));
        line = new QFrame(ReportGenerator);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(313, 0, 20, 301));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        featureList = new QListWidget(ReportGenerator);
        featureList->setObjectName(QStringLiteral("featureList"));
        featureList->setGeometry(QRect(350, 10, 131, 192));
        featureNameLineEdit = new QLineEdit(ReportGenerator);
        featureNameLineEdit->setObjectName(QStringLiteral("featureNameLineEdit"));
        featureNameLineEdit->setGeometry(QRect(630, 20, 113, 20));
        label = new QLabel(ReportGenerator);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(500, 20, 47, 13));
        label_3 = new QLabel(ReportGenerator);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(500, 170, 101, 16));
        featureCentroidLatLineEdit = new QLineEdit(ReportGenerator);
        featureCentroidLatLineEdit->setObjectName(QStringLiteral("featureCentroidLatLineEdit"));
        featureCentroidLatLineEdit->setGeometry(QRect(690, 170, 71, 20));
        featureCentroidLonLineEdit = new QLineEdit(ReportGenerator);
        featureCentroidLonLineEdit->setObjectName(QStringLiteral("featureCentroidLonLineEdit"));
        featureCentroidLonLineEdit->setGeometry(QRect(610, 170, 71, 20));
        label_4 = new QLabel(ReportGenerator);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(500, 200, 47, 13));
        featureAreaLineEdit = new QLineEdit(ReportGenerator);
        featureAreaLineEdit->setObjectName(QStringLiteral("featureAreaLineEdit"));
        featureAreaLineEdit->setGeometry(QRect(630, 200, 113, 20));
        label_5 = new QLabel(ReportGenerator);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(500, 230, 47, 13));
        featureVolumeLineEdit = new QLineEdit(ReportGenerator);
        featureVolumeLineEdit->setObjectName(QStringLiteral("featureVolumeLineEdit"));
        featureVolumeLineEdit->setGeometry(QRect(630, 230, 113, 20));
        pushButton = new QPushButton(ReportGenerator);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(100, 180, 141, 23));
        refreshListButton = new QPushButton(ReportGenerator);
        refreshListButton->setObjectName(QStringLiteral("refreshListButton"));
        refreshListButton->setGeometry(QRect(360, 210, 121, 23));
        copyToClipboardButton = new QPushButton(ReportGenerator);
        copyToClipboardButton->setObjectName(QStringLiteral("copyToClipboardButton"));
        copyToClipboardButton->setGeometry(QRect(360, 250, 121, 23));
        label_7 = new QLabel(ReportGenerator);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(500, 50, 47, 13));
        label_8 = new QLabel(ReportGenerator);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(500, 80, 47, 13));
        label_9 = new QLabel(ReportGenerator);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(500, 110, 71, 16));
        featureTypeComboBox = new QComboBox(ReportGenerator);
        featureTypeComboBox->setObjectName(QStringLiteral("featureTypeComboBox"));
        featureTypeComboBox->setGeometry(QRect(630, 50, 111, 22));
        structureStateComboBox = new QComboBox(ReportGenerator);
        structureStateComboBox->setObjectName(QStringLiteral("structureStateComboBox"));
        structureStateComboBox->setGeometry(QRect(630, 80, 111, 22));
        objectTypeComboBox = new QComboBox(ReportGenerator);
        objectTypeComboBox->setObjectName(QStringLiteral("objectTypeComboBox"));
        objectTypeComboBox->setGeometry(QRect(630, 110, 111, 22));
        line_2 = new QFrame(ReportGenerator);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(0, 290, 771, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        imageList = new QListWidget(ReportGenerator);
        imageList->setObjectName(QStringLiteral("imageList"));
        imageList->setGeometry(QRect(600, 350, 151, 241));
        label_10 = new QLabel(ReportGenerator);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(650, 320, 81, 16));
        featureBarCodeLineEdit = new QLineEdit(ReportGenerator);
        featureBarCodeLineEdit->setObjectName(QStringLiteral("featureBarCodeLineEdit"));
        featureBarCodeLineEdit->setGeometry(QRect(630, 140, 113, 20));
        label_6 = new QLabel(ReportGenerator);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(500, 140, 47, 13));
        boundingPointList = new QListWidget(ReportGenerator);
        boundingPointList->setObjectName(QStringLiteral("boundingPointList"));
        boundingPointList->setGeometry(QRect(10, 350, 151, 241));
        label_11 = new QLabel(ReportGenerator);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(40, 320, 91, 16));

        retranslateUi(ReportGenerator);

        QMetaObject::connectSlotsByName(ReportGenerator);
    } // setupUi

    void retranslateUi(QWidget *ReportGenerator)
    {
        ReportGenerator->setWindowTitle(QApplication::translate("ReportGenerator", "Form", 0));
        generateReport->setText(QApplication::translate("ReportGenerator", "GenerateReport", 0));
        loadObjectFileButton->setText(QApplication::translate("ReportGenerator", "Load Object File", 0));
        loadSurfaceFileButton->setText(QApplication::translate("ReportGenerator", "Load Surface File", 0));
        loadPointImageFile_2->setText(QApplication::translate("ReportGenerator", "Load Point-Image File", 0));
        loadVolumeFile->setText(QApplication::translate("ReportGenerator", "Load Volume File", 0));
        label->setText(QApplication::translate("ReportGenerator", "Name", 0));
        label_3->setText(QApplication::translate("ReportGenerator", "Centroid (Lon/Lat)", 0));
        featureCentroidLatLineEdit->setText(QString());
        featureCentroidLonLineEdit->setText(QString());
        label_4->setText(QApplication::translate("ReportGenerator", "Area", 0));
        featureAreaLineEdit->setText(QString());
        label_5->setText(QApplication::translate("ReportGenerator", "Volume", 0));
        featureVolumeLineEdit->setText(QString());
        pushButton->setText(QApplication::translate("ReportGenerator", "Parse Data", 0));
        refreshListButton->setText(QApplication::translate("ReportGenerator", "Refresh List", 0));
        copyToClipboardButton->setText(QApplication::translate("ReportGenerator", "Copy to Clipboard", 0));
        label_7->setText(QApplication::translate("ReportGenerator", "Type", 0));
        label_8->setText(QApplication::translate("ReportGenerator", "State", 0));
        label_9->setText(QApplication::translate("ReportGenerator", "Object Type", 0));
        featureTypeComboBox->clear();
        featureTypeComboBox->insertItems(0, QStringList()
         << QApplication::translate("ReportGenerator", "NONE", 0)
         << QApplication::translate("ReportGenerator", "CONTAMINED_AREA", 0)
         << QApplication::translate("ReportGenerator", "DEBRIS_PILE", 0)
         << QApplication::translate("ReportGenerator", "OBJECT", 0)
         << QApplication::translate("ReportGenerator", "PERSON", 0)
         << QApplication::translate("ReportGenerator", "STRUCTURE", 0)
         << QApplication::translate("ReportGenerator", "TRAIN", 0)
        );
        structureStateComboBox->clear();
        structureStateComboBox->insertItems(0, QStringList()
         << QApplication::translate("ReportGenerator", "NONE", 0)
         << QApplication::translate("ReportGenerator", "DAMAGED", 0)
         << QApplication::translate("ReportGenerator", "UNDAMAGED", 0)
        );
        objectTypeComboBox->clear();
        objectTypeComboBox->insertItems(0, QStringList()
         << QApplication::translate("ReportGenerator", "NONE", 0)
         << QApplication::translate("ReportGenerator", "BOAT", 0)
         << QApplication::translate("ReportGenerator", "CAR", 0)
         << QApplication::translate("ReportGenerator", "FIRE", 0)
         << QApplication::translate("ReportGenerator", "TENT", 0)
        );
        label_10->setText(QApplication::translate("ReportGenerator", "Image List", 0));
        featureBarCodeLineEdit->setText(QString());
        label_6->setText(QApplication::translate("ReportGenerator", "Bar code", 0));
        label_11->setText(QApplication::translate("ReportGenerator", "Bounding Point List", 0));
    } // retranslateUi

};

namespace Ui {
    class ReportGenerator: public Ui_ReportGenerator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTGENERATOR_H
