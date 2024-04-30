#include <iostream>
#include "musicplayer.h"

MusicPlayer::MusicPlayer() {
    mPlayer = new QMediaPlayer();
    audioOutput = new QAudioOutput();

    audioVolume = audioOutput->volume();

    loadList("..");
}

MusicPlayer::~MusicPlayer() {

}

//=== loading functions

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

void MusicPlayer::loadList(QString path) {
    // get files & dirs from suggested path
    QDir directory(path);
    dirPath = directory.absolutePath();
    dirList = directory.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
    fileList = directory.entryList(QDir::Files);
    if (!dirPathList.isEmpty()) {dirPathList.clear();}
    foreach(QString dir, dirList) {
        dirPathList << directory.filePath(dir);
    }
    if (!filePathList.isEmpty()) {filePathList.clear();}
    foreach(QString file, fileList) {
        filePathList << directory.filePath(file);
    }
    if (!iconList.isEmpty()) {iconList.clear();}
    foreach(QString file, fileList) {   // for now, set as default icon for all.
        iconList << defaultIcon;
    }
}
