#pragma once

#include <opencv2/aruco.hpp>
#include <opencv2/core.hpp>

#include <MemoryBuffer.h>

using namespace Microsoft::WRL;
using namespace Windows::Foundation;
using namespace Windows::Graphics::Imaging;
using namespace Windows::UI::Xaml::Media::Imaging;

namespace OpenCV
{
	class Aruco
	{
		cv::Ptr<cv::aruco::Dictionary> _dictionary;
	public:
		Aruco(cv::aruco::PREDEFINED_DICTIONARY_NAME name = cv::aruco::PREDEFINED_DICTIONARY_NAME::DICT_6X6_100);
		~Aruco();

		void Detect(int* data, size_t length);
	};
}
