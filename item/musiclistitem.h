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

    void setItem(QString path, QString name, QString icon, int idx);

public slots:
    void selectMusicSlot();
    void selectDirSlot();

private:
    Ui::MusicListItem *ui;

    int idx;
    QString name;
    QString icon;
    QString path;
};

#endif // MUSICLISTITEM_H
