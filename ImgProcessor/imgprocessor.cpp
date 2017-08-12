#include "imgprocessor.h"
#include <QApplication>
#include <QVBoxLayout>
#include <QDialog>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QPainter>
#include <QMatrix>
#include <QFont>
#include <QColor>
#include <QColorDialog>
#include <QTextCharFormat>
#include <QTextListFormat>
#include <QTextList>

ImgProcessor::ImgProcessor(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("Easy Word"));
    showWidget = new ShowWidget(this);
    setCentralWidget(showWidget);
    fontLabel = new QLabel(tr("字体"));
    fontComboBox = new QFontComboBox;
    fontComboBox->setFontFilters(QFontComboBox::ScalableFonts);
    sizeLabel = new QLabel(tr("字号"));
    sizeComboBox = new QComboBox;
    QFontDatabase db;
    foreach(int size,db.standardSizes())
        sizeComboBox->addItem(QString::number(size));
    boldBtn = new QToolButton;
    boldBtn->setText(tr("加粗"));
    boldBtn->setCheckable(true);
    italicBtn = new QToolButton;
    italicBtn->setText(tr("斜体"));
    italicBtn->setCheckable(true);
    underlineBtn = new QToolButton;
    underlineBtn->setText(tr("下划线"));
    underlineBtn->setCheckable(true);
    underlineBtn->setChecked(true);
    colorBtn = new QToolButton;
    colorBtn->setText(tr("颜色"));
    connect(fontComboBox,SIGNAL(activated(QString)),this,SLOT(showFontComboBox(QString)));
    connect(sizeComboBox,SIGNAL(activated(QString)),this,SLOT(showSizeComboBox(QString)));
    connect(boldBtn,SIGNAL(clicked()),this,SLOT(showBoldBtn()));
    connect(italicBtn,SIGNAL(clicked()),this,SLOT(showItalicBtn()));
    connect(underlineBtn,SIGNAL(clicked()),this,SLOT(showUnderlineBtn()));
    connect(colorBtn,SIGNAL(clicked()),this,SLOT(showColorBtn()));
    connect(showWidget->textEdit,SIGNAL(currentCharFormatChanged(const QTextCharFormat&)),
            this,SLOT(showCurrentFormatChanged(const QTextCharFormat&)));

    listLabel = new QLabel(tr("排序"));
    listComboBox = new QComboBox;
    listComboBox->addItem("Standard");
    listComboBox->addItem("QTextListFormat::ListDisc");
    listComboBox->addItem("QTextListFormat::ListCircle");
    listComboBox->addItem("QTextListFormat::ListSquare");
    listComboBox->addItem("QTextListFormat::ListDecimal");
    listComboBox->addItem("QTextListFormat::ListLowerAlpha");
    listComboBox->addItem("QTextListFormat::ListUpperAlpha");
    listComboBox->addItem("QTextListFormat::ListLowerRoman");
    listComboBox->addItem("QTextListFormat::ListUpperRoman");
    connect(listComboBox,SIGNAL(activated(int)),this,SLOT(showList(int)));


    createActions();
    connect(showWidget->textEdit->document(),SIGNAL(undoAvailable(bool)),redoAction,SLOT(setEnabled(bool))); //必须是redoAction
    connect(showWidget->textEdit->document(),SIGNAL(redoAvailable(bool)),redoAction,SLOT(setEnabled(bool)));
    connect(showWidget->textEdit,SIGNAL(cursorPositionChanged()),this,SLOT(showCursorPositionChanged()));
    createMenus();
    createToolBars();
    if(img.load(":/picture/8cm.jpg"))
    {
        showWidget->imgLabel->setPixmap(QPixmap::fromImage(img));
    }
}

ImgProcessor::~ImgProcessor()
{

}

