#include "deckdisplay.h"
#include "ui_deckdisplay.h"

#include <iostream>

DeckDisplay::DeckDisplay(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DeckDisplay)
{
    ui->setupUi(this);
    this->move(0,0);
    this->resize(100,100);
    ui->widget->setStyleSheet("QWidget#widget{ background: black; border: 1px solid lightgray; }");
}

DeckDisplay::DeckDisplay(DisplayData d, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DeckDisplay)
{
    ui->setupUi(this);
    this->move(d.x, d.y);
    this->resize(d.w, d.h);
    setDisplayContent(d.type);
    ui->widget->setStyleSheet("QWidget#widget{ background: black; border: 1px solid lightgray; }");
}

DeckDisplay::~DeckDisplay()
{
    delete ui;
}



//=== display setup function
void DeckDisplay::setDisplayContent(int displayType) {
    switch (displayType) {
    case 0:
        ui->widget->layout()->addWidget(new MusicPlayerWidget);
        break;
    case 1:
        ui->widget->layout()->addWidget(new MusicFileSystemWidget);
        break;
    }
}
