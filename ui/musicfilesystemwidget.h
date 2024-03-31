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

    void setDirectory();

private slots:
    void on_backButton_clicked();

private:
    Ui::MusicFileSystemWidget *ui;

    void selectFile(int idx);
    void selectDirectory(int idx);
};

#endif // MUSICFILESYSTEMWIDGET_H
