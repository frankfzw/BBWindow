#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void cameraDown();
    void cameraUp();
    void cameraLeft();
    void cameraRight();
    void carLeft();
    void carRight();
    void carForward();
    void carBack();



private:
    Ui::MainWindow *ui;

    VlcInstance *_instance;
    VlcMedia *_media;
    VlcMediaPlayer *_player;
};

#endif // MAINWINDOW_H
