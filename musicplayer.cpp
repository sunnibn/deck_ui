#include "musicplayer.h"

MusicPlayer::MusicPlayer() {
    mPlayer = new QMediaPlayer();
    audioOutput = new QAudioOutput();

    audioVolume = audioOutput->volume();
}

MusicPlayer::~MusicPlayer() {

}

void MusicPlayer::loadMusic(QString path) {
    // get file
    mFile = QFileInfo(path);
    // set play
    mPlayer->setAudioOutput(audioOutput);
    mPlayer->setSource(QUrl::fromLocalFile(mFile.filePath()));
}
