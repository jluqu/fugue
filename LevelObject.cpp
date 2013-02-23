#include "LevelObject.h"

LevelObject::LevelObject() :
    x(0),
    y(0),
    w(1),
    h(1)
{
}

LevelObject::LevelObject(float x_in, float y_in, float w_in, float h_in) :
    x(x_in),
    y(y_in),
    w(w_in),
    h(h_in)
{
}

LevelObject::~LevelObject() {
}

void LevelObject::draw() {
}

void LevelObject::setPosition(float x_in, float y_in) {
    x = x_in;
    y = y_in;
}

void LevelObject::setSize(float w_in, float h_in) {
    w = w_in;
    h = h_in;
}
