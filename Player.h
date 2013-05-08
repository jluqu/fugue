#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "DynamicObject.h"

class Player : public DynamicObject
{
	public:
		Player(float x, float y);
		virtual ~Player();
		virtual void draw();
};

#endif
