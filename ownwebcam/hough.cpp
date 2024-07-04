
#include "hough.h"
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

houghVideo::houghVideo() {

}

int houghVideo::detectCircles(Mat& frame) {
    Mat gray;
    cvtColor(frame, gray, COLOR_BGR2GRAY);
    GaussianBlur(gray, gray, Size(9, 9), 2, 2);

    vector<Vec3f> circles;
    HoughCircles(gray, circles, HOUGH_GRADIENT, 1, gray.rows / 8, 200, 100);

    for (size_t i = 0; i < circles.size(); i++) {
        Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
        int radius = cvRound(circles[i][2]);
        circle(frame, center, radius, Scalar(0, 255, 100), 2);
    }

    return circles.size();
}



