#ifndef DECKCONFIGDISPLAYBAR_H
#define DECKCONFIGDISPLAYBAR_H

#include <QWidget>
#include <QEvent>
#include <QMouseEvent>

#include "data/decksetting.h"

extern DeckSetting CONFIG;

namespace Ui {
class DeckConfigDisplayBar;
}

class DeckConfigDisplayBar : public QWidget
{
    Q_OBJECT

public:
    explicit DeckConfigDisplayBar(int displayIdx, QWidget *parent = nullptr);
    ~DeckConfigDisplayBar();

    int displayIdx;
    bool settingFlag = false;

protected:
    bool eventFilter(QObject *o, QEvent *e);

private slots:
    void on_removeBtn_clicked();
    void on_settingBtn_clicked();

private:
    Ui::DeckConfigDisplayBar *ui;

    int pw, ph, px, py, x, y;
};

#endif // DECKCONFIGDISPLAYBAR_H
