#include <chipmunk.h>
#include <stdio.h>
#include "Globals.h"
#include "Player.h"
#include "TextureManager.h"

Player::Player(float x, float y, cpSpace* space) :
	DynamicObject(x, y, 1, 1.5, 5, space)
{
	//cpFloat moment = cpMomentForBox(m_mass, 1.5, 1.5);
	cpFloat moment = INFINITY;  // Infinite moment of inertia - don't let player rotate
	
	m_pBody = cpSpaceAddBody(space, cpBodyNew(m_mass, moment));
	m_pShape = cpSpaceAddShape(space, cpBoxShapeNew(m_pBody, 1, 1.5));
	m_pShape->collision_type = PLAYER_TYPE;
	setPosition(x, y);
	
	cpShapeSetFriction(m_pShape, 0.7);
	cpShapeSetElasticity(m_pShape, 0.0);
}

Player::~Player()
{
	cpShapeFree(m_pShape);
	cpBodyFree(m_pBody);
}

void Player::draw()
{
    TextureManager::getInstance()->selectTexture("player");
    
	DynamicObject::draw();
}

void Player::run(float dir)
{
	if (dir > 0)
	{
		m_facingRight = true;
	}
	else
	{
		m_facingRight = false;
	}
		
	cpBodyApplyImpulse(m_pBody, cpv(dir, 0.0), cpv(0, 0));
}

void Player::jump(float force)
{
	cpBodyApplyImpulse(m_pBody, cpv(0.0, force), cpvzero);
}


