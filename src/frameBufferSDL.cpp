#include "frameBufferSDL.h"

//Constructor
FrameBufferSDL::FrameBufferSDL(int width, int height): 
    FrameBuffer(width, height)
{
    uint32_t flags = SDL_INIT_VIDEO;
    SDL_Init(flags);
    _window = SDL_CreateWindow("CUTRE", 0, 0, _width, _height, 0);
    _surface = SDL_GetWindowSurface(_window);
}

void FrameBufferSDL::block()
{
    SDL_LockSurface(_surface);
}

void FrameBufferSDL::unblock()
{
    SDL_UnlockSurface(_surface);
}

void FrameBufferSDL::updateScreen()
{
    SDL_UpdateWindowSurface(_window);
}

void FrameBufferSDL::setPixelColour(int x, int y, const Colour& colour)
{
    int* pixel = (int*) _surface->pixels;
    pixel += x + y * _width;
    *pixel = SDL_MapRGB(_surface->format, colour.r(), colour.g(), colour.b());
}
