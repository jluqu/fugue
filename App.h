#ifndef _APP_H_
#define _APP_H_

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "Level.h"

class App {
    private:
        bool Running;
        SDL_Surface* Surf_Display;
        Level* level;

    public:
        App();
        int OnExecute();

    public:
        bool OnInit();
        void OnEvent(SDL_Event* Event);
        void OnLoop();
        void OnRender();
        void OnCleanup();
};

#endif
