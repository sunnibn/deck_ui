#include <string>

#include "playerwindow.h"
#include "ui_playerwindow.h"

#include <QPushButton>


PlayerWindow::PlayerWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PlayerWindow)
{
    ui->setupUi(this);
}

PlayerWindow::~PlayerWindow()
{
    delete ui;
}

void PlayerWindow::setTitle(std::string file_name) {
    this->setWindowTitle(QString(file_name.c_str()));
}

void PlayerWindow::on_playButton_clicked()
{
    extern bool PLAY;
    if (PLAY) {
        PLAY = false;
        ui->playButton->setStyleSheet("border-image: url(:assets/icon_play_64.png);");
    } else {
        PLAY = true;
        ui->playButton->setStyleSheet("border-image: url(:assets/icon_pause_64.png);");
    }
}

