#ifndef POINTERMANAGER_H
#define POINTERMANAGER_H
#include <QObject>
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
class PointerManager : public QObject
{
    Q_OBJECT
private:

    KalmanFilter kalmanFilter;
    Point currentPointer;
    Point previousPointer;
    Mat_<float> measurement;
    Point indexPoint;
    int framesWithoutPoints;
    bool isPointerActive;

public:
    PointerManager();
    void updateFrameData(vector<Point>);
    Point getTopMostPoint(vector<Point>);
    bool isInMagnetArea(Point, Point);
    bool isPointerAvailable();
    Point getActivePointer();
    Point getFilteredPointer();
};

#endif // POINTERMANAGER_H