void ImgProcessor::createActions()
{
    openFileAction = new QAction(tr("打开"),this);
    openFileAction->setShortcut(tr("Ctrl+O"));
    openFileAction->setStatusTip(tr("打开一个文件"));
    connect(openFileAction,SIGNAL(triggered()),this,SLOT(showOpenFile()));
    newFileAction = new QAction(tr("新建"),this);
    newFileAction->setShortcut(tr("Ctrl+N"));
    newFileAction->setStatusTip(tr("新建一个文件"));
    connect(newFileAction,SIGNAL(triggered()),this,SLOT(showNewFile()));
    exitAction = new QAction(tr("退出"),this);
    exitAction->setShortcut(tr("Ctrl+Q"));
    exitAction->setStatusTip(tr("退出程序"));
    connect(exitAction,SIGNAL(triggered()),this,SLOT(close()));
    copyAction = new QAction(tr("复制"),this);
    copyAction->setShortcut(tr("Ctrl+C"));
    copyAction->setStatusTip(tr("复制文件"));
    connect(copyAction,SIGNAL(triggered()),showWidget->textEdit,SLOT(copy()));
    cutAction = new QAction(tr("剪切"),this);
    cutAction->setShortcut(tr("Ctrl+X"));
    cutAction->setStatusTip(tr("剪切文件"));
    connect(cutAction,SIGNAL(triggered()),showWidget->textEdit,SLOT(cut()));
    pasteAction = new QAction(tr("粘贴"),this);
    pasteAction->setShortcut(tr("Ctrl+V"));
    pasteAction->setStatusTip(tr("粘贴文件"));
    connect(pasteAction,SIGNAL(triggered()),showWidget->textEdit,SLOT(paste()));
    aboutAction = new QAction(tr("关于"),this);
//    connect(aboutAction,SIGNAL(triggered()),this,SLOT(Qapplication::aboutQt()));

   printTextAction = new QAction(tr("打印文本"),this);
   printTextAction->setStatusTip(tr("打印一个文本"));
   connect(printTextAction,SIGNAL(triggered()),this,SLOT(showPrintText()));
   printImgAction = new QAction(tr("打印图像"),this);
   printImgAction->setStatusTip(tr("打印一幅图像"));
   connect(printImgAction,SIGNAL(triggered()),this,SLOT(showPrintImg()));
   zoomInAction = new QAction(tr("放大"),this);
   zoomInAction->setStatusTip(tr("放大一张图片"));
   connect(zoomInAction,SIGNAL(triggered()),this,SLOT(showZoomIn()));
   zoomOutAction = new QAction(tr("缩小"),this);
   zoomOutAction->setStatusTip(tr("缩小一张图片"));
   connect(zoomOutAction,SIGNAL(triggered()),this,SLOT(showZoomOut()));
   rotate90Action = new QAction(tr("旋转90°"),this);
   rotate90Action->setStatusTip(tr("将图片旋转90°"));
   connect(rotate90Action,SIGNAL(triggered()),this,SLOT(showRotate90()));
   rotate180Action = new QAction(tr("旋转180°"),this);
   rotate180Action->setStatusTip(tr("将图片旋转180°"));
   connect(rotate180Action,SIGNAL(triggered()),this,SLOT(showRotate180()));
   rotate270Action = new QAction(tr("旋转270°"),this);
   rotate270Action->setStatusTip(tr("将图片旋转270°"));
   connect(rotate270Action,SIGNAL(triggered()),this,SLOT(showRotate270()));
   mirrorVerticalAction = new QAction(tr("纵向镜像"),this);
   mirrorVerticalAction->setStatusTip(tr("将图片做纵向镜像"));
   connect(mirrorVerticalAction,SIGNAL(triggered()),this,SLOT(showMirrorVertical()));
   mirrorHorizontalAction = new QAction(tr("横向镜像"),this);
   mirrorHorizontalAction->setStatusTip(tr("将图片做横向镜像"));
   connect(mirrorHorizontalAction,SIGNAL(triggered()),this,SLOT(showMirrorHorizontal()));
   undoAction = new QAction(tr("撤销"),this);
   connect(undoAction,SIGNAL(triggered()),showWidget->textEdit,SLOT(undo()));
   redoAction = new QAction(tr("重做"),this);
   connect(redoAction,SIGNAL(triggered()),showWidget->textEdit,SLOT(redo()));

   actGrp = new QActionGroup(this);
   leftAction = new QAction(tr("左对齐"),actGrp);
   leftAction->setCheckable(true);
   rightAction = new QAction(tr("右对齐"),actGrp);
   rightAction->setCheckable(true);
   centerAction = new QAction(tr("居中"),actGrp);
   centerAction->setCheckable(true);
   justifyAction = new QAction(tr("两端对齐"),actGrp);
   justifyAction->setCheckable(true);
   connect(actGrp,SIGNAL(triggered(QAction*)),this,SLOT(showAlignment(QAction*)));

}

