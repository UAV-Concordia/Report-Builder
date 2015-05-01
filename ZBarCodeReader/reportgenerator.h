#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H

#include "model.h"
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

    void on_loadObjectFileButton_clicked();



    void on_loadSurfaceFileButton_clicked();

    void on_loadVolumeFile_clicked();

    void on_loadPointImageFile_2_clicked();



    void on_refreshListButton_clicked();

    void on_featureList_clicked(const QModelIndex &index);

    void on_copyToClipboardButton_clicked();

    void on_pushButton_clicked();

    void on_featureTypeComboBox_activated(const QString &arg1);

    void on_structureStateComboBox_activated(const QString &arg1);

    void on_objectTypeComboBox_activated(const QString &arg1);

    void on_featureBarCodeLineEdit_editingFinished();

    void on_featureList_activated(const QModelIndex &index);

private:
    Ui::ReportGenerator *ui;
    QTextDocument * const m_document;
    QTextCursor m_cursor;

    Model *model;


    void displayFeature();
};

#endif // REPORTGENERATOR_H
