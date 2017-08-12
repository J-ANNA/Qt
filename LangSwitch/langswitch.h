#ifndef LANGSWITCH_H
#define LANGSWITCH_H

#include <QDialog>
#include <QComboBox>
#include <QLabel>

class LangSwitch : public QDialog
{
    Q_OBJECT

public:
    LangSwitch(QWidget *parent = 0);
    ~LangSwitch();
private slots:
    void changeLang(int index);
private:
    void createScreen();
    void changeTr(const QString &LangCode);
    void refreshLabel();
    QComboBox *comboBox;
    QLabel *label;
};

#endif // LANGSWITCH_H
