#ifndef PLAYERWINDOW_H
#define PLAYERWINDOW_H

#include <string>
#include <QMainWindow>
#include <QPushButton>
#include <QtMultimedia/QtMultimedia>

QT_BEGIN_NAMESPACE
namespace Ui {
class PlayerWindow;
}
QT_END_NAMESPACE

class PlayerWindow : public QMainWindow
{
    Q_OBJECT

public:
    PlayerWindow(QWidget *parent = nullptr);
    ~PlayerWindow();

    void setTitle(std::string);

private slots:
    void on_playButton_clicked();

    void on_fileButton_clicked();

    void on_volUpBtn_clicked();

    void on_volDownBtn_clicked();

private:
    Ui::PlayerWindow *ui;
    QPixmap iconDefault;

    QMediaPlayer *mPlayer;
    QAudioOutput *audioOutput;
    float audioVolume;
};
#endif // PLAYERWINDOW_H
