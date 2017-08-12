#ifndef FILEVIEW_H
#define FILEVIEW_H

#include <QDialog>
#include <QLineEdit>
#include <QListWidget>
#include <QVBoxLayout>
#include <QDir>
#include <QListWidgetItem>
#include <QFileInfoList>
#include <QFile>
#include <QPushButton>
#include <QMessageBox>

class FileView : public QDialog
{
    Q_OBJECT
public:
    FileView(QWidget *parent=0,Qt::WindowFlags f=0);
    ~FileView();
    void showFileInfoList(QFileInfoList list);

public slots:
    void slotShow(QDir dir);
    void slotDirShow(QListWidgetItem *item);
    void slotShowDeleteFileBox();
private:
    QLineEdit *fileLineEdit;
    QListWidget *fileListWidget;
    QVBoxLayout *mainLayout;
    QPushButton *btn;
    QMessageBox *deleteFileBox;
    QPushButton *enterBtn;
    QPushButton *cancelBtn;

};

#endif // FILEVIEW_H
