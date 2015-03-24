#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H

#include <QWidget>
#include <QDebug>
#include <QTextDocumentWriter>
#include <QTextDocument>
#include <QTextCursor>


namespace Ui {
class ReportGenerator;
}

class ReportGenerator : public QWidget
{
    Q_OBJECT

public:
    explicit ReportGenerator(QWidget *parent = 0);
    ~ReportGenerator();

   void write(const QString &fileName);


private slots:
    void on_generateReport_clicked();

private:
    Ui::ReportGenerator *ui;
    QTextDocument * const m_document;
    QTextCursor m_cursor;
};

#endif // REPORTGENERATOR_H
