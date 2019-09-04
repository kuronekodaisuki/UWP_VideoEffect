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
    public ref class DNN sealed
    {
    public:
        DNN();
    };
}
