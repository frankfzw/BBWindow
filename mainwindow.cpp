#include <QFileDialog>
#include <QInputDialog>

#include <vlc-qt/Common.h>
#include <vlc-qt/Instance.h>
#include <vlc-qt/Media.h>
#include <vlc-qt/MediaPlayer.h>

#include <mutex>
#include <windows.h>

#include "mainwindow.h"
#include "ui_mainwindow.h"

std::mutex cameraDownLock, cameraUpLock, cameraLeftLock, cameraRightLock;
std::mutex carForwardLock, carBackLock, carLeftLock, carRightLock;

bool cameraDownFlag, cameraUpFlag, cameraLeftFlag, cameraRightFlag;
bool carForwardFlag, carBackFlag, carLeftFlag, carRightFlag;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //init flags
    cameraDownFlag = false;
    cameraUpFlag = false;
    cameraLeftFlag = false;
    cameraRightFlag = false;
    carForwardFlag = false;
    carBackFlag = false;
    carLeftFlag = false;
    carRightFlag = false;

    ui->setupUi(this);

    _instance = new VlcInstance(VlcCommon::args(), this);
    _player = new VlcMediaPlayer(_instance);
    _player->setVideoWidget(ui->video);

    ui->video->setMediaPlayer(_player);

    connect(ui->actionOpen_Local_File, SIGNAL(triggered()), this, SLOT(openLocal()));
    connect(ui->actionOpen_URL, SIGNAL(triggered()), this, SLOT(openUrl()));
    connect(ui->actionCar_Address, SIGNAL(triggered()), this, SLOT(setCarAddr()));

    connect(ui->cameraDown, SIGNAL(pressed()), this, SLOT(cameraDown()));
    connect(ui->cameraUp, SIGNAL(pressed()), this, SLOT(cameraUp()));
    connect(ui->cameraLeft, SIGNAL(pressed()), this, SLOT(cameraLeft()));
    connect(ui->cameraRight, SIGNAL(pressed()), this, SLOT(cameraRight()));
    connect(ui->carForward, SIGNAL(pressed()), this, SLOT(carForward()));
    connect(ui->carBack, SIGNAL(pressed()), this, SLOT(carBack()));
    connect(ui->carLeft, SIGNAL(pressed()), this, SLOT(carLeft()));
    connect(ui->carRight, SIGNAL(pressed()), this, SLOT(carRight()));
    connect(ui->cameraDown, SIGNAL(released()), this, SLOT(cameraDownRelease()));
    connect(ui->cameraUp, SIGNAL(released()), this, SLOT(cameraUpRelease()));
    connect(ui->cameraLeft, SIGNAL(released()), this, SLOT(cameraLeftRelease()));
    connect(ui->cameraRight, SIGNAL(released()), this, SLOT(cameraRightRelease()));
    connect(ui->carForward, SIGNAL(released()), this, SLOT(carForwardRelease()));
    connect(ui->carBack, SIGNAL(released()), this, SLOT(carBackRelease()));
    connect(ui->carLeft, SIGNAL(released()), this, SLOT(carLeftRelease()));
    connect(ui->carRight, SIGNAL(released()), this, SLOT(carRightRelease()));



    sender = new MsgSender();


}

