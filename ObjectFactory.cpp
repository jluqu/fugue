#include <string.h>

#include "ObjectFactory.h"
#include "Block.h"


Block* ObjectFactory::buildBlock(const char* type, float x, float y, float w, float h, Level* level)
{
	if (strcmp(type, "solidBlue") == 0)
	{
		return new Block(x, y, w, h, level->getSpace(), SOLID, "blue", TILE);
	}
	if (strcmp(type, "solidRed") == 0)
	{
		return new Block(x, y, w, h, level->getSpace(), SOLID, "red", TILE);
	}
	return NULL;
}
