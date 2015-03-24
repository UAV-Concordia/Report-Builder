/********************************************************************************
** Form generated from reading UI file 'reportgenerator.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTGENERATOR_H
#define UI_REPORTGENERATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReportGenerator
{
public:
    QPushButton *generateReport;

    void setupUi(QWidget *ReportGenerator)
    {
        if (ReportGenerator->objectName().isEmpty())
            ReportGenerator->setObjectName(QStringLiteral("ReportGenerator"));
        ReportGenerator->resize(400, 300);
        generateReport = new QPushButton(ReportGenerator);
        generateReport->setObjectName(QStringLiteral("generateReport"));
        generateReport->setGeometry(QRect(150, 130, 121, 23));

        retranslateUi(ReportGenerator);

        QMetaObject::connectSlotsByName(ReportGenerator);
    } // setupUi

    void retranslateUi(QWidget *ReportGenerator)
    {
        ReportGenerator->setWindowTitle(QApplication::translate("ReportGenerator", "Form", 0));
        generateReport->setText(QApplication::translate("ReportGenerator", "GenerateReport", 0));
    } // retranslateUi

};

namespace Ui {
    class ReportGenerator: public Ui_ReportGenerator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTGENERATOR_H
