#include <iostream>

#include "screenwidget.h"
#include "ui_screenwidget.h"

#include <QVBoxLayout>

#include "ui/musicplayerwidget.h"
#include "ui/musicfilesystemwidget.h"

ScreenWidget::ScreenWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ScreenWidget)
{
    ui->setupUi(this);
    ui->widget->setStyleSheet("border: 1px solid lightgray; background: black;");
    bar = new ScreenBar(this);
    ui->gridLayout->addWidget(bar, 0,0,1,1, Qt::AlignBottom);

    screenResizable(false);
}

ScreenWidget::ScreenWidget(int displayNo, int x, int y, int w, int h, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ScreenWidget)
{
    ui->setupUi(this);
    ui->widget->setStyleSheet("border: 1px solid lightgray; background: black;");
    this->move(x, y);
    this->resize(w, h);
    bar = new ScreenBar(this);
    ui->gridLayout->addWidget(bar, 0,0,1,1, Qt::AlignBottom);

    screenDisplay(displayNo);
    screenResizable(false);
}

ScreenWidget::~ScreenWidget()
{
    delete ui;
}

//=== screen display functions

void ScreenWidget::screenResizable(bool enable) {
    if (enable) {
        // this->setWindowFlags(Qt::SubWindow);
        bar->show();
    } else {
        // this->setWindowFlags(Qt::Widget);
        bar->hide();
    }
}

void ScreenWidget::screenDisplay(int displayNo) {
    switch (displayNo) {
    case MUSIC_PLAYER_1:
        ui->widget->layout()->addWidget(new MusicPlayerWidget);
        break;
    case MUSIC_LIST_1:
        ui->widget->layout()->addWidget(new MusicFileSystemWidget);
        break;
    }
}
