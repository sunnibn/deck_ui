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

    this->installEventFilter(this);
}

MusicListItem::MusicListItem(QString name, QString icon, QWidget *parent)
    : QPushButton(parent)
    , ui(new Ui::MusicListItem)
{
    ui->setupUi(this);
    this->setItemName(name);
    this->setItemIcon(icon);
    this->setItemStyle();

    this->installEventFilter(this);
}

MusicListItem::~MusicListItem()
{
    delete ui;
}



//=== event filter
bool MusicListItem::eventFilter(QObject *o, QEvent *e) {
    if (e->type() == QEvent::HoverEnter) {
        this->setStyleSheet("height: 64; background: gray; border: 1px solid lightgray; border-bottom: none;");
    } else if (e->type() == QEvent::HoverLeave) {
        this->setStyleSheet("height: 64; background: transparent; border: 1px solid lightgray; border-bottom: none;");
    }
    return QWidget::eventFilter(o, e);
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
    this->setStyleSheet("height: 64; background: transparent; border: 1px solid lightgray; border-bottom: none;");
    ui->iconLabel->setStyleSheet("margin: 10; border: 1px solid lightgray;");
    ui->titleLabel->setStyleSheet("color: lightgray;");
    this->show();
}
