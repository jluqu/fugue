#ifndef _APP_H_
#define _APP_H_

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "Level.h"

class App
{
    private:
        bool m_running;
        SDL_Surface* m_pSurfDisplay;
        Level* m_pLevel;
        float m_targetFps;

    public:
        App();
        int onExecute();

    public:
        bool onInit();
        void onEvent(SDL_Event* event);
        void onLoop();
        void onRender();
        void onCleanup();
};

#endif
