#ifndef _LEVELMAP_H_
#define _LEVELMAP_H_

class LevelMap
{
    public:
        LevelMap();
        
        bool load(const char* filename);
        void draw();
};

#endif
