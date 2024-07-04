#include "record.h"
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

recordVideo::recordVideo(){

}

void recordVideo::startRecording(const string& outputPath ) {
	videoWriter.open(outputPath,VideoWriter::fourcc('M','J','P','G'),30, Size(640, 480), true);
	if (!videoWriter.isOpened())cout << "error in recording the video" << endl;
	return;
}

void recordVideo::stopRecording() {
	if (videoWriter.isOpened())videoWriter.release();
}

void recordVideo::writeFrame(const Mat& frame) {
	if (videoWriter.isOpened())videoWriter.write(frame);
}