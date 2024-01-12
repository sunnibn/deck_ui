#include "playerwindow.h"
#include "ui_playerwindow.h"
#include <string>
#include <QPushButton>

PlayerWindow::PlayerWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PlayerWindow)
{
    ui->setupUi(this);

    // button
    QPushButton *btn = this->findChild<QPushButton *>("playButton");
    QPixmap pixmap("../storage/musical-note.png");
    QIcon ButtonIcon(pixmap);
    btn->setIcon(ButtonIcon);
    btn->setIconSize(QSize(16,16));

}

PlayerWindow::~PlayerWindow()
{
    delete ui;
}

void PlayerWindow::setTitle(std::string file_name) {
    this->setWindowTitle(QString(file_name.c_str()));
}
