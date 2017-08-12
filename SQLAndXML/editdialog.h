#ifndef EDITDIALOG_H
#define EDITDIALOG_H

#include <QDialog>
#include <QtSql>
#include <QtXml>
#include <connectdlg.h>
#include <QDialogButtonBox>


class EditDialog : public QDialog
{
    Q_OBJECT
public:
    EditDialog(QSqlRelationalTableModel *cars,QSqlTableModel *factory,QDomDocument details,
               QFile *output,QWidget *parent = 0);
private slots:
    void revert();
    void submit();
private:
    int addNewCar(const QString &name,int factoryId);
    int addNewFactory(const QString &factory,const QString &address);
    void addAttribs(int carId,QStringList attribs);
    QDialogButtonBox *createButtons();
    QGroupBox *createInputWidgets();
    int findFactoryId(const QString &factory);
    int generateCarId();
    int generateFactoryId();
    QSqlRelationalTableModel *carModel;
    QSqlTableModel *factoryModel;
    QDomDocument carDetails;
    QFile *outputFile;
    QLineEdit *factoryLineEdit;
    QLineEdit *addressLineEdit;
    QLineEdit *carLineEdit;
    QSpinBox *yearSpinBox;
    QLineEdit *attribLineEdit;

};

#endif // EDITDIALOG_H
