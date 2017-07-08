#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H
#include <opencv2/opencv.hpp>
#include "PointerManager.h"
#include "MousePointerManager.h"
#include <QDesktopWidget>
#include <QRect>
#include "rocket.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#define PI 3.14159
#include "bullet.h"
using namespace cv;

class ImageProcessor
{
private:
    // contains final points after filter process for current frame
    vector<Point> finalPoints;
    // contains number of frames for which double click gesture has been made
    int framesWithDoubleClickActivationCounter;
    // contains number of frames for which double click gesture has not been made
    int framesWithDoubleClickDeactivationCounter;
    // contains number of frames for which click gesture has been made
    int framesWithClickActivationCounter;
    // contains number of frames for which click gesture has not been made
    int framesWithClickDeactivationCounter;
    // contains number of frames for which mouse down gesture has been made
    int framesWithMouseDownActivationCounter;
    // contains number of frames for which mouse down gesture has not been made
    int framesWithMouseDownDeactivationCounter;
    // contains number of frames for which right click gesture has been made
    int framesWithRightClickActivationCounter;
    // contains number of frames for which right click gesture has not been made
    int framesWithRightClickDeactivationCounter;
    // contains number of frames for which mouse events reset is requested
    int framesWithResetCounter;
    // indicates if mouse button is down
    bool isMouseDown;
    // indicates if mouse click is activated
    bool isClickActivated;
    // indicates if mouse right click is activated
    bool isRightClickActivated;
    // indicates if mouse double click is activated
    bool isDoubleClickActivated;
    // desktop widget to get desktop screen size
    QDesktopWidget widget;
    // pointer manager object
    PointerManager pointerManager;
    // mouse manager object
    MousePointerManager mouseManager;
    // eleminates convex defects by its dimention and provides filtered defects
    vector<Vec4i> eleminateDefectsByDimentation(vector<Vec4i>,vector<Point>);
    // eleminates convex defects by its bounding box height region
    vector<Vec4i> eleminateDefectsByregion(vector<Vec4i>,vector<Point>, Rect);
    // calculates distance between two given point
    float distanceP2P(Point, Point);
    // calculates angle between line (p1,p2) and line (p2,p3)
    float getAngle(Point, Point, Point);
    // eleminates redundent defects that are too close to each other
    vector<Point> removeRedundantEndPoints(vector<Vec4i>,vector<Point>);
    // find one finger which is not detected by convex defects
    Point findTopPoint(vector<Point> contours, Point);
    // represents the bounding rectangle of the largest contour
    Rect boundingRectect;

public:
    // constructor of this class
    ImageProcessor();
    // does preprocessing of the image and then detection/ elemination of points
    vector<Mat> getprocessedImage(Mat);
    // generates the output image based on the processed data
    Mat getOutputImage();
    // get the filtered skin image
    Mat getSkin(Mat);
    // generate mouse event based on the current data
    void generateMouseEvents();
    QGraphicsView *view;
    QGraphicsScene *scene;
    Rocket *rocket= new Rocket();
    Bullet *bullet;
};

#endif // IMAGEPROCESSOR_H
