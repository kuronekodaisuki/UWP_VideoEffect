#include "stdafx.h"

#include "OpenCVSharp.h"

using System.Runtime.InteropServices;

namespace OpenCVSharp
{
	DNN::DNN()
	{

	}

	int DNN::ReadNetFromCaffe(String^ prototext, String^ model)
	{
		cv:: dnn::readNetFromCaffe(prototext, model);
		return 0;
	}
}