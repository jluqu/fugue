#ifndef _APP_H_
#define _APP_H_

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "Level.h"

class App
{
    public:
        App();
        int onExecute();

        bool onInit();
        void onEvent(SDL_Event* event);
        void onLoop();
        void onRender();
        void onCleanup();
        
    private:
        bool m_running;
        SDL_Surface* m_pSurfDisplay;
        Level* m_pLevel;
        float m_targetFps;
        
        bool m_leftDown, m_rightDown, m_upDown, m_downDown, m_spaceDown;
        
};

#endif
