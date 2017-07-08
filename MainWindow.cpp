#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <iostream>
#include <QMessageBox>
#include <opencv2/opencv.hpp>
#include "SystemConfiguration.h"

using namespace cv;
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // create a new system configuration object
    SystemConfiguration config;
    // load the settings to system configuration
    config.loadSettings();

    ui->setupUi(this);
    configWindow = NULL;
}

void MainWindow::startAutoMode(int devId)
{
    ui->inputCameraId->setDisabled(true);
    cameraId = devId;
    // initialize the capture device
    captureDevice = VideoCapture(cameraId);

    // check if the device is accessable
    if(!captureDevice.isOpened())
    {
        // create a new message box
        QMessageBox messageBox(this);
        // show warning message
        messageBox.warning(this,"Warning","Can not open Camera Device",QMessageBox::Ok);
        // return from this function as capture device is not correct
        return;
    }

    // every thing is ok, start capturing
    startProcessing();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startBtn_clicked()
{
    // read the camera id
    cameraId = ui->inputCameraId->value();

    // initialize the capture device
    captureDevice = VideoCapture(cameraId);

    // check if the device is accessable
    if(!captureDevice.isOpened())
    {
        // create a new message box
        QMessageBox messageBox(this);
        // show warning message
        messageBox.warning(this,"Warning","Can not open Camera Device",QMessageBox::Ok);
        // return from this function as capture device is not correct
        return;
    }

    // every thing is ok, start capturing
    startProcessing();
}

void MainWindow::updateCameraFeedDisplay(QImage img1, QImage img2, QImage img3, QImage img4)
{
    // display all the received images
    ui->displayCameraFeed->setPixmap(QPixmap::fromImage(img1).scaled(ui->displayCameraFeed->width(), ui->displayCameraFeed->height()));
    ui->displayProcessedFrame->setPixmap(QPixmap::fromImage(img2).scaled(ui->displayProcessedFrame->width(), ui->displayProcessedFrame->height()));
    ui->displayDetectedPoints->setPixmap(QPixmap::fromImage(img3).scaled(ui->displayDetectedPoints->width(), ui->displayDetectedPoints->height()));
    ui->displayOutPut->setPixmap(QPixmap::fromImage(img4).scaled(ui->displayOutPut->width(), ui->displayOutPut->height()));
}


void MainWindow::startProcessing()
{
    // disable start brn
    ui->startBtn->setEnabled(false);
    // create a new camera capture object
    cameraCapture = new CameraCapture(captureDevice);
    // connect the signal to receive images
    connect(cameraCapture,SIGNAL(capturedNewFrame(QImage,QImage,QImage,QImage)),this,SLOT(updateCameraFeedDisplay(QImage,QImage,QImage,QImage)));
    // start capturing process
    cameraCapture->start();
}

void MainWindow::on_btn_configure_clicked()
{
    // check if configuration window is already not initilized
    if(!configWindow)
    {
        // create a new config window
        configWindow = new ConfigurationWindow();
    }
    // show the config wondow
    configWindow->show();
    // activate the window
    configWindow->raise();
    configWindow->activateWindow();
}
