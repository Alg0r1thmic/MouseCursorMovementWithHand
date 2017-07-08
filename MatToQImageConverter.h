#ifndef MATTOQIMAGECONVERTER_H
#define MATTOQIMAGECONVERTER_H

#include <opencv2/opencv.hpp>
#include <QImage>

using namespace cv;

// a function to convert OpenCV Mat object to QT QImage
QImage convertMatToQImage(Mat);


#endif // MATTOQIMAGECONVERTER_H
