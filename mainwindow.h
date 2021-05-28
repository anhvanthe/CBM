#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QComboBox>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QSpinBox>

#include "fft.h"

#define PORT_OPEN 0
#define PORT_CLOSE 1


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ConnectButton_clicked();

    void on_StartButton_clicked();

    void on_FFTButton_clicked();

    //void on_ComBox_activated(const QString &arg1);

    //void on_PortComBox_activated(const QString &arg1);

private:
    uint32_t statePort = PORT_OPEN;
    QComboBox *m_serialPortComboBox = nullptr;
    QSerialPort *port = nullptr;



//    MasterThread m_thread;

private:
    Ui::MainWindow *ui;
    FFT *fft = new FFT();

};
#endif // MAINWINDOW_H
