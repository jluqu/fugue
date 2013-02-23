#include <GL/gl.h>
#include "Block.h"
#include "Globals.h"
#include "TextureManager.h"

Block::Block() :
    LevelObject(),
    type(SOLID),
    texture_name("")
{

}

Block::Block(float x_in, float y_in, float w_in, float h_in, BlockType type_in, const char* texture_name_in) :
    LevelObject(x_in, y_in, w_in, h_in),
    type(type_in),
    texture_name(texture_name_in)
{
}

Block::~Block() {
}

void Block::draw() {
	
    TextureManager::getInstance()->selectTexture(texture_name);
    
    glBegin(GL_QUADS);
    /*
        glColor3f(1, 0, 0); glVertex3f(x, y, 0);
        glColor3f(1, 1, 0); glVertex3f(x+w, y, 0);
        glColor3f(1, 0, 1); glVertex3f(x+w, y+h, 0);
        glColor3f(1, 1, 1); glVertex3f(x, y+h, 0);
    */
        glTexCoord2f(0, 0); glVertex3f(x, y, 0);
        glTexCoord2f(1, 0); glVertex3f(x+w, y, 0);
        glTexCoord2f(1, 1); glVertex3f(x+w, y+h, 0);
        glTexCoord2f(0, 1); glVertex3f(x, y+h, 0);
    glEnd();
}
