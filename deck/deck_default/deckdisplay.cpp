#include "deckdisplay.h"
#include "ui_deckdisplay.h"

#include <iostream>

DeckDisplay::DeckDisplay(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DeckDisplay)
{
    ui->setupUi(this);
    this->setStyleSheet("border: 1px solid lightgray; background: black;");
    this->move(0,0);
    this->resize(100,100);
}

DeckDisplay::DeckDisplay(DisplayData d, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DeckDisplay)
{
    ui->setupUi(this);
    this->setStyleSheet("border: 1px solid lightgray; background: black;");
    this->move(d.x, d.y);
    this->resize(d.w, d.h);
    setDisplayContent(0);
}

DeckDisplay::~DeckDisplay()
{
    delete ui;
}



//=== display setup function
void DeckDisplay::setDisplayContent(int displayNo) {
    switch (displayNo) {
    case 0:
        this->layout()->addWidget(new MusicPlayerWidget);
        break;
    case 1:
        this->layout()->addWidget(new MusicFileSystemWidget);
        break;
    }
}
