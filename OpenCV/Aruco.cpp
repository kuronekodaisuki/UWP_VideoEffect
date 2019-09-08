#include "pch.h"
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

void Aruco::Detect(int* data, size_t length)
{
	cv::Mat image;
	std::vector<float> corners;
	std::vector<int> ids;
	cv::aruco::detectMarkers(image, _dictionary, corners, ids);
}