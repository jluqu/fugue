#ifndef _LEVEL_H_
#define _LEVEL_H_

#include "LevelObject.h"
#include <vector>

class Level
{
    public:
        Level();
        ~Level();
        void draw();
        void clear();
        
        bool loadFromXml(const char* filename);

    private:
        std::vector<LevelObject*> m_objList;
};

#endif
