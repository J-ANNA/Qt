#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QFrame>
#include <QColor>
#include "inputdlg.h"
#include "msgboxdlg.h"
#include "customdlg.h"
#include <QMessageBox>

class MyMessageBox : public QMessageBox
{
    Q_OBJECT
public:
    MyMessageBox(QWidget *parent = 0);
    ~MyMessageBox();
    protected:
    void showEvent(QShowEvent* event);
};

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
     ~Dialog();
private:
    QPushButton *fileBtn;
    QLineEdit *fileLineEdit;
    QGridLayout *mainLayout;
    QPushButton *colorBtn;
    QFrame *colorFrame;
    QPushButton *fontBtn;
    QLineEdit *fontLineEdit;
    InputDlg *inputDlg;
    QPushButton *inputBtn;
    MsgBoxDlg *msgBoxDlg;
    QPushButton *msgBoxBtn;
    CustomDlg *customDlg;
    QPushButton *customDlgBtn;
    QPushButton *yesBtn;
    QPushButton *noBtn;
    QPushButton *cancel;
    QMessageBox *customMsg;





private slots:
    void showFile();
    void showColor();
    void showFont();
    void showInputDlg();
    void showMsgBoxDlg();
    void showCustomDlg();


};

#endif // DIALOG_H
