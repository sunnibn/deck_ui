#include <iostream>

#include "deckbar.h"
#include "ui_deckbar.h"

#include "data/decksetting.h"

extern DeckSetting DECK_CONF;

DeckBar::DeckBar(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DeckBar)
{
    ui->setupUi(this);
    this->setStyleSheet("background: black; border: 1px solid lightgray; color: lightgray;");
    basicMode();
}

DeckBar::~DeckBar()
{
    delete ui;
}

//=== bar mode functions
void DeckBar::emptyBar() {
    if (!ui->widget->layout()->isEmpty()) {
        std::cout << "emptying.." << std::endl;
        QLayoutItem *child;
        while ((child = ui->widget->layout()->takeAt(0)) != nullptr) {
            delete child->widget();
        }
    }
}
void DeckBar::basicMode() {
    // empty the bar contents
    this->emptyBar();
    // fill in bar contents
    QSpacerItem *spacer = new QSpacerItem(0,0, QSizePolicy::Expanding, QSizePolicy::Minimum);
    ui->widget->layout()->addItem(spacer);
    QPushButton *btn = new QPushButton(this);
    btn->setText("Edit");

    connect(btn, &QPushButton::clicked, [this](){ DECK_CONF.deckConfigWrite(); this->editMode(); });

    ui->widget->layout()->addWidget(btn);
}
void DeckBar::editMode() {
    // empty the bar contents
    this->emptyBar();
    // fill in bar contents
    QSpacerItem *spacer = new QSpacerItem(0,0, QSizePolicy::Expanding, QSizePolicy::Minimum);
    ui->widget->layout()->addItem(spacer);
    QPushButton *btn = new QPushButton(this);
    btn->setText("Done");

    connect(btn, &QPushButton::clicked, [this](){ DECK_CONF.deckConfigWrite(); this->basicMode(); });

    ui->widget->layout()->addWidget(btn);
}

//=== button click functions
