#include <string.h>
#include <stdio.h>
#include "ObjectFactory.h"
#include "Block.h"


Block* ObjectFactory::buildBlock(const char* type, float x, float y, float w, float h, Level* level)
{
	if (strcmp(type, "solidBlue") == 0)
	{
		return new Block(x, y, w, h, level->getSpace(), SOLID, "blue", TILE);
	}
	else if (strcmp(type, "solidRed") == 0)
	{
		return new Block(x, y, w, h, level->getSpace(), SOLID, "red", TILE);
	}
	else if (strcmp(type, "concrete_beveled") == 0)
	{
		return new Block(x, y, w, h, level->getSpace(), SOLID, "concrete_beveled", TILE);
	}	
	// TODO: this doesn't work... WHY?
	else
	{
		printf("unrecognized block type %s", type);
	}
	return NULL;
}
