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

private:
    Ui::MusicPlayerWidget *ui;
};

#endif // MUSICPLAYERWIDGET_H
