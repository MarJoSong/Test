#include "widget.h"
#include "ui_widget.h"
#include <QDataStream>
#include <QMessageBox>
#include <QDateTime>
#include <QColorDialog>
#include <QFileDialog>

Widget::Widget(QWidget *parent, QString name) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    udpSocket = new QUdpSocket(this);
    this->uName = name;
    this->port = 9999;

    udpSocket->bind(this->port, QUdpSocket::ShareAddress|QUdpSocket::ReuseAddressHint);
    //sndMsg(UsrEnter);

    connect(ui->pushButtonSend, &QPushButton::clicked, [=](){
        sndMsg(Msg);
    });

    connect(udpSocket, &QUdpSocket::readyRead, this, &Widget::ReceiveMessage);

    connect(ui->pushButtonExit, &QPushButton::clicked, this, [=](){
        this->close();
    });

    connect(ui->fontComboBox, &QFontComboBox::currentFontChanged,[=](const QFont &font){
       ui->textEditMsg->setCurrentFont(font);
       ui->textEditMsg->setFontPointSize(ui->comboBoxFontSize->currentText().toInt());
       ui->textEditMsg->setFocus();
    });

    void (QComboBox::*signalFontChanged)(const QString &text) = &QComboBox::currentIndexChanged;
    connect(ui->comboBoxFontSize, signalFontChanged,[=](const QString &text){
       ui->textEditMsg->setFontPointSize(text.toInt());
       ui->textEditMsg->setFocus();
    });

    connect(ui->toolButtonBold, &QToolButton::clicked, [=](bool isChecked){
       if(isChecked)
       {
           ui->textEditMsg->setFontWeight(QFont::Bold);
       }
       else
       {
           ui->textEditMsg->setFontWeight(QFont::Normal);
       }
    });

    connect(ui->toolButtonItalic, &QToolButton::clicked, [=](bool isChecked){
       ui->textEditMsg->setFontItalic(isChecked);
    });

    connect(ui->toolButtonUnderline, &QToolButton::clicked, [=](bool isChecked){
       ui->textEditMsg->setFontUnderline(isChecked);
    });

    connect(ui->toolButtonColor, &QToolButton::clicked,[=](){
        QColor color = QColorDialog::getColor(Qt::red);
        ui->textEditMsg->setTextColor(color);
    });

    connect(ui->toolButtonClear, &QToolButton::clicked, [=](){
        ui->textBrowserMsg->clear();
    });

    connect(ui->toolButtonSave, &QToolButton::clicked, [=](){
        if(ui->textBrowserMsg->document()->isEmpty())
        {
            QMessageBox::warning(this, "警告", "保存内容不能为空");
        }
        else
        {
            QString path = QFileDialog::getSaveFileName(this, "保存文件", "C:\\Users\\Public\\Documents");
            QFile file(path);
            file.open(QIODevice::WriteOnly | QIODevice::Text);
            QTextStream stream(&file);
            stream << ui->textBrowserMsg->toPlainText();
            file.close();
        }
    });

    sndMsg(UsrEnter);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::closeEvent(QCloseEvent *e)
{
    emit this->widgetClose();
    sndMsg(UsrLeft);
    udpSocket->close();
    udpSocket->destroyed();
    QWidget::closeEvent(e);
}

void Widget::sndMsg(Widget::MsgType type)
{
    QByteArray array;
    QDataStream stream(&array, QIODevice::WriteOnly);

    stream << type << getUsr();
    switch (type) {
    case Msg:
        if(ui->textEditMsg->toPlainText()=="")
        {
            QMessageBox::warning(this, "警告", "发送内容不能为空!");
            return;
        }
        stream << getMsg();
        break;
    case UsrEnter:
        break;
    case UsrLeft:
        break;
    }

    udpSocket->writeDatagram(array, QHostAddress::Broadcast, port);
}

void Widget::usrEnter(QString username)
{
    bool isEmpty = ui->tableWidgetusr->findItems(username,Qt::MatchExactly).isEmpty();
    if(isEmpty)
    {
        QTableWidgetItem* usr = new QTableWidgetItem(username);

        ui->tableWidgetusr->insertRow(0);
        ui->tableWidgetusr->setItem(0,0,usr);

        ui->textBrowserMsg->setTextColor(Qt::gray);
        ui->textBrowserMsg->append(QString("%1 上线了").arg(username));

        ui->labelUserNum->setText(QString("在线用户：%1人").arg(ui->tableWidgetusr->rowCount()));

        sndMsg(UsrEnter);
    }
}

void Widget::usrLeft(QString usrname, QString time)
{
    bool isEmpty = ui->tableWidgetusr->findItems(usrname,Qt::MatchExactly).isEmpty();
    if(!isEmpty)
    {
        int row = ui->tableWidgetusr->findItems(usrname,Qt::MatchExactly).first()->row();

        ui->tableWidgetusr->removeRow(row);

        ui->textBrowserMsg->setTextColor(Qt::gray);
        ui->textBrowserMsg->append(QString("%1 于 %2 离开").arg(usrname).arg(time));

        ui->labelUserNum->setText(QString("在线用户：%1人").arg(ui->tableWidgetusr->rowCount()));
    }
}

QString Widget::getUsr()
{
    return this->uName;
}

QString Widget::getMsg()
{
    QString str = ui->textEditMsg->toHtml();
    ui->textEditMsg->clear();
    ui->textEditMsg->setFocus();

    return str;
}

void Widget::ReceiveMessage()
{
    qint64 size = udpSocket->pendingDatagramSize();
    QByteArray array = QByteArray(static_cast<int>(size), 0);
    udpSocket->readDatagram(array.data(), size);

    QDataStream stream(&array, QIODevice::ReadOnly);
    int msgType;
    QString usrName;
    QString msg;
    stream >> msgType;

    QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");

    switch (msgType) {
    case Msg:
        stream >> usrName >> msg;

        ui->textBrowserMsg->setTextColor(Qt::blue);
        ui->textBrowserMsg->append("["+ usrName + "] " + time);
        ui->textBrowserMsg->append(msg);
        break;

    case UsrEnter:
        stream >> usrName;
        usrEnter(usrName);
        break;

    case UsrLeft:
        stream >> usrName;
        usrLeft(usrName, time);
        break;
    }
}
