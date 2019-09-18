#pragma once

#include <opencv2/core.hpp>
#include <opencv2/dnn.hpp>

#include <MemoryBuffer.h>

using namespace Microsoft::WRL;
using namespace Windows::Foundation;
using namespace Windows::Graphics::Imaging;
using namespace Windows::UI::Xaml::Media::Imaging;

using namespace cv;

namespace OpenCV
{

}

extern "C"
{
	_declspec(dllexport) int32_t CreateONNX(const char* onnx);
	_declspec(dllexport) int32_t DetectONNX(const void* data, size_t width, size_t height, int channel);
}