using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Windows.Foundation.Collections;
using Windows.Graphics.DirectX.Direct3D11;
using Windows.Media;
using Windows.Media.Effects;
using Windows.Media.MediaProperties;

namespace VideoEffectLibrary
{
    public sealed class ExampleVideoEffect: IBasicVideoEffect
    {
        public void SetEncodingProperties(VideoEncodingProperties encodingProperties, IDirect3DDevice device)
        {
            throw new NotImplementedException();
        }

        public void ProcessFrame(ProcessVideoFrameContext context)
        {
            throw new NotImplementedException();
        }

        public void Close(MediaEffectClosedReason reason)
        {
            throw new NotImplementedException();
        }

        public void DiscardQueuedFrames()
        {
            throw new NotImplementedException();
        }

        public bool IsReadOnly => throw new NotImplementedException();

        public IReadOnlyList<VideoEncodingProperties> SupportedEncodingProperties => throw new NotImplementedException();

        public MediaMemoryTypes SupportedMemoryTypes => throw new NotImplementedException();

        public bool TimeIndependent => throw new NotImplementedException();

        public void SetProperties(IPropertySet configuration)
        {
            throw new NotImplementedException();
        }
    }
}
