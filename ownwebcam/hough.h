/*Name:Hough header file
* Author:SP
* Date:4-7-24
* The plot is to create the header file to access the hough transform function
*/

#ifndef HOUGH_H
#define HOUGH_H

#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/opencv.hpp" 

using namespace std;
using namespace cv;

class houghVideo {
public:
	int detectCircles(Mat& frame);
};

#endif // HOUGH 
