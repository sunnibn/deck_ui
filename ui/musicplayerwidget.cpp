#include "musicplayerwidget.h"
#include "ui_musicplayerwidget.h"

MusicPlayerWidget::MusicPlayerWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MusicPlayerWidget)
{
    ui->setupUi(this);
    this->setObjectName("MusicPlayerWidget");
    this->setStyleSheet("QWidget#MusicPlayerWidget{background: black;}");
}

MusicPlayerWidget::~MusicPlayerWidget()
{
    delete ui;
}
