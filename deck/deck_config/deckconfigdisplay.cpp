#include "deckconfigdisplay.h"
#include "ui_deckconfigdisplay.h"

DeckConfigDisplay::DeckConfigDisplay(int displayIdx, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DeckConfigDisplay)
{
    ui->setupUi(this);
    this->setStyleSheet("border: 1px solid lightgray; background: black;");
    this->move(0,0);
    this->resize(100,100);

    this->displayIdx = displayIdx;

    bar = new DeckConfigDisplayBar(this->displayIdx, this);
    ui->gridLayout->addWidget(bar, 0,0,1,1, Qt::AlignBottom);
}

DeckConfigDisplay::DeckConfigDisplay(int displayIdx, DisplayData d, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DeckConfigDisplay)
{
    ui->setupUi(this);
    this->setStyleSheet("border: 1px solid lightgray; background: black;");
    this->move(d.x, d.y);
    this->resize(d.w, d.h);
    setDisplayContent(0);

    this->displayIdx = displayIdx;

    bar = new DeckConfigDisplayBar(this->displayIdx, this);
    ui->gridLayout->addWidget(bar, 0,0,1,1, Qt::AlignBottom);
}

DeckConfigDisplay::~DeckConfigDisplay()
{
    delete ui;
}



//=== config display setup function
void DeckConfigDisplay::setDisplayContent(int displayType) {
    switch (displayType) {
    case 0:
        this->layout()->addWidget(new MusicPlayerWidget);
        break;
    case 1:
        this->layout()->addWidget(new MusicFileSystemWidget);
        break;
    }
}
