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
}

DeckBar::~DeckBar()
{
    delete ui;
}



//=== bar setting functions
void DeckBar::renderScreensBtn() {
    // empty midwidget
    // if (!ui->midWidget->layout()->isEmpty()) {
    //     QLayoutItem *child;
    //     while ((child = ui->midWidget->layout()->takeAt(0)) != nullptr) {
    //         child->widget()->setParent(nullptr);
    //         delete child;
    //     }
    // }
    for (int i=0; i < BB.size(); i++) {
        BB[i]->setParent(nullptr);
        delete BB[i];
    }
    if (!BB.empty()) { BB.clear(); }
    // fill in screens btn
    for (int i=0; i < CONFIG.screens.size(); i++) {
        BarScreenButton *btn = new BarScreenButton(this);
        connect(btn, &QPushButton::clicked, [this, btn, i](){
            if (0 <= CONFIG.currScreenIdx && CONFIG.currScreenIdx < BB.size())
                this->BB[CONFIG.currScreenIdx]->switchActive(false);
            CONFIG.switchScreen(i);
            btn->switchActive(true);
        });
        BB.push_back(btn);
        ui->midWidget->layout()->addWidget(btn);
    }
}

//=== button slot functions
void DeckBar::on_editBtn_clicked() {
    emit editModeSignal();
}
