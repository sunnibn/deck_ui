#include "deckconfigbar.h"
#include "ui_deckconfigbar.h"

#include <iostream>

DeckConfigBar::DeckConfigBar(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DeckConfigBar)
{
    ui->setupUi(this);
    this->setStyleSheet("background: black; border: 1px solid lightgray; color: lightgray;");
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
    if (!ui->midWidget->layout()->isEmpty()) {
        QLayoutItem *child;
        while ((child = ui->midWidget->layout()->takeAt(0)) != nullptr) {
            child->widget()->setParent(nullptr);
            delete child->widget();
            delete child;
        }
    }
    // fill in screens btn
    for (int i=0; i < CONFIG.screens.size(); i++) {
        QPushButton *btn = new QPushButton(".");
        connect(btn, &QPushButton::clicked, [i](){ CONFIG.switchScreen(i); });
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
