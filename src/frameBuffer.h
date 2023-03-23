#pragma once

#include <iostream>
#include "colour.h"

class FrameBuffer {
    public:
        FrameBuffer(int width, int height); //Constructor

        int getWidth() const;
        int getHeight() const;
        float getAspectRatio() const;
        virtual void block() = 0;
        virtual void unblock() = 0;
        virtual void updateScreen() = 0; //Obliga al hijo a implementar la clase
        virtual void setPixelColour(int x, int y, const Colour& colour) = 0;
        //El igual a 0 implica que no tiene implementación en esta clase

    protected:
        int _width;
        int _height;
        int* _frameBuffer;
};
