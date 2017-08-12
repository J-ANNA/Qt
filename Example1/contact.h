#ifndef CONTACT_H
#define CONTACT_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QGridLayout>

class Contact : public QWidget
{
    Q_OBJECT
public:
    explicit Contact(QWidget *parent = 0);
private:
    QLabel *emailLabel;
    QLabel *addrLabel;
    QLabel *codeLabel;
    QLabel *moveTelLabel;
    QLabel *proTelLabel;
    QLineEdit *emailEdit;
    QLineEdit *addrEdit;
    QLineEdit *codeEdit;
    QLineEdit *moveTelEdit;
    QLineEdit *proTelEdit;
    QCheckBox *moveTelCheckBox;

    QGridLayout *mainLayout;
signals:

public slots:
};

#endif // CONTACT_H
