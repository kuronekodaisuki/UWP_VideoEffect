#include "pch.h"
#include <opencv2/dnn/shape_utils.hpp>
#include <opencv2/imgproc.hpp>

#include "DNN.h"

using namespace OpenCV;
using namespace Platform;

DNN::DNN()
{
}

cv::dnn::Net _net;

int CreateCaffeInstance(const char * proto, const char * caffemodel)
{
	_net = cv::dnn::readNetFromCaffe(proto, caffemodel);
	_net.setPreferableBackend(cv::dnn::DNN_BACKEND_OPENCV);
	_net.setPreferableTarget(cv::dnn::DNN_TARGET_OPENCL);
	return 0;
}

int DetectObjects(uchar * data, uint width, uint height)
{
	cv::Mat image(height, width, CV_8UC4, data);
	cv::Mat rgb, blob;
	//cv::cvtColor(bgra, rgb, cv::COLOR_BGRA2BGR);
	blob = cv::dnn::blobFromImage(image, 1.0, cv::Size(), cv::Scalar(), false, false);
	_net.setInput(blob);
	cv::Mat objects = _net.forward();
	return 0;
}
