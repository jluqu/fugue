#include "App.h"

#define SCR_WIDTH 1024
#define SCR_HEIGHT 786

#include "Level.h"
#include "TextureManager.h"

App::App() {
    Surf_Display = NULL;

    Running = true;
    

}

void App::OnCleanup() {
    SDL_FreeSurface(Surf_Display);
    SDL_Quit();
    TextureManager::getInstance()->cleanUp();
    delete level;
}

void App::OnEvent(SDL_Event* Event) {
    if(Event->type == SDL_QUIT) {
        Running = false;
    }
}

bool App::OnInit() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
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

    if((Surf_Display = SDL_SetVideoMode(SCR_WIDTH, SCR_HEIGHT, 32, SDL_HWSURFACE | SDL_GL_DOUBLEBUFFER | SDL_OPENGL)) == NULL) {
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
    
	TextureManager::getInstance()->addPngTexture("test.png", "test");
    TextureManager::getInstance()->addPngTexture("test2.png", "test2");
    
    level = new Level();

    return true;
}

void App::OnLoop() {
}

int App::OnExecute() {
    if(OnInit() == false) {
        return -1;
    }

    SDL_Event Event;

    while(Running) {
        while(SDL_PollEvent(&Event)) {
            OnEvent(&Event);
        }

        OnLoop();
        OnRender();
    }

    OnCleanup();

    return 0;
}

void App::OnRender() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -10.0);
    
    level->draw();
    
    SDL_GL_SwapBuffers();
}

int main(int argc, char* argv[]) {
    App mainApp;

    return mainApp.OnExecute();
}
