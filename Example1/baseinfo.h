#ifndef BASEINFO_H
#define BASEINFO_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QComboBox>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>

class BaseInfo : public QWidget
{
    Q_OBJECT
public:
    BaseInfo(QWidget *parent = 0);
private:
    //整体
    QGridLayout *mainLayout;

    //左侧
    QLabel *userNameLabel;
    QLabel *nameLabel;
    QLabel *sexLabel;
    QLabel *departmentLabel;
    QLabel *ageLabel;
    QLabel *otherLabel;
    QLineEdit *userNameEdit;
    QLineEdit *nameEdit;
    QComboBox *sexComboBox;
    QTextEdit *departmentEdit;
    QLineEdit *ageEdit;
    QGridLayout *leftLayout;

    //右侧
    QLabel *headLabel;
    QLabel *headIconLabel;
    QPushButton *updateHeadBtn;
    QHBoxLayout *topRightLayout;
    QLabel *introductionLabel;
    QTextEdit *introductionEdit;
    QVBoxLayout *rightLayout;


};

#endif // BASEINFO_H
