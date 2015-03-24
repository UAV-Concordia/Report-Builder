/********************************************************************************
** Form generated from reading UI file 'barcodereader.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BARCODEREADER_H
#define UI_BARCODEREADER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BarCodeReader
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *DecodeImg;
    QListView *FolderListView;
    QTextEdit *textEdit;

    void setupUi(QWidget *BarCodeReader)
    {
        if (BarCodeReader->objectName().isEmpty())
            BarCodeReader->setObjectName(QStringLiteral("BarCodeReader"));
        BarCodeReader->resize(579, 344);
        widget = new QWidget(BarCodeReader);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 20, 551, 311));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setFrameShape(QFrame::StyledPanel);

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        DecodeImg = new QPushButton(widget);
        DecodeImg->setObjectName(QStringLiteral("DecodeImg"));

        horizontalLayout->addWidget(DecodeImg);


        verticalLayout->addLayout(horizontalLayout);

        FolderListView = new QListView(widget);
        FolderListView->setObjectName(QStringLiteral("FolderListView"));
        FolderListView->setFrameShape(QFrame::StyledPanel);
        FolderListView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        FolderListView->setViewMode(QListView::ListMode);

        verticalLayout->addWidget(FolderListView);

        textEdit = new QTextEdit(widget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setFrameShape(QFrame::StyledPanel);
        textEdit->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        textEdit->setReadOnly(true);
        textEdit->setOverwriteMode(true);

        verticalLayout->addWidget(textEdit);


        retranslateUi(BarCodeReader);

        QMetaObject::connectSlotsByName(BarCodeReader);
    } // setupUi

    void retranslateUi(QWidget *BarCodeReader)
    {
        BarCodeReader->setWindowTitle(QApplication::translate("BarCodeReader", "BarCodeReader", 0));
        label->setText(QApplication::translate("BarCodeReader", "Img Path:", 0));
        DecodeImg->setText(QApplication::translate("BarCodeReader", "Decode", 0));
    } // retranslateUi

};

namespace Ui {
    class BarCodeReader: public Ui_BarCodeReader {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BARCODEREADER_H
