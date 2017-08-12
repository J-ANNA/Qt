#ifndef PROGRESSDLG_H
#define PROGRESSDLG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QProgressBar>
#include <QProgressDialog>
#include <QPushButton>
#include <QComboBox>
#include <QGridLayout>


class ProgressDlg : public QDialog
{
    Q_OBJECT

public:
    ProgressDlg(QWidget *parent = 0);
    ~ProgressDlg();
private:
    QLabel *fileNumLabel;
    QLineEdit *fileNumLineEdit;
    QLabel *progressType;
    QComboBox *comboBox;
    QProgressBar *progressBar;
    QPushButton *startBtn;
    QGridLayout *mainLayout;
private slots:
    void startprogress();
};

#endif // PROGRESSDLG_H
