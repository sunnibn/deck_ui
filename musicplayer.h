#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QtMultimedia/QtMultimedia>
#include <QFileDialog>

class MusicPlayer
{
public:
    MusicPlayer();
    ~MusicPlayer();

    // vars
    QMediaPlayer *mPlayer;
    qint64 mDuration;
    QFileInfo mFile;
    bool playFlag = false;

    QAudioOutput *audioOutput;
    float audioVolume;

    QString filePath;
    QString dirPath;
    QString iconPath = ":/assets/icon_def_music_64.png";

    // funcs
    void loadMusic(QString path);
};

#endif // MUSICPLAYER_H
