#ifndef DECKCONFIGBAR_H
#define DECKCONFIGBAR_H

#include <QWidget>
#include "data/decksetting.h"

extern DeckSetting CONFIG;

namespace Ui {
class DeckConfigBar;
}

class DeckConfigBar : public QWidget
{
    Q_OBJECT

public:
    explicit DeckConfigBar(QWidget *parent = nullptr);
    ~DeckConfigBar();

    void renderScreensBtn();

signals:
    void screenSwitchSignal(int screenIdx);
    void userModeSignal();

private slots:
    void on_saveBtn_clicked();
    void on_exitBtn_clicked();
    void on_addScreenBtn_clicked();
    void on_delScreenBtn_clicked();
    void on_addDisplayBtn_clicked();

private:
    Ui::DeckConfigBar *ui;
};

#endif // DECKCONFIGBAR_H
