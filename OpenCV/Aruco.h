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
	public:
		Aruco();
		~Aruco();
	};
}
