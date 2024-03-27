#ifndef MUSICFILESYSTEMWIDGET_H
#define MUSICFILESYSTEMWIDGET_H

#include <QWidget>

namespace Ui {
class MusicFileSystemWidget;
}

class MusicFileSystemWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MusicFileSystemWidget(QWidget *parent = nullptr);
    ~MusicFileSystemWidget();

    void setDirectory(QString path);

private:
    Ui::MusicFileSystemWidget *ui;
};

#endif // MUSICFILESYSTEMWIDGET_H
