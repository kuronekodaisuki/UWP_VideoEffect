// MobilenetSSD.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;

int main(int argc, char *argv[])
{
	dnn::Net _net;
	switch (argc)
	{
	case 4:
		Mat image = imread(argv[1]);
		_net = cv::dnn::readNetFromCaffe(argv[2], argv[3]);
		_net.setPreferableBackend(cv::dnn::DNN_BACKEND_OPENCV);
		_net.setPreferableTarget(cv::dnn::DNN_TARGET_OPENCL);

		//cv::Mat image(height, width, CV_8UC4, data);
		cv::Mat blob;
		//cv::cvtColor(bgra, rgb, cv::COLOR_BGRA2BGR);
		blob = cv::dnn::blobFromImage(image, 1.0, cv::Size(), cv::Scalar(), false, false);
		_net.setInput(blob);
		cv::Mat probs = _net.forward();
		// この後　http://tecsingularity.com/opencv/opencv_googlenet/

		imshow("Image", image);
		while (true)
		{
			int c = waitKey(10);
			if (c == 'q' || c == 'Q')
				break;
		}
	}
}
