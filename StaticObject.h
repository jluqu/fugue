#ifndef _STATIC_OBJECT_H_
#define _STATIC_OBJECT_H_

#include "LevelObject.h"

class StaticObject : public LevelObject
{
    public:
		StaticObject(float x, float y, float w, float h);
        virtual ~StaticObject();
        
        virtual void draw();
		virtual void setPosition(float x, float y);
		
		virtual void setSize(float w, float h);
};

#endif
