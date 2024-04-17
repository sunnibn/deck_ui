#ifndef SCREENBAR_H
#define SCREENBAR_H

#include <QWidget>
#include <QEvent>
#include <QMouseEvent>
#include <data/decksetting.h>

extern DeckSetting CONFIG;

namespace Ui {
class ScreenBar;
}

class ScreenBar : public QWidget
{
    Q_OBJECT

public:
    explicit ScreenBar(QWidget *parent = nullptr);
    ~ScreenBar();

    int screenIdx;
    int displayIdx;

protected:
    bool eventFilter(QObject *o, QEvent *e);

private slots:
    void on_removeButton_clicked();
    void on_settingButton_clicked();

private:
    Ui::ScreenBar *ui;

    int pw, ph, px, py, x, y;
};

#endif // SCREENBAR_H
