#include "clickslider.h"
#include "ui_clickslider.h"

ClickSlider::ClickSlider(QWidget *parent)
    : QSlider(parent)
    , ui(new Ui::ClickSlider)
{
    ui->setupUi(this);
}

ClickSlider::~ClickSlider()
{
    delete ui;
}

void ClickSlider::mousePressEvent(QMouseEvent *ev) {
    if (ev->button() == Qt::LeftButton) {
        if (orientation() == Qt::Horizontal)
            setValue( minimum() + (maximum()-minimum()) * ev->x() / width() );
        ev->accept();
    }
    QSlider::mousePressEvent(ev);
}
