using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Windows.Foundation.Collections;
using Windows.Graphics.Imaging;
using Windows.Graphics.DirectX.Direct3D11;
using Windows.Media;
using Windows.Media.Effects;
using Windows.Media.MediaProperties;


//using OpenCVSharp;

namespace VideoEffectLibrary
{
    public sealed class ExampleVideoEffect: IBasicVideoEffect
    {
        private IPropertySet _properties;
        private IDirect3DDevice _device;

        public void ProcessFrame(ProcessVideoFrameContext context)
        {
            throw new NotImplementedException();
        }


        public void SetEncodingProperties(VideoEncodingProperties encodingProperties, IDirect3DDevice device)
        {
            _device = device;
        }

        public void Close(MediaEffectClosedReason reason)
        {
        }

        public void DiscardQueuedFrames()
        {
        }

        public bool IsReadOnly
        {
            get { return true; }
        }

        public IReadOnlyList<VideoEncodingProperties> SupportedEncodingProperties => throw new NotImplementedException();

        public bool TimeIndependent
        {
            get { return true; }
        }

        public void SetProperties(IPropertySet configuration)
        {
            _properties = configuration;
        }

        MediaMemoryTypes IBasicVideoEffect.SupportedMemoryTypes => throw new NotImplementedException();
    }
}
