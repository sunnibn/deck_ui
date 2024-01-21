#include <string>
#include <iostream> //

#include "musicplayer.h"
#include "playerwindow.h"
#include "ui_playerwindow.h"
#include "clickslider.h"

#include <QPushButton>
#include <QFileDialog>
#include <QtMultimedia/QtMultimedia>

extern MusicPlayer MP;

PlayerWindow::PlayerWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PlayerWindow)
{
    ui->setupUi(this);

    // init player title & icon
    ui->titleLbl->setText("Not selected");
    ui->iconLbl->setScaledContents(true);

    // init player bar
    connect(MP.mPlayer, &QMediaPlayer::durationChanged, this, &PlayerWindow::durChange);
    connect(MP.mPlayer, &QMediaPlayer::positionChanged, this, &PlayerWindow::posChange);
    // ui->playSlider->setRange(0, MP.mPlayer->duration()/1000);

    // init volume icon
    // QPixmap icon;
    // icon.load(":/assets/icon_sound_64.png");
    // ui->volIconLbl->setPixmap(icon);
    // init volume & icon
    ui->volIconLbl->setScaledContents(true);
    ui->volNumLbl->setText(QString::number(int(MP.audioVolume*100)));
}

PlayerWindow::~PlayerWindow()
{
    delete ui;
}

void PlayerWindow::setTitle(std::string file_name) {
    this->setWindowTitle(QString(file_name.c_str()));
}
void PlayerWindow::setIcon(QString path) {
    QPixmap icon(path);
    ui->iconLbl->setPixmap(icon);
    ui->iconLbl->setScaledContents(true);
}
void PlayerWindow::durChange(qint64 duration) {     // player duration change -> slider, label
    qint64 dur = duration/1000;
    if (dur) {
        QTime totalTime((dur/3600)%60, (dur/60)%60, dur%60, (dur*1000)%1000);
        ui->time2Lbl->setText(totalTime.toString("mm:ss"));
        ui->playSlider->setRange(0, dur);
        // ui->playSlider->setMaximum(dur);
    }
}
void PlayerWindow::posChange(qint64 position) {     // player pos change -> player slider
    qint64 dur = position/1000;
    if (dur) {
        QTime currentTime((dur/3600)%60, (dur/60)%60, dur%60, (dur*1000)%1000);
        ui->time1Lbl->setText(currentTime.toString("mm:ss"));
        ui->playSlider->setValue(dur);
    }
}



void PlayerWindow::on_playButton_clicked()
{
    if (MP.playFlag) {
        MP.playFlag = false;
        MP.mPlayer->pause();
        ui->playButton->setStyleSheet("image: url(:assets/icon_play_64.png);");
    } else {
        MP.playFlag = true;
        MP.mPlayer->play();
        ui->playButton->setStyleSheet("image: url(:assets/icon_pause_64.png);");
    }
}


void PlayerWindow::on_fileButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, tr("Select to play"), "", tr("MP3 (*.mp3)"));
    // set playing...
    MP.loadMusic(path);
    ui->titleLbl->setText(MP.mFile.fileName());
}


void PlayerWindow::on_volUpBtn_clicked()
{
    // if (MP.audioVolume < 1.0) {
    //     MP.audioVolume += 0.01;
    //     MP.audioOutput->setVolume(audioVolume);
    //     ui->volNumLbl->setText(QString::number(int(audioVolume*100)));
    // }
}


void PlayerWindow::on_volDownBtn_clicked()
{
    // if (audioVolume > 0.0) {
    //     audioVolume -= 0.01;
    //     audioOutput->setVolume(audioVolume);
    //     ui->volNumLbl->setText(QString::number(int(audioVolume*100)));
    // }
}


void PlayerWindow::on_playSlider_valueChanged(int value)
{
    MP.mPlayer->setPosition(value * 1000); // continuous pausing
}
void PlayerWindow::on_playSlider_sliderPressed() {
    // std::cout << "pressed" << std::endl;
}
void PlayerWindow::on_playSlider_sliderMoved(int value) {
    // std::cout << value << " moved" << std::endl;
}
void PlayerWindow::on_playSlider_sliderReleased() {
    // std::cout << "released" << std::endl;
}


void PlayerWindow::on_secPrvBtn_clicked() {
    // ui->playSlider->setValue(ui->playSlider->value() - 5);
    // MP.mPlayer->setPosition(ui->playSlider->value() * 1000);
    MP.mPlayer->setPosition(MP.mPlayer->position() + 5000);
}
void PlayerWindow::on_secNxtBtn_clicked() {
    // ui->playSlider->setValue(ui->playSlider->value() + 5);
    // MP.mPlayer->setPosition(ui->playSlider->value() * 1000);
    MP.mPlayer->setPosition(MP.mPlayer->position() + 5000);
}

