#include "TextureManager.h"
#include <GL/gl.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdexcept>
#include <vector>


TextureManager::TextureManager() {
    glEnable(GL_TEXTURE_2D);
}

TextureManager* TextureManager::m_pInstance = NULL;

TextureManager* TextureManager::getInstance() {
    if (!m_pInstance) {
        m_pInstance = new TextureManager();
    }
    return m_pInstance;
}


TextureManager::~TextureManager() {
    cleanUp();
    delete m_pInstance;
}

void TextureManager::cleanUp() {
    printf("Texture manager is cleaning up\n");
    std::vector<GLuint> arr;
    
    
    const unsigned int s = idMap.size();
    arr.reserve(s);
    for (std::map<const char*, GLuint>::iterator it = idMap.begin(); it != idMap.end(); ++it) {
        arr.push_back(it->second);
    }
    glDeleteTextures(s, &arr[0]);
}

void TextureManager::testSet(const char* name, GLuint x) {
    printf("Setting %s to %u\n", name, x);
    idMap[name] = x;
}

GLuint TextureManager::testGet(const char* name) {
    GLuint x = 0;
    try {
        x = idMap.at(name);
        printf("Looked up entry at %s, got %u\n", name, x);
    } catch (const std::out_of_range& oor) {
        x = 0;
        printf("Lookup for %s failed\n", name);
    }
    return x;
}

void TextureManager::addPngTexture(const char *imgFile, const char *name) {
    
    if (idMap.find(name) != idMap.end()) {
        printf("warning: %s texture has already been loaded, skipping it\n", name);
        return;
    }
    
    GLuint texture = 0;
    SDL_Surface* s = IMG_Load(imgFile);
    printf("Loaded texture %s, width = %d, height = %d\n", imgFile, s->w, s->h);
    // Check that the image's width is a power of 2
    if ( (s->w & (s->w - 1)) != 0 ) {
        printf("warning: image.bmp's width is not a power of 2\n");
    }
    // Also check if the height is a power of 2
    if ( (s->h & (s->h - 1)) != 0 ) {
        printf("warning: image.bmp's height is not a power of 2\n");
    }
    
    glGenTextures(1, &texture);
    
    // Bind the texture object
    glBindTexture( GL_TEXTURE_2D, texture );

    // Set the texture's stretching properties
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

    // Edit the texture object's image data using the information SDL_Surface gives us
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, s->w, s->h, 0, 
                 GL_RGB, GL_UNSIGNED_BYTE, s->pixels);
    
    SDL_FreeSurface(s);
    
    idMap[name] = texture;
    printf("Set texture %s to %u\n", name, texture);
    try {
        printf("Trying the lookup: %u\n", idMap[name]);
    } catch (const std::out_of_range& oor) {
        printf("Nope, even that doesn't work\n");
    }
}

GLuint TextureManager::getTexture(const char *name) {
    //if (idMap.find(name) == idMap.end()) {
    //    printf("Can't find texture called %s\n", name);
    //    return 0;
    //} else {
    //    return idMap[name];
    //}
    try {
        return idMap.at(name);
    } catch (const std::out_of_range& oor) {
        //printf("Can't find texture called %s\n", name);
        return (GLuint)0;
    }
}

void TextureManager::selectTexture(const char *name) {
    GLuint id = getTexture(name);
    if (id != 0) {
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        glBindTexture(GL_TEXTURE_2D, id);
    }
}
