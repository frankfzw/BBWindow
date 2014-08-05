#include <QFileDialog>
#include <QInputDialog>

#include <vlc-qt/Common.h>
#include <vlc-qt/Instance.h>
#include <vlc-qt/Media.h>
#include <vlc-qt/MediaPlayer.h>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _instance = new VlcInstance(VlcCommon::args(), this);
    _player = new VlcMediaPlayer(_instance);
    _player->setVideoWidget(ui->video);

    ui->video->setMediaPlayer(_player);

    connect(ui->actionOpen_Local_File, SIGNAL(triggered()), this, SLOT(openLocal()));
    connect(ui->actionOpen_URL, SIGNAL(triggered()), this, SLOT(openUrl()));
    connect(ui->cameraDown, SIGNAL(pressed()), this, SLOT(cameraDown()));
    connect(ui->cameraUp, SIGNAL(pressed()), this, SLOT(cameraUp()));
    connect(ui->cameraLeft, SIGNAL(pressed()), this, SLOT(cameraLeft()));
    connect(ui->cameraRight, SIGNAL(pressed()), this, SLOT(cameraRight()));
    connect(ui->carForward, SIGNAL(pressed()), this, SLOT(carForward()));
    connect(ui->carBack, SIGNAL(pressed()), this, SLOT(carBack()));
    connect(ui->carLeft, SIGNAL(pressed()), this, SLOT(carLeft()));
    connect(ui->carRight, SIGNAL(pressed()), this, SLOT(carRight()));



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openLocal()
{
    QString file =
            QFileDialog::getOpenFileName(this, tr("Open file"),
                                         QDir::homePath(),
                                         tr("Multimedia files(*)"));

    if (file.isEmpty())
        return;

    _media = new VlcMedia(file, true, _instance);

    _player->open(_media);
}

void MainWindow::openUrl()
{
    QString url =
            QInputDialog::getText(this, tr("Open Url"), tr("Enter the URL you want to play"));

    if (url.isEmpty())
        return;

    _media = new VlcMedia(url, _instance);

    _player->open(_media);
}

void MainWindow::cameraDown()
{

}

void MainWindow::cameraUp()
{

}

void MainWindow::cameraLeft()
{

}

void MainWindow::cameraRight()
{

}

void MainWindow::carForward()
{

}

void MainWindow::carBack()
{

}

void MainWindow::carLeft()
{

}

void MainWindow::carRight()
{

}


