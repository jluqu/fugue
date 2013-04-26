#include <GL/gl.h>
#include "Block.h"
#include "Globals.h"
#include "TextureManager.h"

Block::Block() :
    LevelObject(),
    m_type(SOLID),
    m_pTextureName("")
{
}

Block::Block(float x, float y, float w, float h, BlockType type, const char* textureName) :
    LevelObject(x, y, w, h),
    m_type(type),
    m_pTextureName(textureName)
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
        glTexCoord2f(0, 0); glVertex3f(m_x,       m_y,       0);
        glTexCoord2f(1, 0); glVertex3f(m_x + m_w, m_y,       0);
        glTexCoord2f(1, 1); glVertex3f(m_x + m_w, m_y + m_h, 0);
        glTexCoord2f(0, 1); glVertex3f(m_x,       m_y + m_h, 0);
    glEnd();
}

BlockType Block::getType()
{
	return m_type;
}
