#include "musicplayerwidget.h"
#include "ui_musicplayerwidget.h"

#include "musicplayer.h"

#include <QFileDialog>
#include <QtMultimedia/QtMultimedia>

extern MusicPlayer MP;

MusicPlayerWidget::MusicPlayerWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MusicPlayerWidget)
{
    ui->setupUi(this);

    // init title
    ui->titleLabel->setText("-");
    // init bar
    connect(MP.mPlayer, &QMediaPlayer::durationChanged, this, &MusicPlayerWidget::durChange);
    connect(MP.mPlayer, &QMediaPlayer::positionChanged, this, &MusicPlayerWidget::posChange);
}

MusicPlayerWidget::~MusicPlayerWidget()
{
    delete ui;
}

//=== slider change functions

void MusicPlayerWidget::durChange(qint64 duration) {    // music player duration change -> affect slider, label.
    qint64 dur = duration/1000;
    if (dur) {
        QTime totalTime((dur/3600)%60, (dur/60)%60, dur%60, (dur*1000)%1000);
        ui->t2Label->setText(totalTime.toString("mm:ss"));
        ui->playSlider->setRange(0, dur);
    }
}
void MusicPlayerWidget::posChange(qint64 position) {    // music player position change -> affect slider.
    qint64 dur = position/1000;
    if (dur) {
        QTime currentTime((dur/3600)%60, (dur/60)%60, dur%60, (dur*1000)%1000);
        ui->t1Label->setText(currentTime.toString("mm:ss"));
        ui->playSlider->setValue(dur);
    }
}

//=== slider functions

void MusicPlayerWidget::on_playSlider_valueChanged(int value) {
    MP.mPlayer->setPosition(value * 1000);   // continuous pausing while changing.
}

//=== temp file dialog function

void MusicPlayerWidget::on_fileButton_clicked() {
    QString path = QFileDialog::getOpenFileName(this, tr("Select to play"), "", tr("MP3 (*.mp3)"));
    MP.loadMusic(path);
    ui->titleLabel->setText(MP.mFile.fileName());
}

//=== button slots functions

void MusicPlayerWidget::on_playButton_clicked() {
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
void MusicPlayerWidget::on_secPrevButton_clicked() {
    MP.mPlayer->setPosition(MP.mPlayer->position() - 5000);
}
void MusicPlayerWidget::on_secNextButton_clicked() {
    MP.mPlayer->setPosition(MP.mPlayer->position() + 5000);
}
void MusicPlayerWidget::on_prevButton_clicked() {

}
void MusicPlayerWidget::on_nextButton_clicked() {

}
