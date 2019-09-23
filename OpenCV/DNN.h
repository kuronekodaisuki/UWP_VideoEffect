#pragma once

#include <opencv2/core.hpp>
#include <opencv2/dnn.hpp>

#include <MemoryBuffer.h>

using namespace Microsoft::WRL;
using namespace Windows::Foundation;
using namespace Windows::Graphics::Imaging;
using namespace Windows::UI::Xaml::Media::Imaging;

namespace OpenCV
{
	public value struct bbox_t
	{
		int x, y, w, h;
		float prob;
		int obj_id;
	};
}

#define DLLEXPORT __declspec(dllexport)

extern "C"
{
	DLLEXPORT int __stdcall CreateCaffeInstance(const char * proto, const char * caffemodel);

	DLLEXPORT int __stdcall CreateDarknetInstance(const char* cfg, const char* weights);

	DLLEXPORT int __stdcall DetectObjects(uchar* data, uint width, uint height);

	DLLEXPORT bool __stdcall GetObject(int index, OpenCV::bbox_t& object);
}
