#ifndef _STATIC_OBJECT_H_
#define _STATIC_OBJECT_H_

#include <chipmunk.h>
#include "LevelObject.h"

class StaticObject : public LevelObject
{
    public:
		StaticObject(float x, float y, float w, float h, cpSpace* space);
        virtual ~StaticObject();
        
        virtual void draw();
};

#endif
