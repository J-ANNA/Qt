#include "langswitch.h"
#include <QVBoxLayout>
#include <QTranslator>
#include <QApplication>
#include <QDebug>

LangSwitch::LangSwitch(QWidget *parent)
    : QDialog(parent)
{
    createScreen();
}

LangSwitch::~LangSwitch()
{

}

void LangSwitch::changeLang(int index)
{
    QString langCode = comboBox->itemData(index).toString();
    changeTr(langCode);   //读取相应的".qm"文件
    refreshLabel();
    qDebug()<<langCode<<endl;

}

void LangSwitch::createScreen()
{
    comboBox = new QComboBox;
    comboBox->addItem("English","en");
    comboBox->addItem("Chinese","zh");
    comboBox->addItem("Latin","la");
    label = new QLabel;
    refreshLabel();
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(comboBox,1);
    layout->addWidget(label,5);
    setLayout(layout);
    connect(comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(changeLang(int)));

}

void LangSwitch::changeTr(const QString &LangCode)
{
    static QTranslator *translator;
    if(translator != NULL)
    {
        qApp->removeTranslator(translator);
        delete translator;
        translator = NULL;
    }
    translator = new QTranslator;
    QString qmFilename = "lang_" + LangCode;
    if(translator->load(QString("D:/QtStudy/LangSwitch/") + qmFilename + ".qm"))   //.qm 可加可不加
    {
        qApp->installTranslator(translator);
    }
}

void LangSwitch::refreshLabel()
{
    label->setText(tr("TXT_HELLO_WORLD","hello world"));  //1:提取翻译串时用到的ID； 2：注释作用，并且在取不到翻译串时注释串会被采用
}
