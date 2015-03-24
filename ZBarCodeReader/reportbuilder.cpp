#include "reportbuilder.h"
#include "ui_reportbuilder.h"

ReportBuilder::ReportBuilder(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ReportBuilder)
{
    ui->setupUi(this);
}

ReportBuilder::~ReportBuilder()
{
    delete ui;
}
