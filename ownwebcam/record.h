/*Name:Record funtion header file
* Author:SP
* Date:4-7-24
* So this is the header file for the recording process which is getting impletemented in the application
* 1)Start the recording process
* 2)Recording process
* 3)Stop the recording
*/

#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;


class recordVideo {

public:
	recordVideo();
	void startRecording(const string& outputPath);
	void stopRecording();
	void writeFrame(const Mat& frame);
private:
	VideoWriter videoWriter;

};