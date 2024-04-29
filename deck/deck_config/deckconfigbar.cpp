#include "deckconfigbar.h"
#include "ui_deckconfigbar.h"

#include <iostream>

DeckConfigBar::DeckConfigBar(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DeckConfigBar)
{
    ui->setupUi(this);
    connect(&CONFIG, &DeckSetting::renderBarSignal, [this](){
        this->renderScreensBtn();
    });

    renderScreensBtn();
}

DeckConfigBar::~DeckConfigBar()
{
    delete ui;
}



//=== bar setting function
void DeckConfigBar::renderScreensBtn() {
    // empty midwidget
    // if (!ui->midWidget->layout()->isEmpty()) {
    //     QLayoutItem *child;
    //     while ((child = ui->midWidget->layout()->takeAt(0)) != nullptr) {
    //         child->widget()->setParent(nullptr);
    //         delete child->widget();
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
        btn->show();
    }
}

//=== button slot functions
void DeckConfigBar::on_saveBtn_clicked() {

}
void DeckConfigBar::on_exitBtn_clicked() {
    emit userModeSignal();
}
void DeckConfigBar::on_addScreenBtn_clicked() {
    CONFIG.addScreenData();
}
void DeckConfigBar::on_delScreenBtn_clicked() {
    CONFIG.delScreenData(CONFIG.currScreenIdx);
}
void DeckConfigBar::on_addDisplayBtn_clicked() {
    CONFIG.addDisplayData(CONFIG.currScreenIdx);
}
