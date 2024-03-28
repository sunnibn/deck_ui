#include <iostream>
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

void MusicPlayer::loadMeta() {
    // std::cout << "load" <<std::endl;
    QMediaMetaData metaData = mPlayer->metaData();
    std::cout<< metaData.keys().size() <<std::endl;
    for(int i=0; i<metaData.keys().size(); i++) {
        QMediaMetaData::Key mKey = metaData.keys().at(i);
        QString sKey = QMediaMetaData::metaDataKeyToString(mKey);
        QVariant mDat = metaData[mKey];

        qDebug() << mKey << mDat.toString();
        std::cout << sKey.toStdString() << " " << std::endl;
    }
}