void ImgProcessor::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("文件"));
    fileMenu->addAction(openFileAction);
    fileMenu->addAction(newFileAction);
    fileMenu->addAction(printTextAction);
    fileMenu->addAction(printImgAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

    zoomMenu = menuBar()->addMenu(tr("编辑"));
    zoomMenu->addAction(copyAction);
    zoomMenu->addAction(cutAction);
    zoomMenu->addAction(pasteAction);
    zoomMenu->addAction(aboutAction);
    zoomMenu->addSeparator();
    zoomMenu->addAction(zoomInAction);
    zoomMenu->addAction(zoomOutAction);

    rotateMenu = menuBar()->addMenu(tr("旋转"));
    rotateMenu->addAction(rotate90Action);
    rotateMenu->addAction(rotate180Action);
    rotateMenu->addAction(rotate270Action);

    mirrorMenu = menuBar()->addMenu(tr("镜像"));
    mirrorMenu->addAction(mirrorVerticalAction);
    mirrorMenu->addAction(mirrorHorizontalAction);
}

void ImgProcessor::createToolBars()
{
    fileTool = addToolBar(tr("File"));
    fileTool->addAction(openFileAction);
    fileTool->addAction(newFileAction);
    fileTool->addAction(printTextAction);
    fileTool->addAction(printImgAction);

    zoomTool = addToolBar(tr("Edit"));
    zoomTool->addAction(copyAction);
    zoomTool->addAction(cutAction);
    zoomTool->addAction(pasteAction);
    zoomTool->addSeparator();
    zoomTool->addAction(zoomInAction);
    zoomTool->addAction(zoomOutAction);

    rotateTool = addToolBar(tr("Rotate"));
    rotateTool->addAction(rotate90Action);
    rotateTool->addAction(rotate180Action);
    rotateTool->addAction(rotate270Action);

//    doToolBar = new QToolBar(tr("DoEdit"));
//    addToolBar(Qt::RightToolBarArea,doToolBar);
    doToolBar = addToolBar(tr("DoEdit"));
    doToolBar->addAction(undoAction);
    doToolBar->addAction(redoAction);
    doToolBar->setAllowedAreas(Qt::LeftToolBarArea);

    fontToolBar = addToolBar("Font");
    fontToolBar->addWidget(fontLabel);
    fontToolBar->addWidget(fontComboBox);
    fontToolBar->addWidget(sizeLabel);
    fontToolBar->addWidget(sizeComboBox);
    fontToolBar->addWidget(boldBtn);
    fontToolBar->addWidget(italicBtn);
    fontToolBar->addWidget(underlineBtn);
    fontToolBar->addSeparator();
    fontToolBar->addWidget(colorBtn);

    listToolBar = addToolBar("List");
    listToolBar->addWidget(listLabel);
    listToolBar->addWidget(listComboBox);
    listToolBar->addSeparator();
    listToolBar->addActions(actGrp->actions());

}

void ImgProcessor::showNewFile()
{
    ImgProcessor *newImgProcessor = new ImgProcessor;
    newImgProcessor->show();
}

