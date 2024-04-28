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
}

DeckBar::~DeckBar()
{
    delete ui;
}



//=== bar setting functions
void DeckBar::renderScreensBtn() {
    // empty midwidget
    if (!ui->midWidget->layout()->isEmpty()) {
        QLayoutItem *child;
        while ((child = ui->midWidget->layout()->takeAt(0)) != nullptr) {
            child->widget()->setParent(nullptr);
            delete child;
        }
    }
    // fill in screens btn
    for (int i=0; i < CONFIG.screens.size(); i++) {
        QPushButton *btn = new QPushButton(".");
        connect(btn, &QPushButton::clicked, [i](){ CONFIG.switchScreen(i); });
        ui->midWidget->layout()->addWidget(btn);
    }
}

//=== button slot functions
void DeckBar::on_editBtn_clicked() {
    emit editModeSignal();
}
