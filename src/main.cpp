#include <iostream>
#include <SDL2/SDL.h>

#include "frameBufferSDL.h"
#include "vector.h"
#include "mathStuff.h"
#include "camera.h"
#include "sphere.h"
#include "scene.h"
#include "renderer.h"
#include "pointLight.h"
#include "lambert.h"
#include "colour.h"

#define WIDTH 1280
#define HEIGHT 720

int main (void)
{
    //Initialize SDL
    uint32_t flags = SDL_INIT_VIDEO;
    SDL_Init(flags);

    //Prepare frame
    FrameBufferSDL frameBuff (WIDTH, HEIGHT);

    //Prepare scene
    Vec3f cameraPosition (0., 0., 0.);
    Camera mainCamera (cameraPosition, deg2rad(35.));
    Sphere sphere (Vec3f(0., 0., -100.), 15.);
    Lambert lambert(fColour(0.8, 0.8, 0.8));
    sphere.setMaterial(&lambert);
    Scene scene;
    scene.addShape(&sphere);

    PointLight light(Vec3f(50., 50., -50.), fColour(1., 1., 1.), 1.);
    PointLight light1(Vec3f(-50.,20., -50.), fColour(1., 0., 1.), 1.);
    //PointLight light(Vec3f(10., 10., 0.), fColour(1., 1., 1.), 1.);

    scene.addLightSource(&light);
    scene.addLightSource(&light1);

    //Render
    Renderer renderer(mainCamera, frameBuff, scene);
    renderer.render();

    //Update screen
    frameBuff.updateScreen();

    //Wait untill window is closed
    bool done = false;
    SDL_Event ev;
    while (!done && SDL_WaitEvent(&ev)){
        switch(ev.type){
            case SDL_QUIT:
                done = true;
                break;
        }
    }

    return 0;
}