void ImgProcessor::showOpenFile()
{
    fileName = QFileDialog::getOpenFileName(this);
    if(!fileName.isEmpty())
    {
        if(showWidget->textEdit->document()->isEmpty())
        {
            loadFile(fileName);
        }
        else
        {
            ImgProcessor *newImgProcessor = new ImgProcessor;
            newImgProcessor->show();
//            newImgProcessor->showOpenFile();
            newImgProcessor->loadFile(fileName);
        }
    }
}

void ImgProcessor::loadFile(QString fileName)
{
    printf("file name:%s\n",fileName.data());
    QFile file(fileName);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream textStream(&file);
        while(!textStream.atEnd())
        {
            showWidget->textEdit->append(textStream.readLine());
            printf("read line\n");
        }
        printf("end\n");
    }

}

void ImgProcessor::mergeFormat(QTextCharFormat format)
{
    QTextCursor cursor = showWidget->textEdit->textCursor();
    if(!cursor.hasSelection())
    {
        cursor.select(QTextCursor::WordUnderCursor);
    }
    cursor.mergeCharFormat(format);
    showWidget->textEdit->mergeCurrentCharFormat(format);
}

void ImgProcessor::showPrintText()
{
    QPrinter printer;
    QPrintDialog printDialog(&printer,this);
    if(printDialog.exec())
    {
        QTextDocument *doc =showWidget->textEdit->document();
        doc->print(&printer);
    }
}

void ImgProcessor::showPrintImg()
{
    QPrinter printerImg;
    QPrintDialog printDialog(&printerImg,this);
    if(printDialog.exec())
    {
        QPainter painter(&printerImg);
        QRect rect = painter.viewport();
        QSize size = img.size();
        size.scale(rect.size(),Qt::KeepAspectRatio);

        painter.setViewport(rect.x(),rect.y(),size.width(),size.height());
        painter.setWindow(img.rect());
        painter.drawImage(0,0,img);
    }
}

void ImgProcessor::showZoomIn()
{
    if(img.isNull())
        return;
    QMatrix matrix;
    matrix.scale(2,2);
    img = img.transformed(matrix);
    showWidget->imgLabel->setPixmap(QPixmap::fromImage(img));

}

void ImgProcessor::showZoomOut()
{
    if(img.isNull())
        return;
    QMatrix matrix;
    matrix.scale(0.5,0.5);
    img = img.transformed(matrix);
    showWidget->imgLabel->setPixmap(QPixmap::fromImage(img));
}

void ImgProcessor::showRotate90()
{
    if(img.isNull())
        return;
    QMatrix matrix;
    matrix.rotate(90);
    img = img.transformed(matrix);
    showWidget->imgLabel->setPixmap(QPixmap::fromImage(img));
}

void ImgProcessor::showRotate180()
{
    if(img.isNull())
        return;
    QMatrix matrix;
    matrix.rotate(180);
    img = img.transformed(matrix);
    showWidget->imgLabel->setPixmap(QPixmap::fromImage(img));
}

void ImgProcessor::showRotate270()
{
    if(img.isNull())
        return;
    QMatrix matrix;
    matrix.rotate(270);
    img = img.transformed(matrix);
    showWidget->imgLabel->setPixmap(QPixmap::fromImage(img));
}

void ImgProcessor::showMirrorVertical()
{
    if(img.isNull())
        return;
    img = img.mirrored(false,true);
    showWidget->imgLabel->setPixmap(QPixmap::fromImage(img));
}

void ImgProcessor::showMirrorHorizontal()
{
    if(img.isNull())
        return;
    img = img.mirrored(true,false);
    showWidget->imgLabel->setPixmap(QPixmap::fromImage(img));
}

void ImgProcessor::showFontComboBox(QString comboStr)
{
    QTextCharFormat fmt;
    fmt.setFontFamily(comboStr);
    mergeFormat(fmt);
}

void ImgProcessor::showSizeComboBox(QString spinValue)
{
    QTextCharFormat fmt;
    fmt.setFontPointSize(spinValue.toFloat());
    mergeFormat(fmt);
//    showWidget->textEdit->mergeCurrentCharFormat(fmt);
}

