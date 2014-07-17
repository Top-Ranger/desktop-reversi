#include "qreversibutton.h"

QReversiButton::QReversiButton(QWidget *parent) :
    QPushButton(parent),
    _x(-1),
    _y(-1)
{

}

QReversiButton::QReversiButton(int x, int y, QWidget *parent) :
    QPushButton(parent),
    _x(x),
    _y(y)
{
    QObject::connect(this,SIGNAL(clicked()), this, SLOT(getClicked()));
}

void QReversiButton::getClicked()
{
    emit clicked(_x,_y);
}
