#ifndef SCREENWIDGET_H
#define SCREENWIDGET_H

#include <QWidget>
#include <QSizeGrip>
// #include <QEvent>
#include <QMouseEvent>
#include <QPushButton>

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
    explicit ScreenWidget(int displayNo, QWidget *parent = nullptr);
    ~ScreenWidget();

    void screenResizable(bool enable);
    void screenDisplay(int displayNum);

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private:
    Ui::ScreenWidget *ui;

    int pw, ph, px, py, x, y;
    // QSizeGrip *grip;
    QPushButton *btn;
};

#endif // SCREENWIDGET_H
