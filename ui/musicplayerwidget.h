#ifndef MUSICPLAYERWIDGET_H
#define MUSICPLAYERWIDGET_H

#include <QWidget>

namespace Ui {
class MusicPlayerWidget;
}

class MusicPlayerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MusicPlayerWidget(QWidget *parent = nullptr);
    ~MusicPlayerWidget();

private slots:
    void mediaChange();
    void durChange(qint64 duration);
    void posChange(qint64 position);

    void on_playSlider_valueChanged(int value);

    void on_fileButton_clicked();

    void on_playButton_clicked();
    void on_secPrevButton_clicked();
    void on_secNextButton_clicked();
    void on_prevButton_clicked();
    void on_nextButton_clicked();

private:
    Ui::MusicPlayerWidget *ui;
};

#endif // MUSICPLAYERWIDGET_H
