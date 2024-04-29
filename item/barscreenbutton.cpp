#include "barscreenbutton.h"
#include "ui_barscreenbutton.h"

BarScreenButton::BarScreenButton(QWidget *parent)
    : QPushButton(parent)
    , ui(new Ui::BarScreenButton)
{
    ui->setupUi(this);

    this->inactiveText = "QPushButton { margin: 10px; \
        background: black; \
        border: 1px solid lightgray; \
        max-width: 20px; max-height: 20px; \
        border-radius: 9px; }";
    this->activeText = "QPushButton { margin: 10px; \
        background: lightgray; \
        border: 1px solid lightgray; \
        max-width: 20px; max-height: 20px; \
        border-radius: 9px; }";
    this->hoverText = "QPushButton:hover:!pressed { background: gray; }";
    this->pressText = "QPushButton:pressed { background: dimgray; }";

    this->active = false;
    this->setStyleSheet(inactiveText + hoverText + pressText);
}

BarScreenButton::~BarScreenButton()
{
    delete ui;
}



void BarScreenButton::switchActive(bool active) {
    this->active = active;
    if (active) {
        this->setStyleSheet(activeText + hoverText + pressText);
    } else {
        this->setStyleSheet(inactiveText + hoverText + pressText);
    }
}
