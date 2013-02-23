#ifndef _BLOCK_H_
#define _BLOCK_H_

#include "LevelObject.h"
#include "Globals.h"

class Block : public LevelObject {
    public:
        Block();
        virtual ~Block();
        Block(float x_in, float y_in, float w_in, float h_in, BlockType type_in, const char* texture_name_in);
        
        virtual void draw();
    
    
    private:
        BlockType type;
        const char* texture_name;
};


#endif
