#include "DynamicObject.h"

DynamicObject::DynamicObject() :
	m_vx(0),
	m_vy(0)
{
}

DynamicObject::~DynamicObject()
{
}

void DynamicObject::setSpeed(float vx, float vy)
{
	m_vx = vx;
	m_vy = vy;
}
