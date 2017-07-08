#ifndef CAMERACAPTURE_H
#define CAMERACAPTURE_H
#include <QThread>
#include <opencv2/opencv.hpp>
#include "ImageProcessor.h"
#include <QImage>

using namespace cv;

class CameraCapture: public QThread
{
    Q_OBJECT
public:
    CameraCapture(VideoCapture);

signals:
    void capturedNewFrame(QImage, QImage, QImage, QImage);

private:
    VideoCapture captureDevice;
    ImageProcessor processor;

protected:
    void run();
};


#endif // CAMERACAPTURE_H
