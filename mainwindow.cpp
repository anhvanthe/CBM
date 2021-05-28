#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QTime>

#include "fft.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_serialPortComboBox(new QComboBox)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QList<QSerialPortInfo> listport = QSerialPortInfo::availablePorts();
        foreach (QSerialPortInfo port, listport) {
            ui->PortComBox->addItem(port.portName());
        }

//    const auto infos = QSerialPortInfo::availablePorts();
//    for (const QSerialPortInfo &info : infos)
//        m_serialPortComboBox->addItem(info.portName());

//    m_serialPortComboBox->setFocus();

   // ui->setupUi(this);
    //connect(ui->FFTButton,SIGNAL(clicked()),this,SLOT(showNewWindow()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ConnectButton_clicked()
{
    qDebug()	<<	"on_ConnectButton_clicked";
    //ui->ConnectButton->setText("CONNECT");
    //ui->ConnectButton->setStyleSheet("background-color: rgb(0, 255, 0)");		// G

    if (ui->ConnectButton->text() == "CONNECT")
        statePort = PORT_OPEN;
    if (ui->ConnectButton->text() == "DISCONNECT")
        statePort = PORT_CLOSE;


    if(statePort == PORT_OPEN)
    {
        port = new QSerialPort(this);
        port->setPortName(ui->PortComBox->currentText());
        port->setBaudRate(QSerialPort::Baud115200);
        port->setDataBits(QSerialPort::Data8);
        port->setFlowControl(QSerialPort::NoFlowControl);
        port->setParity(QSerialPort::NoParity);
        port->setStopBits(QSerialPort::OneStop);
        if (port->open(QIODevice::ReadWrite))
        {
            /* Change button string to connected */
            ui->ConnectButton->setText("DISCONNECT");
            /* Change color to red */
            ui->ConnectButton->setStyleSheet("border: none;background-color: rgb(255, 0, 0)");

            /* Change label to connected */
            //ui->setText("Connected");
            qDebug() << "Inside CONNECT LOOP";
            port->write("Ok\n");
        }

        if(statePort == PORT_CLOSE)
        {
            port->close();
            ui->ConnectButton->setText("CONNECT");
            ui->ConnectButton->setStyleSheet("background-color: rgb(0, 255, 0)");
            qDebug() << "Inside DISCONNECT LOOP";
        }

        //port->is
}


}

//background-color: rgb(255, 255, 127);

void MainWindow::on_StartButton_clicked()
{
    qDebug() <<	"on_StartButton_clicked";
    ui->StartButton->setText("STOP");
}


void MainWindow::on_FFTButton_clicked()
{
    qDebug() << "on_FFTButton_clicked";
    qDebug()	<<	"Show FFT window";
    fft->show();
}


//void MainWindow::on_ComBox_activated(const QString &arg1)
//{
//    const auto infos = QSerialPortInfo::availablePorts();
//    for (const QSerialPortInfo &info : infos)
//        m_serialPortComboBox->addItem(info.portName());
//}


//void MainWindow::on_PortComBox_activated(const QString &arg1)
//{
//    const auto infos = QSerialPortInfo::availablePorts();
//    for (const QSerialPortInfo &info : infos)
//    PortComBox->addItem(info.portName());
//}

