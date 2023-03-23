#include "frameBuffer.h"

//Constructor
FrameBuffer::FrameBuffer(int width, int height)
{
    _width = width;
    _height = height;
}

//Other methods

int FrameBuffer::getWidth() const
{
    return _width;
}

int FrameBuffer::getHeight() const
{
    return _height;
}

float FrameBuffer::getAspectRatio() const
{
    return (float)_width / (float)_height;
}
