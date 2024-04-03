#include <iostream>

#include "musiclistitem.h"
#include "ui_musiclistitem.h"

#include "data/musicplayer.h"

extern MusicPlayer MP;

MusicListItem::MusicListItem(QWidget *parent)
    : QPushButton(parent)
    , ui(new Ui::MusicListItem)
{
    ui->setupUi(this);
    this->setItemStyle();
}

MusicListItem::MusicListItem(QString name, QString icon, QWidget *parent)
    : QPushButton(parent)
    , ui(new Ui::MusicListItem)
{
    ui->setupUi(this);
    this->setItemStyle();
    this->setItemName(name);
    this->setItemIcon(icon);
}

MusicListItem::~MusicListItem()
{
    delete ui;
}

//=== setup music file item.

void MusicListItem::setItemName(QString name) {
    this->name = name;
    ui->titleLabel->setText(name);
}
void MusicListItem::setItemIcon(QString icon) {
    this->icon = icon;
}

//=== setup item style.

void MusicListItem::setItemStyle() {
    this->setStyleSheet("QPushButton#MusicListItem {height: 64; background: transparent; border: 1px solid lightgray; border-bottom: none;}"
                        "QPushButton#MusicListItem::hover {background: gray;}");
    ui->iconLabel->setStyleSheet("margin: 10; border: 1px solid lightgray;");
    ui->titleLabel->setStyleSheet("color: lightgray;");
}
