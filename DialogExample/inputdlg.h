#ifndef INPUTDLG_H
#define INPUTDLG_H
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>

class InputDlg : public QDialog
{
    Q_OBJECT
public:
    InputDlg(QWidget* parent=0);
private:
    QLabel *nameLabel;
    QLabel *sexLabel;
    QLabel *ageLabel;
    QLabel *scorelabel;
    QLabel *nameInputLabel;
    QLabel *sexInputLabel;
    QLabel *ageInputLabel;
    QLabel *scoreInputLabel;
    QPushButton *nameBtn;
    QPushButton *sexBtn;
    QPushButton *ageBtn;
    QPushButton *scoreBtn;
    QGridLayout *mainLayout;

signals:


private slots:
    void changeName();
    void changeSex();
    void changeAge();
    void changeScore();

};

#endif // INPUTDLG_H
