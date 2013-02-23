#include <vector>
#include <GL/gl.h>

#include "Level.h"
#include "LevelObject.h"
#include "Block.h"

Level::Level() {
    int oddEven = 0;
    for (float x = -5.0; x < 5.0; x += 1.0) {
        float y = 0.0;
        float w = 1.0, h = 1.0;
        const char* tex = "test";
        if (oddEven == 1) {
            tex = "test2";
        }
        
        LevelObject* b = new Block(x, y, w, h, SOLID, tex);
        objList.push_back(b);
        oddEven = (oddEven + 1) % 2;
    }
}

Level::~Level() {
    while (!objList.empty()) {
        delete objList.back();
        objList.pop_back();
    }
}

void Level::draw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    for (std::vector<LevelObject*>::iterator it = objList.begin(); it != objList.end(); ++it) {
        (*it)->draw();
    }
}
