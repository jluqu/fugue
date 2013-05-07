#include <chipmunk.h>
#include <stdio.h>
#include "StaticObject.h"
#include "LevelObject.h"

StaticObject::StaticObject(float x, float y, float w, float h) :
	LevelObject(x, y, w, h)
{
	m_pBody = cpBodyNewStatic();
	m_pShape = cpBoxShapeNew(m_pBody, (cpFloat)w, (cpFloat)h);
	setPosition(x, y);
}

StaticObject::~StaticObject()
{
	cpShapeFree(m_pShape);
	cpBodyFree(m_pBody);
}

void StaticObject::draw()
{
}

void StaticObject::setPosition(float x, float y)
{
	m_x = x;
	m_y = y;
	cpBodySetPos(m_pBody, cpv((cpFloat)m_x, (cpFloat)m_y));
}

void StaticObject::setSize(float w, float h)
{
	////cpBoxShapeDestroy(m_pShape);
	//cpBoxShapeInit(m_pShape, m_pBody, (cpFloat)w, (cpFloat)h);
	printf("StaticObject::setSize isn't implemented yet! Need to figure out how to do this!\n");

}
