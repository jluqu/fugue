#include "App.h"

#define SCR_WIDTH 1024
#define SCR_HEIGHT 786

#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include "Level.h"
#include "TextureManager.h"


App::App() :
    m_running(true),
    m_pSurfDisplay(NULL),
    m_pLevel(NULL),
    m_targetFps(60),
    m_leftDown(false),
    m_rightDown(false),
    m_upDown(false),
    m_downDown(false),
    m_spaceDown(false)
{
}

void App::onCleanup()
{
    SDL_FreeSurface(m_pSurfDisplay);
    SDL_Quit();
    TextureManager::getInstance()->cleanUp();
    delete m_pLevel;
}

void App::onEvent(SDL_Event* event)
{
    switch (event->type)
    {
        case SDL_QUIT:
            m_running = false;
            break;
            
        case SDL_KEYDOWN:
            switch (event->key.keysym.sym)
            {
                case SDLK_LEFT:
					m_leftDown = true;
                    break;
                case SDLK_RIGHT:
					m_rightDown = true;
                    break;
                case SDLK_UP:
					m_upDown = true;
                    break;
                case SDLK_DOWN:
					m_downDown = true;
                    break;
                case SDLK_SPACE:
					m_spaceDown = true;
					break;
                default:
                    break;
            }
            break;

        case SDL_KEYUP:
            switch (event->key.keysym.sym)
            {
                case SDLK_LEFT:
					m_leftDown = false;
                    break;
                case SDLK_RIGHT:
					m_rightDown = false;
                    break;
                case SDLK_UP:
					m_upDown = false;
                    break;
                case SDLK_DOWN:
					m_downDown = false;
                    break;
                case SDLK_SPACE:
					m_spaceDown = false;
					break;
                default:
                    break;
            }
            break;

        default:
            break;
    }
}

bool App::onInit()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return false;
    }

    SDL_GL_SetAttribute(SDL_GL_RED_SIZE,            8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,          8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,           8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE,          8);

    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,          16);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE,         32);

    SDL_GL_SetAttribute(SDL_GL_ACCUM_RED_SIZE,      8);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_GREEN_SIZE,    8);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_BLUE_SIZE,     8);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_ALPHA_SIZE,    8);

    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS,  1);
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES,  2);

    if((m_pSurfDisplay = SDL_SetVideoMode(SCR_WIDTH, SCR_HEIGHT, 32, SDL_HWSURFACE | SDL_GL_DOUBLEBUFFER | SDL_OPENGL)) == NULL)
    {
        return false;
    }

    glClearColor(0, 0, 0, 0);
    glShadeModel(GL_FLAT);

    glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);

    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    float h = (GLfloat)SCR_HEIGHT/(GLfloat)SCR_WIDTH;
    glFrustum(-1.0, 1.0, -h, h, 1.0, 300.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_TEXTURE_2D);
    
    TextureManager::getInstance()->addPngTexture("test.png", "blue");
    TextureManager::getInstance()->addPngTexture("test2.png", "red");
    TextureManager::getInstance()->addPngTexture("character.png", "player");
    
    m_pLevel = new Level();
	m_pLevel->loadFromXml("testlevel.xml");
    return true;
}

void App::onLoop()
{
	m_pLevel->updateActions(m_leftDown, m_rightDown, m_upDown, m_downDown, m_spaceDown);
}

int App::onExecute()
{
    if (onInit() == false)
    {
        return -1;
    }

    SDL_Event event;

    timespec start, end;
    double elapsed;
    long waitusec;
    while (m_running)
    {
        clock_gettime(CLOCK_MONOTONIC, &start);
        while(SDL_PollEvent(&event))
        {
            onEvent(&event);
        }

        onLoop();
        onRender();
        
        clock_gettime(CLOCK_MONOTONIC, &end);
        elapsed = double(end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec)/double(1000000000);
        
        if (elapsed < double(1/m_targetFps))
        {
            waitusec = (double(1/m_targetFps) - elapsed) * 1000000;
            usleep(waitusec);
        }
    }

    onCleanup();

    return 0;
}

void App::onRender()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, -7.0, -15.0);
    
    m_pLevel->draw();
    
    SDL_GL_SwapBuffers();
}

int main(int argc, char* argv[])
{
    App mainApp;
    return mainApp.onExecute();
}
