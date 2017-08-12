#ifndef NERWORKINFORMATION_H
#define NERWORKINFORMATION_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTextBrowser>

class NerworkInformation : public QWidget
{
    Q_OBJECT

public:
    NerworkInformation(QWidget *parent = 0);
    ~NerworkInformation();

    void getHostInformation();

private slots:
    void slotShowDetail();

private:
    QLabel *hostLabel;
    QLineEdit *hostLineEdit;
    QLabel *IPLabel;
    QLineEdit *IPLineEdit;
    QPushButton *detailBtn;
    QTextBrowser *detailText;
    QWidget *detailWidget;

};

#endif // NERWORKINFORMATION_H
