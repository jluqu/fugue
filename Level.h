#ifndef _LEVEL_H_
#define _LEVEL_H_

#include <chipmunk.h>
#include <vector>

#include "LevelObject.h"
#include "Player.h"

class Level
{
    public:
        Level();
        ~Level();
        void draw();
        void clear();
        
        bool loadFromXml(const char* filename);
        
        void setGravity(float g_x, float g_y);
        cpSpace* getSpace();

		void addObject(LevelObject* obj);
		void setPlayerPosition(float x, float y);
		
		void updateActions(bool leftDown, bool rightDown, bool upDown, bool downDown, bool spaceDown);

    private:
        std::vector<LevelObject*> m_objList;
        
		Player* m_pPlayer;
        cpSpace* m_pSpace;
};

#endif
