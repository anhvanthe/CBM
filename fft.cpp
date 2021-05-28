#include "fft.h"
#include "ui_fft.h"

FFT::FFT(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FFT)
{
    ui->setupUi(this);
}

FFT::~FFT()
{
    delete ui;
}
