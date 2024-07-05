
#include "hough.h"
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int houghVideo::detectCircles(Mat& frame) {
    Mat gray;
    cvtColor(frame, gray, COLOR_BGR2GRAY);
    medianBlur(gray, gray, 5);
    vector<Vec3f> circles;
    HoughCircles(gray, circles, HOUGH_GRADIENT, 1,
        gray.rows / 16, // change this value to detect circles with different distances to each other
        100, 30, 1, 30 // change the last two parameters
        // (min_radius & max_radius) to detect larger circles
    );
    for (size_t i = 0; i < circles.size(); i++)
    {
        Vec3i c = circles[i];
        Point center = Point(c[0], c[1]);
        // circle center
        circle(frame, center, 1, Scalar(0, 100, 100), 3, LINE_AA);
        // circle outline
        int radius = c[2];
        circle(frame, center, radius, Scalar(255, 100, 255), 3, LINE_AA);
    }

    return circles.size();
}



