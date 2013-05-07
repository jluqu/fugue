#ifndef _LEVELOBJECT_H_
#define _LEVELOBJECT_H_

#include <chipmunk.h>

class LevelObject
{
    public:
		LevelObject();
		LevelObject(float x, float y, float w, float h);
		virtual ~LevelObject();
        
        virtual void draw();
        virtual void setPosition(float x, float y);
        
    protected:
        // pointers are declared here, but are the responsibilty of inherited classes to create and free
        cpBody* m_pBody;
        cpShape* m_pShape;
        
        float m_x, m_y;
        float m_w, m_h;
		
};

#endif
