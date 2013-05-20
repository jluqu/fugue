#include <chipmunk.h>
#include <stdio.h>
#include "StaticObject.h"
#include "LevelObject.h"

StaticObject::StaticObject(float x, float y, float w, float h, cpSpace* space) :
	LevelObject(x, y, w, h, space)
{
	
	cpVect verts[] = {cpv(0, 0), cpv(0, h), cpv(w, h), cpv(w, 0)};
	m_pShape = cpPolyShapeNew(cpSpaceGetStaticBody(space), 4, verts, cpv(x, y));
	cpShapeSetFriction(m_pShape, 0.8);
	cpShapeSetElasticity(m_pShape, 0.0);
	cpSpaceAddShape(space, m_pShape);
	
}

StaticObject::~StaticObject()
{
	cpShapeFree(m_pShape);
}

void StaticObject::draw()
{
}

