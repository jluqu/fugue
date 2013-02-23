#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "DynamicObject.h"

class Player : public DynamicObject {
    Player();
    virtual ~Player();
    virtual void draw();
};

#endif
