#ifndef FFT_H
#define FFT_H

#include <QMainWindow>

namespace Ui {
class FFT;
}

class FFT : public QMainWindow
{
    Q_OBJECT

public:
    explicit FFT(QWidget *parent = nullptr);
    ~FFT();

private:
    Ui::FFT *ui;
};

#endif // FFT_H
