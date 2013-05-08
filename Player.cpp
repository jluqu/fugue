#include <GL/gl.h>
#include <chipmunk.h>

#include "Player.h"
#include "TextureManager.h"

Player::Player(float x, float y) :
	DynamicObject(x, y, 1.5, 1.5)
{
}

Player::~Player()
{
}

void Player::draw()
{
    TextureManager::getInstance()->selectTexture("player");
    
    glBegin(GL_QUADS);
        cpVect pos = cpBodyGetPos(m_pBody);
        // TODO: figure out how to pull w and h from m_pShape??
        
        glTexCoord2f(0, 1); glVertex3f(pos.x,       pos.y,       0);
        glTexCoord2f(1, 1); glVertex3f(pos.x + m_w, pos.y,       0);
        glTexCoord2f(1, 0); glVertex3f(pos.x + m_w, pos.y + m_h, 0);
        glTexCoord2f(0, 0); glVertex3f(pos.x,       pos.y + m_h, 0);

    glEnd();
}
