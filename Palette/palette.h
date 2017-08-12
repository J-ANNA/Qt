#ifndef PALETTE_H
#define PALETTE_H

#include <QDialog>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFrame>

class Palette : public QDialog
{
    Q_OBJECT

public:
    Palette(QWidget *parent = 0);
    ~Palette();
    void createCtrlFrame();
    void createContentFrame();
    void fillColorList(QComboBox *);

private slots:
    void showWindow();
    void showWindowText();
    void showButton();
    void showButtonText();
    void showBase();
private:
    QFrame *ctrlFrame;
    QLabel *windowLabel;
    QComboBox *windowComboBox;
    QLabel *windowTextLabel;
    QComboBox *windowTextComboBox;
    QLabel *btnLabel;
    QComboBox *btnComboBox;
    QLabel *btnTextLabel;
    QComboBox *btnTextComboBox;
    QLabel *baseLabel;
    QComboBox *baseComboBox;
    QFrame *contentFrame;
    QLabel *valueLabel;
    QComboBox *valueComboBox;
    QLabel *strLabel;
    QLineEdit *strLineEdit;
    QTextEdit *textEdit;
    QPushButton *okBtn;
    QPushButton *cancelBtn;





};

#endif // PALETTE_H
