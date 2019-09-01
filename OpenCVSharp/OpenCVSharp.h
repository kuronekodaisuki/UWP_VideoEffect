#pragma once

#pragma unmanaged
#include <opencv2/core.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#pragma managed

using namespace System;

namespace OpenCVSharp 
{
	public ref class DNN
	{
		DNN();

		int ReadNetFromCaffe(String^ prototext, String^ model);

	};
}
