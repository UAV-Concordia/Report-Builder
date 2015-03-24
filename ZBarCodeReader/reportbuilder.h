#ifndef REPORTBUILDER_H
#define REPORTBUILDER_H

#include <QMainWindow>

namespace Ui {
class ReportBuilder;
}

class ReportBuilder : public QMainWindow
{
    Q_OBJECT

public:
    explicit ReportBuilder(QWidget *parent = 0);
    ~ReportBuilder();

private:
    Ui::ReportBuilder *ui;
};

#endif // REPORTBUILDER_H
