#ifndef SHOWWIDGET_H
#define SHOWWIDGET_H

#include <QWidget>
#include <QImage>
#include <QLabel>
#include <QTextEdit>

class ShowWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ShowWidget(QWidget *parent = 0);
    QImage img;
    QLabel *imgLabel;
    QTextEdit *textEdit;


signals:

public slots:
};

#endif // SHOWWIDGET_H
