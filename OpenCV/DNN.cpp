#include "pch.h"
#include <opencv2/dnn/shape_utils.hpp>
#include <opencv2/imgproc.hpp>

#include "DNN.h"

using namespace OpenCV;
using namespace Platform;


cv::dnn::Net _net;
cv::Mat _objects;

int CreateCaffeInstance(const char * proto, const char * caffemodel)
{
	_net = cv::dnn::readNetFromCaffe(proto, caffemodel);
	_net.setPreferableBackend(cv::dnn::DNN_BACKEND_OPENCV);
	_net.setPreferableTarget(cv::dnn::DNN_TARGET_OPENCL);
	return 0;
}

int CreateDarknetInstance(const char * cfg, const char * weights)
{
	_net = cv::dnn::readNetFromDarknet(cfg, weights);
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
	_objects = _net.forward();
	return 0;
}


bool GetObject(int index, OpenCV::bbox_t & object)
{
	return false;
}
