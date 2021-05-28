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
    int m_transactionCount = 0;
//    QLabel *m_serialPortLabel = nullptr;
    QComboBox *m_serialPortComboBox = nullptr;
//    QLabel *m_waitResponseLabel = nullptr;
//    QSpinBox *m_waitResponseSpinBox = nullptr;
//    QLabel *m_requestLabel = nullptr;
//    QLineEdit *m_requestLineEdit = nullptr;
//    QLabel *m_trafficLabel = nullptr;
//    QLabel *m_statusLabel = nullptr;
//    QPushButton *m_runButton = nullptr;

//    MasterThread m_thread;

private:
    Ui::MainWindow *ui;
    FFT *fft = new FFT();

};
#endif // MAINWINDOW_H
