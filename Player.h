#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "DynamicObject.h"

class Player : public DynamicObject
{
	public:
		Player(float x, float y, cpSpace* space);
		virtual ~Player();
		virtual void draw();
		
		void run(float dir);
		void jump(float force);
		
		int collisionBegin(cpArbiter* arb, cpSpace* space, void* unused);
		void collisionEnd(cpArbiter* arb, cpSpace* space, void* unused);
};

#endif
