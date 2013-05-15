#include <chipmunk.h>

#include "DynamicObject.h"


DynamicObject::DynamicObject(float x, float y, float w, float h, float mass, cpSpace* space) :
	LevelObject(x, y, w, h, space),
	m_mass(mass)
{
}

DynamicObject::~DynamicObject()
{
}

void DynamicObject::draw()
{
}

void DynamicObject::setPosition(float x, float y)
{
	m_x = x;
	m_y = y;
	cpBodySetPos(m_pBody, cpv((cpFloat)m_x, (cpFloat)m_y));
}

