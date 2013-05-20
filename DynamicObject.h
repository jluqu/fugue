#ifndef _DYNAMICOBJECT_H_
#define _DYNAMICOBJECT_H_

#include <chipmunk.h>
#include "LevelObject.h"

class DynamicObject : public LevelObject
{
    public:
        DynamicObject(float x, float y, float w, float h, float mass, cpSpace* space);
        virtual ~DynamicObject();
        
        virtual void draw();
        
		void setPosition(float x, float y);
		
		float getXVel();
		float getYVel();
		
		void setGrounded(bool grounded);
		bool isGrounded();
		
	protected:
		float m_mass;
		bool m_facingRight;
		bool m_grounded;
};


#endif
