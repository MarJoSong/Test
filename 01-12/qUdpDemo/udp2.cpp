#include "udp2.h"
#include "ui_udp2.h"

Udp2::Udp2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Udp2)
{
    ui->setupUi(this);
    
    ui->MyPort->setText("9999");
    ui->ToPort->setText("8888");
    ui->ToIP->setText("127.0.0.1");
    
    udp = new QUdpSocket(this);
    udp->bind(static_cast<quint16>(ui->MyPort->text().toInt()));
    connect(ui->pushButtonSend, &QPushButton::clicked, this, [=](){
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

Udp2::~Udp2()
{
    delete ui;
}
