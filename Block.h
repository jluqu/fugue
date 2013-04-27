#ifndef _BLOCK_H_
#define _BLOCK_H_

#include "LevelObject.h"

enum BlockType
{
    SOLID,
    PLATFORM,
    BACKGROUND
};

class Block : public LevelObject
{
    public:
        Block();
        virtual ~Block();
        Block(float x, float y, float w, float h, BlockType type, const char* textureName);
        
        virtual void draw();
		BlockType getType();
    
    private:
        BlockType m_type;
        const char* m_pTextureName;
};

#endif
