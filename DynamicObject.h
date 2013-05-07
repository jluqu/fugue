#ifndef _DYNAMICOBJECT_H_
#define _DYNAMICOBJECT_H_

#include "LevelObject.h"

class DynamicObject : public LevelObject
{
    public:
        DynamicObject(float x, float y, float w, float h);
        virtual ~DynamicObject();
        
        virtual void draw();
        
		void setPosition(float x, float y);

};

#endif
