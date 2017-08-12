#ifndef IMGPROCESSOR_H
#define IMGPROCESSOR_H

#include <QMainWindow>
#include <QImage>
#include <QLabel>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QToolButton>
#include <QToolBar>
#include <QComboBox>
#include <QSpinBox>
#include <QFontComboBox>
#include <QTextCharFormat>
#include <QString>
#include <QFontComboBox>
#include <QActionGroup>
#include "showwidget.h"


class ImgProcessor : public QMainWindow
{
    Q_OBJECT

public:
    ImgProcessor(QWidget *parent = 0);
    ~ImgProcessor();
    void createActions();
    void createMenus();
    void createToolBars();
    void loadFile(QString fileName);
    void mergeFormat(QTextCharFormat format);

private:
    QMenu *fileMenu;
    QMenu *zoomMenu;
    QMenu *rotateMenu;
    QMenu *mirrorMenu;
    QImage img;
    QString fileName;
    ShowWidget *showWidget;
    QAction *openFileAction;
    QAction *newFileAction;
    QAction *printTextAction;
    QAction *printImgAction;
    QAction *exitAction;
    QAction *copyAction;
    QAction *cutAction;
    QAction *pasteAction;
    QAction *aboutAction;
    QAction *zoomInAction;
    QAction *zoomOutAction;
    QAction *rotate90Action;
    QAction *rotate180Action;
    QAction *rotate270Action;
    QAction *mirrorVerticalAction;
    QAction *mirrorHorizontalAction;
    QAction *undoAction;
    QAction *redoAction;
    QToolBar *fileTool;
    QToolBar *zoomTool;
    QToolBar *rotateTool;
    QToolBar *mirrorTool;
    QToolBar *doToolBar;
    QToolBar *fontToolBar;
    QLabel *fontLabel;
    QFontComboBox *fontComboBox;
    QLabel *sizeLabel;
    QComboBox *sizeComboBox;
    QToolButton *boldBtn;
    QToolButton *italicBtn;
    QToolButton *underlineBtn;
    QToolButton *colorBtn;

    QLabel *listLabel;
    QComboBox *listComboBox;
    QActionGroup *actGrp;
    QAction *leftAction;
    QAction *rightAction;
    QAction *centerAction;
    QAction *justifyAction;
    QToolBar *listToolBar;




private slots:
    void showNewFile();
    void showOpenFile();
    void showPrintText();
    void showPrintImg();
    void showZoomIn();
    void showZoomOut();
    void showRotate90();
    void showRotate180();
    void showRotate270();
    void showMirrorVertical();
    void showMirrorHorizontal();
    void showFontComboBox(QString comboStr);
    void showSizeComboBox(QString spinValue);
    void showBoldBtn();
    void showItalicBtn();
    void showUnderlineBtn();
    void showColorBtn();
    void showCurrentFormatChanged(const QTextCharFormat &fmt);

    void showList(int index);
    void showAlignment(QAction *act);
    void showCursorPositionChanged();






};

#endif // IMGPROCESSOR_H


