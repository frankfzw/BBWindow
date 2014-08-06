#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>

#include "socket.h"

namespace Ui {
class MainWindow;
}

class VlcInstance;
class VlcMedia;
class VlcMediaPlayer;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void openLocal();
    void openUrl();
    void setCarAddr();

    void cameraDown();
    void cameraUp();
    void cameraLeft();
    void cameraRight();
    void carLeft();
    void carRight();
    void carForward();
    void carBack();
    void cameraDownRelease();
    void cameraUpRelease();
    void cameraLeftRelease();
    void cameraRightRelease();
    void carLeftRelease();
    void carRightRelease();
    void carForwardRelease();
    void carBackRelease();

protected:
    void keyPressEvent(QKeyEvent *e);

private:
    Ui::MainWindow *ui;

    VlcInstance *_instance;
    VlcMedia *_media;
    VlcMediaPlayer *_player;

    //socket
    MsgSender *sender;
};

#endif // MAINWINDOW_H
