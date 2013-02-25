#ifndef _BLOCK_H_
#define _BLOCK_H_

#include "LevelObject.h"
#include "Globals.h"

class Block : public LevelObject
{
    public:
        Block();
        virtual ~Block();
        Block(float x, float y, float w, float h, BlockType type, const char* textureName);
        
        virtual void draw();
    
    
    private:
        BlockType m_type;
        const char* m_pTextureName;
};


#endif
