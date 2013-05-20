#include <chipmunk.h>
#include "LevelObject.h"

LevelObject::LevelObject(cpSpace* space) :
	m_pSpace(space),
	m_x(0),
	m_y(0),
	m_w(1),
	m_h(1)
{
}

LevelObject::LevelObject(float x, float y, float w, float h, cpSpace* space) :
	m_pSpace(space),
	m_x(x),
	m_y(y),
	m_w(w),
	m_h(h)
{
}

LevelObject::~LevelObject()
{
}

void LevelObject::draw()
{
}

void LevelObject::setPosition(float x, float y)
{
	m_x = x;
	m_y = y;
}

float LevelObject::getX()
{
	cpVect p = cpBodyGetPos(m_pBody);
	return (float)p.x;
}

float LevelObject::getY()
{
	cpVect p = cpBodyGetPos(m_pBody);
	return (float)p.y;
}
