#include "clickslider.h"

#include <QMouseEvent>

ClickSlider::ClickSlider(QWidget *parent)
    : QSlider(parent)
{

}

ClickSlider::~ClickSlider()
{

}

void ClickSlider::mousePressEvent(QMouseEvent *ev) {
    if (ev->button() == Qt::LeftButton) {
        if (orientation() == Qt::Horizontal)
            setValue( minimum() + (maximum()-minimum()) * ev->x() / width() );
        ev->accept();
    }
    QSlider::mousePressEvent(ev);
}
