#include <GL/gl.h>
#include <chipmunk.h>
#include <stdio.h>

#include "Player.h"
#include "TextureManager.h"

Player::Player(float x, float y, cpSpace* space) :
	DynamicObject(x, y, 1, 1.5, 5, space),
	m_facingRight(true)
{
	//cpFloat moment = cpMomentForBox(m_mass, 1.5, 1.5);
	cpFloat moment = INFINITY;  // Infinite moment of inertia - don't let player rotate
	
	m_pBody = cpSpaceAddBody(space, cpBodyNew(m_mass, moment));
	m_pShape = cpSpaceAddShape(space, cpBoxShapeNew(m_pBody, 1, 1.5));
	setPosition(x, y);
	
	cpShapeSetFriction(m_pShape, 0.7);
	cpShapeSetElasticity(m_pShape, 0.0);
}

Player::~Player()
{
	cpShapeFree(m_pShape);
	cpBodyFree(m_pBody);
}

void Player::draw()
{
    TextureManager::getInstance()->selectTexture("player");
    cpVect pos = cpBodyGetPos(m_pBody);
    glTranslatef(pos.x, pos.y, 0);
    
    //glRotatef((float)cpBodyGetAngle(m_pBody)*180/3.1416, 0, 0, 1);
    float u_w, v_h;
    float aspect = m_h / m_w;
    if (aspect > 1)
    {
		v_h = 0.5;
		u_w = 1/(2*aspect);
    }
    else
    {
		v_h = 2*aspect;
		u_w = 0.5;
	}
    
    glBegin(GL_QUADS);
	if (m_facingRight)
	{
		glTexCoord2f(0.5-u_w, 0.5-v_h); glVertex3f(-m_w/2, m_h/2, 0);
		glTexCoord2f(0.5+u_w, 0.5-v_h); glVertex3f(m_w/2, m_h/2, 0);
		glTexCoord2f(0.5+u_w, 0.5+v_h); glVertex3f(m_w/2, -m_h/2, 0);
		glTexCoord2f(0.5-u_w, 0.5+v_h); glVertex3f(-m_w/2, -m_h/2, 0);
	} 
	else
	{
		glTexCoord2f(0.5+u_w, 0.5-v_h); glVertex3f(-m_w/2, m_h/2, 0);
		glTexCoord2f(0.5-u_w, 0.5-v_h); glVertex3f(m_w/2, m_h/2, 0);
		glTexCoord2f(0.5-u_w, 0.5+v_h); glVertex3f(m_w/2, -m_h/2, 0);
		glTexCoord2f(0.5+u_w, 0.5+v_h); glVertex3f(-m_w/2, -m_h/2, 0);
	}
    glEnd();
}


float Player::getXVel()
{
	cpVect v = cpBodyGetVel(m_pBody);
	return (float)v.x;
}

float Player::getYVel()
{
	cpVect v = cpBodyGetVel(m_pBody);
	return (float)v.y;
}
/*
void Player::setVelocity(float vx, float vy)
{
	cpBodySetVel(m_pBody, cpv(vx, vy));
}
*/

void Player::run(float dir)
{
	if (dir > 0)
	{
		m_facingRight = true;
	}
	else
	{
		m_facingRight = false;
	}
		
	cpBodyApplyImpulse(m_pBody, cpv(dir, 0.0), cpv(0, 0));
}

void Player::jump(float force)
{
	cpBodyApplyImpulse(m_pBody, cpv(0.0, force), cpvzero);
}
