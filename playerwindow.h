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
    void durChange(qint64 duration);
    void posChange(qint64 position);

    void on_playButton_clicked();

    void on_fileButton_clicked();

    void on_volUpBtn_clicked();

    void on_volDownBtn_clicked();

    void on_playSlider_valueChanged(int value);
    void on_playSlider_sliderPressed();
    void on_playSlider_sliderMoved(int value);
    void on_playSlider_sliderReleased();

    void on_secPrvBtn_clicked();

    void on_secNxtBtn_clicked();

private:
    Ui::PlayerWindow *ui;
    QPixmap iconDefault;

    QMediaPlayer *mPlayer;
    QAudioOutput *audioOutput;

    float audioVolume;

    qint64 mDuration;
};
#endif // PLAYERWINDOW_H
