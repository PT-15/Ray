#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include "frameBuffer.h"
#include "colour.h"

class FrameBufferSDL: public FrameBuffer
{
    public:
        FrameBufferSDL(int width, int height); //Constructor

        virtual void block();
        virtual void unblock();
        virtual void updateScreen();
        virtual void setPixelColour(int x, int y, const Colour& colour);

    private:
        SDL_Window* _window;
        SDL_Surface* _surface;
};
