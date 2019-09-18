using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

using Microsoft.Graphics;
using Microsoft.Graphics.Canvas;
using Microsoft.Graphics.Canvas.UI.Xaml;

using Windows.Foundation.Collections;
using Windows.Graphics;
using Windows.Graphics.Imaging;
using Windows.Graphics.DirectX.Direct3D11;
using Windows.Media;
using Windows.Media.Effects;
using Windows.Media.MediaProperties;
//using Windows.UI.Xaml.Media;


//using OpenCVSharp;

namespace VideoEffectLibrary
{
    public sealed class ExampleVideoEffect: IBasicVideoEffect
    {
        [DllImport("OpenCV.dll", EntryPoint = "CreateONNX")]
        static extern int CreateONNX(string onnx);

        [DllImport("OpenCV.dll", EntryPoint = "DetectONNX")]
        static extern int DetectONNX(IntPtr data, int width, int height, int channel);

        private IPropertySet _properties;
        private CanvasDevice _device;

        public void ProcessFrame(ProcessVideoFrameContext context)
        {
            using (CanvasBitmap input = CanvasBitmap.CreateFromDirect3D11Surface(_device, context.InputFrame.Direct3DSurface))
            using (CanvasRenderTarget target = CanvasRenderTarget.CreateFromDirect3D11Surface(_device, context.OutputFrame.Direct3DSurface))
            using (CanvasDrawingSession session = target.CreateDrawingSession())
            {
                byte[] bytes = input.GetPixelBytes();
                IntPtr ptr = Marshal.AllocHGlobal(bytes.Length);
                Marshal.Copy(bytes, 0, ptr, bytes.Length);



                Marshal.FreeHGlobal(ptr);
            }
        }


        public void SetEncodingProperties(VideoEncodingProperties encodingProperties, IDirect3DDevice device)
        {
            _device = CanvasDevice.CreateFromDirect3D11Device(device);
        }

        public void Close(MediaEffectClosedReason reason)
        {
            if (_device != null)
                _device.Dispose();
        }

        public void DiscardQueuedFrames()
        {
            // Do nothing
        }

        public bool IsReadOnly
        {
            get { return true; }
        }

        public IReadOnlyList<VideoEncodingProperties> SupportedEncodingProperties
        {
            get
            {
                return new List<VideoEncodingProperties>()
                {
                    VideoEncodingProperties.CreateUncompressed(MediaEncodingSubtypes.Argb32, 1280, 720)
                };
            }
        }

        public bool TimeIndependent
        {
            get { return true; }
        }

        public void SetProperties(IPropertySet configuration)
        {
            _properties = configuration;
        }

        MediaMemoryTypes IBasicVideoEffect.SupportedMemoryTypes
        {
            get { return MediaMemoryTypes.GpuAndCpu; }
        }
    }
}
