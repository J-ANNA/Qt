#ifndef DETAIL_H
#define DETAIL_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QComboBox>
#include <QGridLayout>



class Detail : public QWidget
{
    Q_OBJECT
public:
    explicit Detail(QWidget *parent = 0);
private:
    QLabel *nationalLabel;
    QLabel *provinceLabel;
    QLabel *cityLabel;
    QLabel *introductLabel;
    QComboBox *nationalComboBox;
    QComboBox *provinceComboBox;
    QLineEdit *cityEdit;
    QTextEdit *introductEdit;
    QGridLayout *mainLayout;

signals:

public slots:
};

#endif // DETAIL_H
