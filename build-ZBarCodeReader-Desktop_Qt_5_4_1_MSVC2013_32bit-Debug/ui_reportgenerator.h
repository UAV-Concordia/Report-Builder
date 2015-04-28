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
    QLineEdit *featureTypeLineEdit;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *featureCentroidLatLineEdit;
    QLineEdit *featureCentroidLonLineEdit;
    QLabel *label_4;
    QLineEdit *featureAreaLineEdit;
    QLabel *label_5;
    QLineEdit *featureVolumeLineEdit;
    QLabel *label_6;
    QListWidget *imageList;
    QPushButton *pushButton;
    QPushButton *refreshListButton;
    QPushButton *copyToClipboardButton;

    void setupUi(QWidget *ReportGenerator)
    {
        if (ReportGenerator->objectName().isEmpty())
            ReportGenerator->setObjectName(QStringLiteral("ReportGenerator"));
        ReportGenerator->resize(769, 314);
        generateReport = new QPushButton(ReportGenerator);
        generateReport->setObjectName(QStringLiteral("generateReport"));
        generateReport->setGeometry(QRect(360, 270, 121, 23));
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
        featureTypeLineEdit = new QLineEdit(ReportGenerator);
        featureTypeLineEdit->setObjectName(QStringLiteral("featureTypeLineEdit"));
        featureTypeLineEdit->setGeometry(QRect(630, 50, 113, 20));
        label_2 = new QLabel(ReportGenerator);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(500, 50, 47, 13));
        label_3 = new QLabel(ReportGenerator);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(500, 80, 101, 16));
        featureCentroidLatLineEdit = new QLineEdit(ReportGenerator);
        featureCentroidLatLineEdit->setObjectName(QStringLiteral("featureCentroidLatLineEdit"));
        featureCentroidLatLineEdit->setGeometry(QRect(690, 80, 71, 20));
        featureCentroidLonLineEdit = new QLineEdit(ReportGenerator);
        featureCentroidLonLineEdit->setObjectName(QStringLiteral("featureCentroidLonLineEdit"));
        featureCentroidLonLineEdit->setGeometry(QRect(610, 80, 71, 20));
        label_4 = new QLabel(ReportGenerator);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(500, 110, 47, 13));
        featureAreaLineEdit = new QLineEdit(ReportGenerator);
        featureAreaLineEdit->setObjectName(QStringLiteral("featureAreaLineEdit"));
        featureAreaLineEdit->setGeometry(QRect(630, 110, 113, 20));
        label_5 = new QLabel(ReportGenerator);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(500, 140, 47, 13));
        featureVolumeLineEdit = new QLineEdit(ReportGenerator);
        featureVolumeLineEdit->setObjectName(QStringLiteral("featureVolumeLineEdit"));
        featureVolumeLineEdit->setGeometry(QRect(630, 140, 113, 20));
        label_6 = new QLabel(ReportGenerator);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(500, 210, 81, 16));
        imageList = new QListWidget(ReportGenerator);
        imageList->setObjectName(QStringLiteral("imageList"));
        imageList->setGeometry(QRect(610, 170, 151, 111));
        pushButton = new QPushButton(ReportGenerator);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(100, 180, 141, 23));
        refreshListButton = new QPushButton(ReportGenerator);
        refreshListButton->setObjectName(QStringLiteral("refreshListButton"));
        refreshListButton->setGeometry(QRect(360, 210, 121, 23));
        copyToClipboardButton = new QPushButton(ReportGenerator);
        copyToClipboardButton->setObjectName(QStringLiteral("copyToClipboardButton"));
        copyToClipboardButton->setGeometry(QRect(360, 240, 121, 23));

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
        featureTypeLineEdit->setText(QString());
        label_2->setText(QApplication::translate("ReportGenerator", "Type", 0));
        label_3->setText(QApplication::translate("ReportGenerator", "Centroid (Lon/Lat)", 0));
        featureCentroidLatLineEdit->setText(QString());
        featureCentroidLonLineEdit->setText(QString());
        label_4->setText(QApplication::translate("ReportGenerator", "Area", 0));
        featureAreaLineEdit->setText(QString());
        label_5->setText(QApplication::translate("ReportGenerator", "Volume", 0));
        featureVolumeLineEdit->setText(QString());
        label_6->setText(QApplication::translate("ReportGenerator", "Image List", 0));
        pushButton->setText(QApplication::translate("ReportGenerator", "Parse Data", 0));
        refreshListButton->setText(QApplication::translate("ReportGenerator", "Refresh List", 0));
        copyToClipboardButton->setText(QApplication::translate("ReportGenerator", "Copy to Clipboard", 0));
    } // retranslateUi

};

namespace Ui {
    class ReportGenerator: public Ui_ReportGenerator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTGENERATOR_H
