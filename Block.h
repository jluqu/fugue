#ifndef _BLOCK_H_
#define _BLOCK_H_

#include <chipmunk.h>
#include "StaticObject.h"

enum BlockType
{
    SOLID,
    PLATFORM,
    BACKGROUND
};

enum TextureStyle
{
	STRETCH,
	TILE
};

class Block : public StaticObject
{
    public:
		Block(float x, float y, float w, float h, cpSpace* space, BlockType type, const char* textureName, TextureStyle textureStyle);
        virtual ~Block();
        
        virtual void draw();
		BlockType getType();
    
    private:
        BlockType m_type;
        const char* m_pTextureName;
        TextureStyle m_textureStyle;
};

#endif
