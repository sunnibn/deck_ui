#include <iostream>

#include "deckbar.h"
#include "ui_deckbar.h"

#include "data/decksetting.h"

extern DeckSetting CONFIG;
extern DeckSetting DECK_CONF;

DeckBar::DeckBar(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DeckBar)
{
    ui->setupUi(this);
    this->setStyleSheet("background: black; border: 1px solid lightgray; color: lightgray;");
    initDeckBar();
}

DeckBar::~DeckBar()
{
    delete ui;
}



//=== bar setting functions
void DeckBar::initDeckBar() {
    // bar elements
    QSpacerItem *spacer = new QSpacerItem(0,0, QSizePolicy::Expanding, QSizePolicy::Minimum);
    editBtn = new QPushButton("Edit");
    addScreenBtn = new QPushButton("New Screen");
    delScreenBtn = new QPushButton("Delete Screen");
    addDisplayBtn = new QPushButton("New Display");
    editSaveBtn = new QPushButton("Save");
    editQuitBtn = new QPushButton("Quit");
    // signal slot bar buttons
    connect(editBtn, &QPushButton::clicked, [this](){ this->editBtnClick(); });
    connect(addScreenBtn, &QPushButton::clicked, [this](){ this->addScreenBtnClick(); });
    connect(delScreenBtn, &QPushButton::clicked, [this](){ this->delScreenBtnClick(); });
    connect(addDisplayBtn, &QPushButton::clicked, [this](){ this->addDisplayBtnClick(); });
    connect(editSaveBtn, &QPushButton::clicked, [this](){ this->editSaveBtnClick(); });
    connect(editQuitBtn, &QPushButton::clicked, [this](){ this->editQuitBtnClick(); });
    // add in widgets
    ui->widget->layout()->addItem(spacer);
    ui->widget->layout()->addWidget(editBtn);
    ui->widget->layout()->addWidget(addScreenBtn);
    ui->widget->layout()->addWidget(delScreenBtn);
    ui->widget->layout()->addWidget(addDisplayBtn);
    ui->widget->layout()->addWidget(editSaveBtn);
    ui->widget->layout()->addWidget(editQuitBtn);
    editBtn->setVisible(true);
    addScreenBtn->setVisible(false);
    delScreenBtn->setVisible(false);
    addDisplayBtn->setVisible(false);
    editSaveBtn->setVisible(false);
    editQuitBtn->setVisible(false);
}
// void DeckBar::emptyBar() {
//     if (!ui->widget->layout()->isEmpty()) {
//         std::cout << "emptying.." << std::endl;
//         QLayoutItem *child;
//         while ((child = ui->widget->layout()->takeAt(0)) != nullptr) {
//             std::cout << 'r';
//             ui->widget->layout()->removeItem(child);
//             //delete child->widget();
//         }
//     }
// }

//=== bar buttons functions
void DeckBar::editBtnClick() {
    editBtn->setVisible(false);
    addScreenBtn->setVisible(true);
    delScreenBtn->setVisible(true);
    addDisplayBtn->setVisible(true);
    editSaveBtn->setVisible(true);
    editQuitBtn->setVisible(true);
}
void DeckBar::addScreenBtnClick() {
    CONFIG.addScreenData();
    ((DeckWindow*)this->parent()->parent())->renderScreen(0);
}
void DeckBar::delScreenBtnClick() {

}
void DeckBar::addDisplayBtnClick() {

}
void DeckBar::editSaveBtnClick() {

}
void DeckBar::editQuitBtnClick() {
    editBtn->setVisible(true);
    addScreenBtn->setVisible(false);
    delScreenBtn->setVisible(false);
    addDisplayBtn->setVisible(false);
    editSaveBtn->setVisible(false);
    editQuitBtn->setVisible(false);
}
