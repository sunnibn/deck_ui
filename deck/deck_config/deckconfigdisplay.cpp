#include "deckconfigdisplay.h"
#include "ui_deckconfigdisplay.h"

DeckConfigDisplay::DeckConfigDisplay(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DeckConfigDisplay)
{
    ui->setupUi(this);
    this->setStyleSheet("border: 1px solid lightgray; background: black;");
    this->move(0,0);
    this->resize(100,100);

    bar = new DeckConfigDisplayBar(this);
    ui->gridLayout->addWidget(bar, 0,0,1,1, Qt::AlignBottom);
}

DeckConfigDisplay::DeckConfigDisplay(DisplayData d, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DeckConfigDisplay)
{
    ui->setupUi(this);
    this->setStyleSheet("border: 1px solid lightgray; background: black;");
    this->move(d.x, d.y);
    this->resize(d.w, d.h);
    setDisplayContent(0);

    bar = new DeckConfigDisplayBar(this);
    ui->gridLayout->addWidget(bar, 0,0,1,1, Qt::AlignBottom);
}

DeckConfigDisplay::~DeckConfigDisplay()
{
    delete ui;
}



//=== config display setup function
void DeckConfigDisplay::setDisplayContent(int displayNo) {
    switch (displayNo) {
    case 0:
        this->layout()->addWidget(new MusicPlayerWidget);
        break;
    case 1:
        this->layout()->addWidget(new MusicFileSystemWidget);
        break;
    }
}
