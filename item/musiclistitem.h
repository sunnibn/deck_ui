#ifndef MUSICLISTITEM_H
#define MUSICLISTITEM_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class MusicListItem;
}

class MusicListItem : public QPushButton
{
    Q_OBJECT

public:
    explicit MusicListItem(QPushButton *parent = nullptr);
    ~MusicListItem();

    void setItem(QString path);

private slots:
    void on_MusicListItem_clicked();

private:
    Ui::MusicListItem *ui;

    bool pressFlag = false;
};

#endif // MUSICLISTITEM_H
