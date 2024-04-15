#ifndef SCREENWIDGET_H
#define SCREENWIDGET_H

#include <QWidget>
#include <QSizeGrip>
// #include <QEvent>
#include <QMouseEvent>
#include <QPushButton>

#include "deck/screenbar.h"

enum UiDisplay {
    MUSIC_PLAYER_1,
    MUSIC_LIST_1,
};

namespace Ui {
class ScreenWidget;
}

class ScreenWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ScreenWidget(QWidget *parent = nullptr);
    explicit ScreenWidget(int displayNo, int x, int y, int w, int h, QWidget *parent = nullptr);
    ~ScreenWidget();

    void screenResizable(bool enable);
    void screenDisplay(int displayNum);

private:
    Ui::ScreenWidget *ui;

    int pw, ph, px, py, x, y;
    ScreenBar *bar;
};

#endif // SCREENWIDGET_H
