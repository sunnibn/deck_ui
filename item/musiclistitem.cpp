#include <iostream>

#include "musiclistitem.h"
#include "ui_musiclistitem.h"

MusicListItem::MusicListItem(QPushButton *parent)
    : QPushButton(parent)
    , ui(new Ui::MusicListItem)
{
    ui->setupUi(this);
    // ui->this->setStyleSheet("");
}

MusicListItem::~MusicListItem()
{
    delete ui;
}

//=== setup music file item.

void MusicListItem::setItem(QString path) {
    ui->titleLabel->setText(path);
}

//=== click interaction

void MusicListItem::on_MusicListItem_clicked() {
    std::cout << "click" << std::endl;
}
