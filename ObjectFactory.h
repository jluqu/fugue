#ifndef _OBJECT_FACTORY_H_
#define _OBJECT_FACTORY_H_

#include "Block.h"

class ObjectFactory
{
    public:
        static Block* buildBlock(const char* type, float x, float y, float w, float h);
        
};

#endif
