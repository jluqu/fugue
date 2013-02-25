#include "LevelObject.h"

LevelObject::LevelObject() :
    m_x(0),
    m_y(0),
    m_w(1),
    m_h(1)
{
}

LevelObject::LevelObject(float x, float y, float w, float h) :
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

void LevelObject::setSize(float w, float h)
{
    m_w = w;
    m_h = h;
}
