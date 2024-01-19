#include <string>
#include <iostream> //

#include "playerwindow.h"
#include "ui_playerwindow.h"

#include <QPushButton>
#include <QFileDialog>
#include <QtMultimedia/QtMultimedia>


PlayerWindow::PlayerWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PlayerWindow)
{
    ui->setupUi(this);

    // init icon
    iconDefault.load(":/assets/icon_def_music_64.png");
    int w = ui->iconLbl->width();
    int h = ui->iconLbl->height();
    ui->iconLbl->setPixmap(iconDefault.scaled(w, h, Qt::KeepAspectRatio));
    // init title
    ui->titleLbl->setText("Not selected");

    // init media player
    mPlayer = new QMediaPlayer();
    audioOutput = new QAudioOutput();

    // init volume icon
    iconDefault.load(":/assets/icon_sound_64.png");
    w = ui->volIconLbl->width();
    h = ui->volIconLbl->height();
    ui->volIconLbl->setPixmap(iconDefault.scaled(w, h, Qt::KeepAspectRatio));
    // init volume
    audioVolume = audioOutput->volume();
    audioOutput->setVolume(audioVolume);
    ui->volNumLbl->setText(QString::number(int(audioVolume*100)));
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
        mPlayer->pause();
        ui->playButton->setStyleSheet("image: url(:assets/icon_play_64.png);");
    } else {
        PLAY = true;
        mPlayer->play();
        ui->playButton->setStyleSheet("image: url(:assets/icon_pause_64.png);");
    }
}


void PlayerWindow::on_fileButton_clicked()
{
    //extern std::string FILE;
    //extern std::string FILENAME;
    QString FilePath = QFileDialog::getOpenFileName(this, tr("Select to play"), "", tr("MP3 (*.mp3)"));
    QFileInfo FileInfo(FilePath);
    // set playing...
    ui->titleLbl->setText(FileInfo.fileName());
    mPlayer->setAudioOutput(audioOutput);
    mPlayer->setSource(QUrl::fromLocalFile(FileInfo.filePath()));
}


void PlayerWindow::on_volUpBtn_clicked()
{
    if (audioVolume < 1.0) {
        audioVolume += 0.01;
        audioOutput->setVolume(audioVolume);
        ui->volNumLbl->setText(QString::number(int(audioVolume*100)));
    }
}


void PlayerWindow::on_volDownBtn_clicked()
{
    if (audioVolume > 0.0) {
        audioVolume -= 0.01;
        audioOutput->setVolume(audioVolume);
        ui->volNumLbl->setText(QString::number(int(audioVolume*100)));
    }
}

