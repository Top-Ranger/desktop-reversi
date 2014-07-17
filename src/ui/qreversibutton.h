#ifndef QREVERSIBUTTON_H
#define QREVERSIBUTTON_H

#include <QPushButton>

class QReversiButton : public QPushButton
{
    Q_OBJECT
public:
    explicit QReversiButton(QWidget *parent = 0);
    explicit QReversiButton(int x, int y, QWidget *parent = 0);

signals:
    void clicked(int x, int y);

public slots:

private slots:
    void getClicked();

private:
    int _x;
    int _y;


};

#endif // QREVERSIBUTTON_H
