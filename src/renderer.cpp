#include "renderer.h"

Renderer::Renderer(Camera &camera, FrameBuffer &frameBf, Scene &scene) : _camera(camera),
                                                                         _frameBf(frameBf),
                                                                         _scene(scene)
{
}

void Renderer::render()
{
    _frameBf.block();
    for (int i = 0; i < _frameBf.getWidth(); i++)
    {
        for (int j = 0; j < _frameBf.getHeight(); j++)
        {
            Ray primaryRay = _camera.primaryRay(i, j, _frameBf);

#if 0
            printf("Ray px %d %d: pos %f %f %f, dir %f %f %f\n", i, j,
                                                                 primaryRay.pos.x(),
                                                                 primaryRay.pos.y(),
                                                                 primaryRay.pos.z(),
                                                                 primaryRay.dir.x(),
                                                                 primaryRay.dir.y(),
                                                                 primaryRay.dir.z());
#endif

            Colour pixelColour = _scene.castRay(primaryRay);
            _frameBf.setPixelColour(i, j, pixelColour);
        }
    }
    _frameBf.unblock();
}
