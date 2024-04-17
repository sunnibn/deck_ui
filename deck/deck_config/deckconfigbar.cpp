#include "deckconfigbar.h"
#include "ui_deckconfigbar.h"

#include <iostream>

DeckConfigBar::DeckConfigBar(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DeckConfigBar)
{
    ui->setupUi(this);
    this->setStyleSheet("background: black; border: 1px solid lightgray; color: lightgray;");
}

DeckConfigBar::~DeckConfigBar()
{
    delete ui;
}



//=== button slot functions
void DeckConfigBar::on_saveBtn_clicked() {

}
void DeckConfigBar::on_exitBtn_clicked() {
    emit userModeSignal();
}
void DeckConfigBar::on_addScreenBtn_clicked() {

}
void DeckConfigBar::on_delScreenBtn_clicked() {

}
void DeckConfigBar::on_addDisplayBtn_clicked() {

}
