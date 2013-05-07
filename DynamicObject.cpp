#include "DynamicObject.h"


DynamicObject::DynamicObject(float x, float y, float w, float h) :
	LevelObject(x, y, w, h)
{
	m_pBody = cpBodyNewStatic();
	m_pShape = cpBoxShapeNew(m_pBody, (cpFloat)w, (cpFloat)h);
	setPosition(x, y);
}

DynamicObject::~DynamicObject()
{
	cpShapeFree(m_pShape);
	cpBodyFree(m_pBody);
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

