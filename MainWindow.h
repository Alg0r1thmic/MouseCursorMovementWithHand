#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include <QThread>
#include <QImage>
#include "CameraCapture.h"
#include "ConfigurationWindow.h"
#include <QProcess>

using namespace cv;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    void startAutoMode(int devId);
    ~MainWindow();
    
private slots:
    // a slot to receive start button click signal
    void on_startBtn_clicked();
    // slot to receive all the images for display
    void updateCameraFeedDisplay(QImage, QImage, QImage, QImage);
    // slot to receive configure button click signal
    void on_btn_configure_clicked();

private:
    Ui::MainWindow *ui;
    // id of the camera to be used
    int cameraId;
    // device for geting camera feed
    VideoCapture captureDevice;
    // function to start processing
    void startProcessing();
    // camera capture object
    CameraCapture *cameraCapture;
    // config window object
    ConfigurationWindow *configWindow;
};

#endif // MAINWINDOW_H
