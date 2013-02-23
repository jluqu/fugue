#ifndef _DYNAMICOBJECT_H_
#define _DYNAMICOBJECT_H_

#include "LevelObject.h"

class DynamicObject : public LevelObject {
    public:
        DynamicObject();
        virtual ~DynamicObject();
        virtual void draw() = 0;
        
    private:
        float vx;
        float vy;
};

#endif
