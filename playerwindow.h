#ifndef PLAYERWINDOW_H
#define PLAYERWINDOW_H

#include <string>
#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class PlayerWindow;
}
QT_END_NAMESPACE

class PlayerWindow : public QMainWindow
{
    Q_OBJECT

public:
    PlayerWindow(QWidget *parent = nullptr);
    ~PlayerWindow();

    void setTitle(std::string);

private slots:
    void on_playButton_clicked();

private:
    Ui::PlayerWindow *ui;
};
#endif // PLAYERWINDOW_H
