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
    //ui->setupUi(this);

    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos)
        m_serialPortComboBox->addItem(info.portName());

    m_serialPortComboBox->setFocus();

    ui->setupUi(this);
    //connect(ui->FFTButton,SIGNAL(clicked()),this,SLOT(showNewWindow()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ConnectButton_clicked()
{
    qDebug()	<<	"on_ConnectButton_clicked";
    ui->ConnectButton->setText("DISCONNECT");
}


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

