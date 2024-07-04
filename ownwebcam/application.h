/*
* Name:Developing a application to access the webcam
* Author:SP
* Date:07.02.24
* 
* 1) Initiation of the webcam 
* 2) Processing:
*       Recording
*		Detecting
* 3) Post Processing:
*		Save the files and provdide the details
* 4) Closing the application
*		

*/

#include <iostream>
#include <memory>
#include "opencv2/opencv.hpp"
#include "hough.h"
#include "record.h"

using namespace std;
using namespace cv;

class application {

public:
	application();
	~application();
	Mat frame;
	char key;
	void init();
	void reset();
	void processFrame();
	string outputPath;


private:
	shared_ptr<VideoCapture> cam;
	bool isRecording;
	bool isDetecting;
	recordVideo recorder;
	houghVideo detect;

};


