#pragma once

#include <iostream>
#include "camera.h"
#include "frameBuffer.h"
#include "scene.h"

class Renderer
{
    public:
        Renderer(Camera& camera, FrameBuffer& frame, Scene& scene);
        void render();
    private:
        Camera& _camera;
        FrameBuffer& _frameBf;
        Scene& _scene;
};