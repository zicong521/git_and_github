//VideoCapture.cpp
#include<opencv2\opencv.hpp>
using namespace cv;
int main(){
	VideoCapture capture(0);
	// 设置摄像头的拍摄属性为 分辨率640x480，帧率30fps
	capture.set(CAP_PROP_FRAME_HEIGHT, 480);
	capture.set(CAP_PROP_FRAME_WIDTH, 640);
	capture.set(CAP_PROP_FPS, 30.0);
	// 设置保存视频的格式为AVI，编码为MJPG
	VideoWriter writer("test.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'), 30.0, Size(640, 480), true);
	Mat videoPlay;
	// 通过总帧数来控制拍摄时间，如果是15s的段视频的话，循环450次
	int count(450);
	namedWindow("VideoPlay", WINDOW_NORMAL);
	while (count--){
		capture >> videoPlay;
		writer << videoPlay;
		imshow("VideoPlay", videoPlay);
		waitKey(1000 / 30);
	}
	// 释放相关对象
	writer.release();
	capture.release();
	destroyWindow("VideoPlay");
	return 0;
}
