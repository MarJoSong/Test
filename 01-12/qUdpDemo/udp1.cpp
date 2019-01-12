#include "udp1.h"
#include "ui_udp1.h"

Udp1::Udp1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Udp1)
{
    ui->setupUi(this);
    
    ui->MyPort->setText("8888");
    ui->ToPort->setText("9999");
    ui->ToIP->setText("127.0.0.1");
    
    udp = new QUdpSocket(this);
    udp->bind(static_cast<quint16>(ui->MyPort->text().toInt()));
    connect(ui->pushButtonSend, &QPushButton::clicked, [=](){
        udp->writeDatagram(ui->input->toPlainText().toUtf8(),QHostAddress(ui->ToIP->text()),static_cast<quint16>(ui->ToPort->text().toInt()));
        ui->record->append("My Say: "+ui->input->toPlainText());
        ui->input->clear();
    });
    
    connect(udp, &QUdpSocket::readyRead, this, [=](){
        qint64 size = udp->pendingDatagramSize();
        QByteArray array = QByteArray(10000,0);
        udp->readDatagram(array.data(),size);
        
        ui->record->append("His Say: "+ array);
    });
}

Udp1::~Udp1()
{
    delete ui;
}
