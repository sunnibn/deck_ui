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
    explicit MusicListItem(QString name, QString icon, QPushButton *parent = nullptr);
    ~MusicListItem();

    void setItemName(QString name);
    void setItemIcon(QString icon);

    void setItemStyle();

private:
    Ui::MusicListItem *ui;

    int idx;
    QString name;
    QString icon;
    QString path;
};

#endif // MUSICLISTITEM_H
