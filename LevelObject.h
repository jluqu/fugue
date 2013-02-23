#ifndef _LEVELOBJECT_H_
#define _LEVELOBJECT_H_

#include "TextureManager.h"

class LevelObject {
    public:
        LevelObject();
        LevelObject(float x_in, float y_in, float w_in, float h_in);
		virtual ~LevelObject();
		
        virtual void draw();
        void setPosition(float x_in, float y_in);
        void setSize(float w_in, float h_in);
    
    protected:
        float x, y;
        float w, h;
        //static TextureManager tm = TextureManager::getInstance();
};

#endif
