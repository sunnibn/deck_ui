#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QtMultimedia/QtMultimedia>
#include <QFileDialog>

class MusicPlayer
{
public:
    MusicPlayer();
    ~MusicPlayer();

    // player vars
    QMediaPlayer *mPlayer;

    QAudioOutput *audioOutput;
    float audioVolume;

    // current playing info/status vars
    QFileInfo mFile;
    bool playFlag = false;
    qint64 mDuration;

    // player directory & file lists vars
    QString dirPath;
    QStringList dirList;
    QStringList dirPathList;
    QStringList fileList;
    QStringList filePathList;
    QStringList iconList;

    int fileIdx;                // current music index. (in file list)
    QString defaultIcon = ":/assets/icon_def_music_64.png";     // default icon path.

    // loading funcs
    void loadMusic(QString path);
    void loadMeta();
    void loadList(QString path);
};

#endif // MUSICPLAYER_H
