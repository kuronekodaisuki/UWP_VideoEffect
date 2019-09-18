#include "pch.h"
#include "ONNX.h"

static cv::dnn::Net _net;

int32_t CreateONNX(const char* onnx)
{
	_net = cv::dnn::readNetFromONNX(onnx);
	_net.setPreferableBackend(cv::dnn::DNN_BACKEND_OPENCV);
	_net.setPreferableTarget(cv::dnn::DNN_TARGET_OPENCL);
	return 0;
}

int32_t DetectONNX(void* data, int width, int height, int channel)
{
	cv::Mat image(height, width, CV_MAKETYPE(CV_8U, channel), data);
	cv::Mat blob = cv::dnn::blobFromImage(image, 1.0 / 128, cv::Size(width, height), cv::Scalar(128, 128, 128), true);
	_net.setInput(blob);
	cv::Mat ret = _net.forward();

	return 0;
}