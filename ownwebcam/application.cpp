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
#include "application.h"


application::application() { //initalzing the flow of the application using a construtor
	isRecording = false;
	isDetecting = false;
	init();

}

application::~application() {
	reset();
	cout << "application reset" << endl;
}

void application::init() {
	cam = make_shared<VideoCapture>(0);
	if (!cam->isOpened()) {
		cerr << "Error in opening the camera" << endl;
		exit(1);
	}
	namedWindow("webcam", WINDOW_FREERATIO);
	cout << "camera initaialized" << endl;
	processFrame();

}

void application::reset() {
	if (cam->isOpened()) {
		cam->release();
	}
	destroyAllWindows;
	init();
}

void application::processFrame() {
	while (true) {
		if (!cam->read(frame)) {
			cout << "No frames read" << endl;
		}

		if (isRecording) {
			recorder.writeFrame(frame);
		}
		if (isDetecting) {
			int circles = detect.detectCircles(frame);
			cout << "detected circles:" << circles << endl;
		}

		key = waitKey(1);
		outputPath = "C:\\output\\output.avi";
		imshow("webcam", frame);


		if (key == 'r') {
			isRecording = !isRecording;
			if (isRecording) {
				recorder.startRecording(outputPath);
				cout << "recording Started" << endl;
			}
			else {
				recorder.stopRecording();
				cout << "recorder stopped" << endl;
			}
		}
		else if (key == 'd') {
			isDetecting = !isDetecting;
			if (isDetecting) {
				cout << "Detection started" << endl;
			}
			else {
				cout << "Detection stopped" << endl;

			}
		}
		else if (key == ' ') {
			break;
		}

	}
}
