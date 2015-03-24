#include "reportgenerator.h"
#include "ui_reportgenerator.h"




ReportGenerator::ReportGenerator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReportGenerator),
    m_document(new QTextDocument()),
            m_cursor(m_document)
{
    ui->setupUi(this);
}

ReportGenerator::~ReportGenerator()
{
    delete ui;
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
