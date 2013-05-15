#include <GL/gl.h>
#include <chipmunk.h>
#include <stdio.h>

#include "Player.h"
#include "TextureManager.h"

Player::Player(float x, float y, cpSpace* space) :
	DynamicObject(x, y, 1.5, 1.5, 5, space)
{
	cpFloat moment = cpMomentForBox(m_mass, 1.5, 1.5);
	m_pBody = cpSpaceAddBody(space, cpBodyNew(m_mass, moment));
	m_pShape = cpSpaceAddShape(space, cpBoxShapeNew(m_pBody, 1.5, 1.5));
	setPosition(x, y);
	cpBodySetVel(m_pBody, cpv(-2, 15));
}

Player::~Player()
{
	cpShapeFree(m_pShape);
	cpBodyFree(m_pBody);
}

void Player::draw()
{
    TextureManager::getInstance()->selectTexture("player");
    
    glBegin(GL_QUADS);
        cpVect pos = cpBodyGetPos(m_pBody);
        // TODO: figure out how to pull w and h from m_pShape??
        /*
        int n = cpPolyShapeGetNumVerts(m_pShape);
        if (n != 4) {
			printf("Unexpected number of verticies: %d\n", n);
		}
        cpVect v = cpPolyShapeGetVert(m_pShape, 0);
        glTexCoord2f(0, 1); glVertex3f(v.x, v.y, 0);
        v = cpPolyShapeGetVert(m_pShape, 1);
        glTexCoord2f(1, 1); glVertex3f(v.x, v.y, 0);
        v = cpPolyShapeGetVert(m_pShape, 2);
        glTexCoord2f(1, 0); glVertex3f(v.x, v.y, 0);
        v = cpPolyShapeGetVert(m_pShape, 3);
        glTexCoord2f(0, 0); glVertex3f(v.x, v.y, 0);
        */
        
        
        glTexCoord2f(0, 1); glVertex3f(pos.x - m_w/2, pos.y - m_h/2, 0);
        glTexCoord2f(1, 1); glVertex3f(pos.x + m_w/2, pos.y - m_h/2, 0);
        glTexCoord2f(1, 0); glVertex3f(pos.x + m_w/2, pos.y + m_h/2, 0);
        glTexCoord2f(0, 0); glVertex3f(pos.x - m_w/2, pos.y + m_h/2, 0);
		
		
    glEnd();
}
