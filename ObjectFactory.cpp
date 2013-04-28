#include <string.h>

#include "ObjectFactory.h"
#include "Block.h"


Block* ObjectFactory::buildBlock(const char* type, float x, float y, float w, float h)
{
	if (strcmp(type, "solidBlue") == 0)
	{
		return new Block(x, y, w, h, SOLID, "blue");
	}
	if (strcmp(type, "solidRed") == 0)
	{
		return new Block(x, y, w, h, SOLID, "red");
	}
	return NULL;
}
