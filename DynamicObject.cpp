#include <chipmunk.h>
#include <GL/gl.h>
#include <stdio.h>
#include "DynamicObject.h"

static void updateGrounded(cpBody* body, cpArbiter* arb, bool* grounded)
{
	cpVect n = cpArbiterGetNormal(arb, 0);
	if (n.y < 0)
	{
		*grounded = true;
	}
}

DynamicObject::DynamicObject(float x, float y, float w, float h, float mass, cpSpace* space) :
	LevelObject(x, y, w, h, space),
	m_mass(mass),
	m_facingRight(true),
	m_grounded(true)
{
}

DynamicObject::~DynamicObject()
{
}

void DynamicObject::draw()
{
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

void DynamicObject::setPosition(float x, float y)
{
	m_x = x;
	m_y = y;
	cpBodySetPos(m_pBody, cpv((cpFloat)m_x, (cpFloat)m_y));
}

float DynamicObject::getXVel()
{
	cpVect v = cpBodyGetVel(m_pBody);
	return (float)v.x;
}

float DynamicObject::getYVel()
{
	cpVect v = cpBodyGetVel(m_pBody);
	return (float)v.y;
}

void DynamicObject::setGrounded(bool grounded)
{
	m_grounded = grounded;
}

bool DynamicObject::isGrounded()
{
	m_grounded = false;
	cpBodyEachArbiter(m_pBody, (cpBodyArbiterIteratorFunc)updateGrounded, &m_grounded);
	return m_grounded;
}



