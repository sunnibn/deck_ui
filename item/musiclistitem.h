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
    explicit MusicListItem(QWidget *parent = nullptr);
    explicit MusicListItem(QString name, QString icon, QWidget *parent = nullptr);
    ~MusicListItem();

    void setItemName(QString name);
    void setItemIcon(QString icon);

    void setItemStyle();

protected:
    bool eventFilter(QObject *o, QEvent *e);

private:
    Ui::MusicListItem *ui;

    int idx;
    QString name;
    QString icon;
    QString path;
};

#endif // MUSICLISTITEM_H
