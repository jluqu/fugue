#ifndef _TEXTURE_MANAGER_H_
#define _TEXTURE_MANAGER_H_

#include <map>
#include <GL/gl.h>
#include <SDL/SDL_image.h>

class TextureManager {
    public:
        static TextureManager* getInstance();
        
        void addPngTexture(const char *imgFile, const char *name);
        GLuint getTexture(const char *name);
        void selectTexture(const char *name);
        
        void testSet(const char* name, GLuint x);
        GLuint testGet(const char* name);
        
        void cleanUp();
        
        
    private:
        TextureManager();
        ~TextureManager();
        static TextureManager* m_pInstance;
        std::map<const char*, GLuint> idMap;
};

#endif
