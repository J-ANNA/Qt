#include "editdialog.h"
#include <QMessageBox>

int uniqueCarId;
int uniqueFactoryId;

EditDialog::EditDialog(QSqlRelationalTableModel *cars,QSqlTableModel *factory,QDomDocument details,
                       QFile *output,QWidget *parent) :QDialog(parent)
{
    carModel = cars;
    factoryModel = factory;
    carDetails = details;
    outputFile = output;
    QGroupBox *inputWidgetBox = createInputWidgets();
    QDialogButtonBox *buttonBox = createButtons();

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(inputWidgetBox);
    layout->addWidget(buttonBox);
    setLayout(layout);
    setWindowTitle(tr("添加产品"));

}

void EditDialog::revert()
{
    factoryLineEdit->clear();
    addressLineEdit->clear();
    carLineEdit->clear();
    yearSpinBox->setValue(QDate::currentDate().year());
    attribLineEdit->clear();
}

void EditDialog::submit()
{
    QString factory = factoryLineEdit->text();
    QString address = addressLineEdit->text();
    QString name = carLineEdit->text();
    if(factory.isEmpty() || address.isEmpty() || name.isEmpty())
    {
        QString message(tr("请输入厂名、厂址和商品名称！"));
        QMessageBox::information(this,tr("添加产品"),message);
    }
    else
    {
        int factoryId = findFactoryId(factory);
        if(factoryId == -1)                              //录入的制造商不存在，新增制造商
        {
            factoryId = addNewFactory(factory,address);
        }
        int carId = addNewCar(name,factoryId);           //在汽车表中新增一条记录
        QStringList attribs;
        attribs = attribLineEdit->text().split(";",QString::SkipEmptyParts); //以分号为分隔符，跳过空白项，将string分割成stringlist
        addAttribs(carId,attribs);                       //将录入的车型信息写入XML文件中
        accept();
    }
}

int EditDialog::addNewCar(const QString &name, int factoryId)
{
    int id = generateCarId();   //生成一个汽车表的主键值
    QSqlRecord record;
    /*在汽车表中插入一条新纪录*/
    QSqlField f1("carid",QVariant::Int);
    QSqlField f2("name",QVariant::String);
    QSqlField f3("factoryid",QVariant::Int);
    QSqlField f4("year",QVariant::Int);
    f1.setValue(QVariant(id));
    f2.setValue(QVariant(name));
    f3.setValue(QVariant(factoryId));
    f4.setValue(QVariant(yearSpinBox->value()));
    record.append(f1);
    record.append(f2);
    record.append(f3);
    record.append(f4);
    carModel->insertRecord(-1,record);
    return id;
}

int EditDialog::addNewFactory(const QString &factory, const QString &address)
{
    QSqlRecord record;
    int id = generateFactoryId();      //生成一个汽车制作商表的主键值 （return uniqueFactoryId++）
    /*在汽车制造商表中插入一条新纪录，厂名和地址有参数传入*/
    QSqlField f1("id",QVariant::Int);
    QSqlField f2("manufactory",QVariant::String);
    QSqlField f3("address",QVariant::String);
    f1.setValue(QVariant(id));
    f2.setValue(QVariant(factory));
    f3.setValue(QVariant(address));
    record.append(f1);
    record.append(f2);
    record.append(f3);
    factoryModel->insertRecord(-1,record);   //-1(negative),插入最后
    return id;

}

void EditDialog::addAttribs(int carId, QStringList attribs)
{
    /*创建一个car标签*/
    QDomElement carNode = carDetails.createElement("car");
    carNode.setAttribute("id",carId);
    for(int i = 0; i<attribs.count(); i++)
    {
        QString attribNumber = QString::number(i+1);
        if(i < 10)
        {
            attribNumber.prepend("0");  //"01"
        }
        QDomText textNode = carDetails.createTextNode(attribs.at(i));
        QDomElement attribNode = carDetails.createElement("attrib");
        attribNode.setAttribute("number",attribNumber);
        attribNode.appendChild(textNode);
        carNode.appendChild(attribNode);
     }
    QDomNodeList archive = carDetails.elementsByTagName("archive");
    archive.item(0).appendChild(carNode);                //0:添加到最后
    if(!outputFile->open(QIODevice::WriteOnly))
    {
        return;
    }
    else
    {
        QTextStream stream(outputFile);
        archive.item(0).save(stream,4);      //缩进4个空格
        outputFile->close();
    }
}

QDialogButtonBox *EditDialog::createButtons()
{
    QPushButton *closeBtn = new QPushButton(tr("关闭"));
    QPushButton *revertBtn = new QPushButton(tr("撤销"));
    QPushButton *submitBtn = new QPushButton(tr("提交"));
    closeBtn->setDefault(true);         //设置默认按钮
    connect(closeBtn,SIGNAL(clicked()),this,SLOT(close()));
    connect(revertBtn,SIGNAL(clicked()),this,SLOT(revert()));
    connect(submitBtn,SIGNAL(clicked()),this,SLOT(submit()));

    QDialogButtonBox *buttonBox = new QDialogButtonBox;
    buttonBox->addButton(submitBtn,QDialogButtonBox::ResetRole);
    buttonBox->addButton(revertBtn,QDialogButtonBox::ResetRole);
    buttonBox->addButton(closeBtn,QDialogButtonBox::ResetRole);
    return buttonBox;

}

QGroupBox *EditDialog::createInputWidgets()
{
    QGroupBox *box = new QGroupBox(tr("添加产品"));
    QLabel *factoryLabel = new QLabel(tr("制造商："));
    QLabel *addressLabel = new QLabel(tr("厂址："));
    QLabel *carLabel = new QLabel(tr("品牌"));
    QLabel *yearLabel = new QLabel(tr("上市时间："));
    QLabel *attribLabel = new QLabel(tr("产品属性（由分号；隔开）："));
    factoryLineEdit = new QLineEdit;
    carLineEdit = new QLineEdit;
    addressLineEdit = new QLineEdit;
    yearSpinBox = new QSpinBox;
    yearSpinBox->setMinimum(1990);
    yearSpinBox->setMaximum(QDate::currentDate().year());
    yearSpinBox->setValue(yearSpinBox->maximum());
    yearSpinBox->setReadOnly(false);
    attribLineEdit = new QLineEdit;
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(factoryLabel,0,0);
    layout->addWidget(factoryLineEdit,0,1);
    layout->addWidget(addressLabel,1,0);
    layout->addWidget(addressLineEdit,1,1);
    layout->addWidget(carLabel,2,0);
    layout->addWidget(carLineEdit,2,1);
    layout->addWidget(yearLabel,3,0);
    layout->addWidget(yearSpinBox,3,1);
    layout->addWidget(attribLabel,4,0,1,2);
    layout->addWidget(attribLineEdit,5,0,1,2);
    box->setLayout(layout);
    return box;
}

int EditDialog::findFactoryId(const QString &factory)
{
    int row = 0;
    while(row < factoryModel->rowCount())
    {
        QSqlRecord record = factoryModel->record(row);
        if(record.value("manufactory") == factory)
        {
            return record.value("id").toInt();
        }
        else
            row++;
    }
    return -1;    //如果未查询到则返回"-1"
}

int EditDialog::generateCarId()
{
    uniqueCarId += 1;
    return uniqueCarId;
}

int EditDialog::generateFactoryId()
{
    uniqueFactoryId += 1;
    return uniqueFactoryId;
}