void ImgProcessor::showBoldBtn()
{
    QTextCharFormat fmt;
    fmt.setFontWeight(boldBtn->isChecked()?QFont::Bold : QFont::Normal);
    mergeFormat(fmt);
}

void ImgProcessor::showItalicBtn()
{
    QTextCharFormat fmt;
    fmt.setFontItalic(italicBtn->isChecked());
    mergeFormat(fmt);
}

void ImgProcessor::showUnderlineBtn()
{
    QTextCharFormat fmt;
    fmt.setFontUnderline(underlineBtn->isChecked());
    mergeFormat(fmt);
}

void ImgProcessor::showColorBtn()
{
    QColor color = QColorDialog::getColor(Qt::red,this);
    if(color.isValid())
    {
        QTextCharFormat fmt;
        fmt.setForeground(color);
        mergeFormat(fmt);
    }
}

void ImgProcessor::showCurrentFormatChanged(const QTextCharFormat &fmt)
{
//    fontComboBox->setCurrentIndex(fontComboBox->findText(showWidget->textEdit->textCursor().charFormat().fontFamily()));
    fontComboBox->setCurrentIndex(fontComboBox->findText(fmt.fontFamily()));
    sizeComboBox->setCurrentIndex(sizeComboBox->findText(QString::number(fmt.fontPointSize())));
    boldBtn->setChecked(fmt.font().bold());
    italicBtn->setChecked(fmt.fontItalic());
    underlineBtn->setChecked(fmt.fontUnderline());
}

void ImgProcessor::showList(int index)
{
    QTextCursor cursor = showWidget->textEdit->textCursor();
    if(index!=0)
    {
        QTextListFormat::Style style = QTextListFormat::ListDisc;
        switch(index)
        {
        case 1:
            style = QTextListFormat::ListDisc;
            break;
        case 2:
            style = QTextListFormat::ListCircle;
            break;
        case 3:
            style = QTextListFormat::ListSquare;
            break;
        case 4:
            style = QTextListFormat::ListDecimal;
            break;
        case 5:
            style = QTextListFormat::ListLowerAlpha;
            break;
        case 6:
            style = QTextListFormat::ListUpperAlpha;
            break;
        case 7:
            style = QTextListFormat::ListLowerRoman;
            break;
        case 8:
            style = QTextListFormat::ListLowerRoman;
            break;
        default:
            break;

        }
        //设置缩进值
        cursor.beginEditBlock();
        QTextBlockFormat blockFmt = cursor.blockFormat();
        QTextListFormat listFmt;
        if(cursor.currentList())
        {
            listFmt = cursor.currentList()->format();
        }
        else
        {
            listFmt.setIndent(blockFmt.indent()+1);
            blockFmt.setIndent(0);
            cursor.setBlockFormat(blockFmt);
        }
        listFmt.setStyle(style);
        cursor.createList(listFmt);
        cursor.endEditBlock();
    }
    else
    {
        QTextBlockFormat bfmt;
        bfmt.setObjectIndex(-1);
        cursor.mergeBlockFormat(bfmt);
    }
}

void ImgProcessor::showAlignment(QAction *act)
{
    if(act == leftAction)
        showWidget->textEdit->setAlignment(Qt::AlignLeft);
    else if(act == rightAction)
        showWidget->textEdit->setAlignment(Qt::AlignRight);
    else if(act == centerAction)
        showWidget->textEdit->setAlignment(Qt::AlignCenter);
    else if(act == justifyAction)
        showWidget->textEdit->setAlignment(Qt::AlignJustify);
}

void ImgProcessor::showCursorPositionChanged()
{
    if(showWidget->textEdit->alignment() == Qt::AlignLeft)
        leftAction->setChecked(true);
    else if(showWidget->textEdit->alignment() == Qt::AlignRight)
        rightAction->setChecked(true);
    else if(showWidget->textEdit->alignment() == Qt::AlignCenter)
        centerAction->setChecked(true);
    else if(showWidget->textEdit->alignment() == Qt::AlignJustify)
        justifyAction->setChecked(true);
}











