#include "pch.h"
#include <opencv2/imgproc.hpp>

#include "Aruco.h"

using namespace OpenCV;
using namespace Platform;

Aruco::Aruco(cv::aruco::PREDEFINED_DICTIONARY_NAME name)
{
	_dictionary = cv::aruco::getPredefinedDictionary(name);
}


Aruco::~Aruco()
{
	_dictionary.release();
}

static cv::Ptr<cv::aruco::Dictionary> _dictionary;

void Aruco::Detect(int* data, size_t length)
{
	cv::Mat image;
	std::vector<float> corners;
	std::vector<int> ids;
	cv::aruco::detectMarkers(image, _dictionary, corners, ids);
}

int CreateArucoInstance()
{
	_dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::PREDEFINED_DICTIONARY_NAME::DICT_6X6_100);
	return 0;
}

int DetectMarkers(uchar * data, uint width, uint height)
{
	cv::Mat image(height, width, CV_8UC4, data);
	cv::Mat gray;
	cv::cvtColor(image, gray, cv::COLOR_BGRA2GRAY);

	std::vector<int> ids;
	std::vector<std::vector<cv::Point2f>> corners;
	cv::aruco::detectMarkers(gray, _dictionary, corners, ids);

	cv::aruco::drawDetectedMarkers(image, corners, ids);
	return 0;
}