MainWindow::~MainWindow()
{
    delete ui;

    delete _instance;
    delete _player;
    delete _media;

    delete sender;
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

void MainWindow::setCarAddr()
{
    QString url =
            QInputDialog::getText(this, tr("Open Url"), tr("Enter the IP of your car"));
    QString port =
            QInputDialog::getText(this, tr("Port"), tr("Enter the port of your car"));

    if (url.isEmpty() || port.isEmpty())
        return;

    QString content = "Car IP: \n";
    content.append(url);
    content.append(":");
    content.append(port);
    ui->ipLabel->setText(content);

    //bind socket
    sender->clear();
    sender->bindSocket(url.toStdString(), port.toInt());
}

void MainWindow::cameraDown()
{
    /*
    cameraDownLock.lock();
    cameraDownFlag = true;
    cameraDownLock.unlock();

    while (cameraDownFlag)
    {
        //add action here
        Sleep(100);
    }
    */
    sender->sendMessage(CAMERADOWN);

}

void MainWindow::cameraUp()
{
    /*
    cameraUpLock.lock();
    cameraUpFlag = true;
    cameraUpLock.unlock();

    while (cameraUpFlag)
    {
        //add action here
        Sleep(100);
    }
    */
    sender->sendMessage(CAMERAUP);
}

void MainWindow::cameraLeft()
{
    /*
    cameraLeftLock.lock();
    cameraLeftFlag = true;
    cameraLeftLock.unlock();

    while (cameraLeftFlag)
    {
        //add action here
        Sleep(100);
    }
    */
    sender->sendMessage(CAMERALEFT);
}

void MainWindow::cameraRight()
{
    /*
    cameraRightLock.lock();
    cameraRightFlag = true;
    cameraRightLock.unlock();

    while (cameraRightFlag)
    {
        //add action here
        Sleep(100);
    }
    */
    sender->sendMessage(CAMERARIGHT);
}

void MainWindow::carForward()
{
    /*
    carForwardLock.lock();
    carForwardFlag = true;
    carForwardLock.unlock();

    while (carForwardFlag)
    {
        //add action here
        Sleep(100);
    }
    */
    sender->sendMessage(CARFORWARD);
}

void MainWindow::carBack()
{
    /*
    carBackLock.lock();
    carBackFlag = true;
    carBackLock.unlock();

    while (carBackFlag)
    {
        //add action here
        Sleep(100);
    }
    */
    sender->sendMessage(CARBACK);
}

void MainWindow::carLeft()
{
    /*
    carLeftLock.lock();
    carLeftFlag = true;
    carLeftLock.unlock();

    while (carLeftFlag)
    {
        //add action here
        Sleep(100);
    }
    */
    sender->sendMessage(CARLEFT);
}

void MainWindow::carRight()
{
    /*
    carRightLock.lock();
    carRightFlag = true;
    carRightLock.unlock();

    while (carRightFlag)
    {
        //add action here
        Sleep(100);
    }
    */
    sender->sendMessage(CARRIGHT);
}

void MainWindow::cameraDownRelease()
{
    /*
    cameraDownLock.lock();
    cameraDownFlag = false;
    cameraDownLock.unlock();
    */
}

void MainWindow::cameraUpRelease()
{
    /*
    cameraUpLock.lock();
    cameraUpFlag = false;
    cameraUpLock.unlock();
    */
}

void MainWindow::cameraLeftRelease()
{
    /*
    cameraLeftLock.lock();
    cameraLeftFlag = false;
    cameraLeftLock.unlock();
    */
}

void MainWindow::cameraRightRelease()
{
    /*
    cameraRightLock.lock();
    cameraRightFlag = false;
    cameraRightLock.unlock();
    */
}

void MainWindow::carForwardRelease()
{
    /*
    carForwardLock.lock();
    carForwardFlag = false;
    carForwardLock.unlock();
    */
}

void MainWindow::carBackRelease()
{
    /*
    carBackLock.lock();
    carBackFlag = false;
    carBackLock.unlock();
    */
}

void MainWindow::carLeftRelease()
{
    /*
    carLeftLock.lock();
    carLeftFlag = false;
    carLeftLock.unlock();
    */
}

void MainWindow::carRightRelease()
{
    /*
    carRightLock.lock();
    carRightFlag = false;
    carRightLock.unlock();
    */
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    switch (e->key())
    {
    case Qt::Key_W:
        carForward();
        break;
    case Qt::Key_A:
        carLeft();
        break;
    case Qt::Key_S:
        carBack();
        break;
    case Qt::Key_D:
        carRight();
        break;
    case Qt::Key_I:
        cameraUp();
        break;
    case Qt::Key_K:
        cameraDown();
        break;
    case Qt::Key_J:
        cameraLeft();
        break;
    case Qt::Key_L:
        cameraRight();
        break;
    }
}

