#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "DynamicObject.h"

class Player : public DynamicObject
{
	public:
		Player(float x, float y, cpSpace* space);
		virtual ~Player();
		virtual void draw();
		
		float getXVel();
		float getYVel();
		//void setVelocity(float vx, float vy);
		
		void run(float dir);
		void jump(float force);
		
	private:
		bool m_facingRight;
};

#endif
