using System;
using System.Collections.Generic;
using System.Linq;
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
        private IPropertySet _properties;
        private IDirect3DDevice _device;

        public void ProcessFrame(ProcessVideoFrameContext context)
        {
            //using (CanvasBitmap input = CanvasBitmap.CreateFromDirect3D11Surface(_device, context.InputFrame.Direct3DSurface))
            //using (CanvasRenderTarget target = CanvasRenderTarget.CreateFromDirect3D11Surface(_device, context.OutputFrame.Direct3DSurface))
            //using (CanvasDrawingSession session = target.CreateDrawingSession())
            {
                BitmapBuffer buffer = context.InputFrame.SoftwareBitmap.LockBuffer(BitmapBufferAccessMode.Read);
                
            }
        }


        public void SetEncodingProperties(VideoEncodingProperties encodingProperties, IDirect3DDevice device)
        {
            _device = device;
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
