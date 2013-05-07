#include <GL/gl.h>
#include <chipmunk.h>

#include "Block.h"
#include "TextureManager.h"
#include "StaticObject.h"

Block::Block(float x, float y, float w, float h, BlockType type, const char* textureName, TextureStyle textureStyle) :
    StaticObject(x, y, w, h),
    m_type(type),
    m_pTextureName(textureName),
    m_textureStyle(textureStyle)
{
}

Block::~Block()
{
}

void Block::draw()
{
    TextureManager::getInstance()->selectTexture(m_pTextureName);
    
    glBegin(GL_QUADS);
    /*
        glColor3f(1, 0, 0); glVertex3f(m_x,       m_y,       0);
        glColor3f(1, 1, 0); glVertex3f(m_x + m_w, m_y,       0);
        glColor3f(1, 0, 1); glVertex3f(m_x + m_w, m_y + m_h, 0);
        glColor3f(1, 1, 1); glVertex3f(m_x,       m_y + m_h, 0);
    */
    
        cpVect pos = cpBodyGetPos(m_pBody);
        // TODO: figure out how to pull w and h from m_pShape??
        
        if (m_textureStyle == STRETCH)
        {
            glTexCoord2f(0, 1); glVertex3f(pos.x,       pos.y,       0);
            glTexCoord2f(1, 1); glVertex3f(pos.x + m_w, pos.y,       0);
            glTexCoord2f(1, 0); glVertex3f(pos.x + m_w, pos.y + m_h, 0);
            glTexCoord2f(0, 0); glVertex3f(pos.x,       pos.y + m_h, 0);
        }
        else if (m_textureStyle == TILE)
        {
            glTexCoord2f(0,   m_h);   glVertex3f(pos.x,       pos.y,       0);
            glTexCoord2f(m_w, m_h);   glVertex3f(pos.x + m_w, pos.y,       0);
            glTexCoord2f(m_w, 0); glVertex3f(pos.x + m_w, pos.y + m_h, 0);
            glTexCoord2f(0,   0); glVertex3f(pos.x,       pos.y + m_h, 0);
        }
    glEnd();
}

BlockType Block::getType()
{
    return m_type;
}
