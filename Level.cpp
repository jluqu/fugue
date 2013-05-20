#include <vector>
#include <GL/gl.h>
#include <chipmunk.h>
#include <stdio.h>

#include "Globals.h"
#include "Level.h"
#include "LevelObject.h"
#include "Block.h"
#include "LevelXmlParser.h"


Level::Level()
{
    // Create an empty space.
    m_pSpace = cpSpaceNew();
    
    setGravity(0, -50);
    
    m_pPlayer = new Player(0, 0, m_pSpace);
    /*
	cpSpaceAddCollisionHandler(m_pSpace,
                               PLAYER_TYPE,
                               BLOCK_TYPE,
	                           (cpCollisionBeginFunc)collisionBegin,
	                           NULL,
	                           (cpCollision
	                           (cpCollisionSeparateFunc)collisionEnd,
	                           m_pPlayer);*/
}

Level::~Level()
{
    clear();
    cpSpaceFree(m_pSpace);
}

void Level::clear()
{
    while (!m_objList.empty())
    {
        delete m_objList.back();
        m_objList.pop_back();
    }
}

void Level::setGravity(float g_x, float g_y)
{
    if (m_pSpace != NULL) {
        cpVect grav = cpv((cpFloat)g_x, (cpFloat)g_y);
        cpSpaceSetGravity(m_pSpace, grav);
    }
}

cpSpace* Level::getSpace()
{
    return m_pSpace;
}

void Level::draw()
{
    cpSpaceStep(m_pSpace, 1.0/60.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glTranslatef(-(m_pPlayer->getX()), -(m_pPlayer->getY()), 0);
    for (std::vector<LevelObject*>::iterator it = m_objList.begin(); it != m_objList.end(); ++it)
    {
        (*it)->draw();
    }
    m_pPlayer->draw();
}

bool Level::loadFromXml(const char* filename)
{
    // remove anything currently in the level
    clear();
    
    return LevelXmlParser::getInstance()->load(filename, this);
}

void Level::addObject(LevelObject* obj)
{
    m_objList.push_back(obj);
}

void Level::setPlayerPosition(float x, float y)
{
    m_pPlayer->setPosition(x, y);
}

void Level::updateActions(bool leftDown, bool rightDown, bool upDown, bool downDown, bool spaceDown)
{
    float vx = m_pPlayer->getXVel();
    //float vy = m_pPlayer->getYVel();
    if (leftDown && vx > -15.0) {
        m_pPlayer->run(-7.0);
    }
    if (rightDown && vx < 15.0) {
        m_pPlayer->run(7.0);
    }
    if (spaceDown && m_pPlayer->isGrounded()) {
        m_pPlayer->jump(120);
    }
}
/*
int static collisionBegin(cpArbiter* arb, cpSpace* space, void* player)
{
    Player* p = (Player*)player;
    cpVect n = cpArbiterGetNormal(arb, 0);
    if (n.y < 0)
    {
        printf("Player is grounded\n");
        p->setGrounded(true);
    }
    
	return 1;
}

void static collisionEnd(cpArbiter* arb, cpSpace* space, void* player)
{
    Player* p = (Player*)player;
//    cpVect n = cpArbiterGetNormal(arb, 0);
 //   if (n.y < 0)
  //  {
        printf("Player is in the air!\n");
        p->setGrounded(false);
    //}
}
*/
