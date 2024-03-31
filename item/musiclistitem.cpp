#include <iostream>

#include "musiclistitem.h"
#include "ui_musiclistitem.h"

#include "data/musicplayer.h"

extern MusicPlayer MP;

MusicListItem::MusicListItem(QPushButton *parent)
    : QPushButton(parent)
    , ui(new Ui::MusicListItem)
{
    ui->setupUi(this);
    this->setStyleSheet("height: 64; background: transparent; border: 1px solid lightgray;");
    ui->iconLabel->setStyleSheet("");
    ui->titleLabel->setStyleSheet("color: lightgray;");
}

MusicListItem::~MusicListItem()
{
    delete ui;
}

//=== setup music file item.

void MusicListItem::setItem(QString path, QString name, QString icon, int idx) {
    this->idx = idx;
    this->path = path;
    this->name = name;
    this->icon = icon;
    ui->titleLabel->setText(name);
}

//=== slot functions
void MusicListItem::selectMusicSlot() {
    // std::cout << qPrintable(path) <<std::endl;
    MP.loadMusic(path);
    // release previous music (if there is)

    // hold new selected music
    MP.fileIdx = idx;
    std::cout << idx << std::endl;
}
void MusicListItem::selectDirSlot() {
    MP.loadList(path);
    std::cout << qPrintable(path) << std::endl;
}
