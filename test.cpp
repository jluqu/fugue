//#include "TextureManager.h"
//#include "GL/gl.h"
#include <stdio.h>

int main(int argc, char* argv[]) {
    //TextureManager::getInstance()->testSet("test1", 1);
    //TextureManager::getInstance()->testSet("test2", 2);
    //GLuint x = TextureManager::getInstance()->testGet("test2");
    //printf("Got %u\n", x);
    
    const char* x  = "Hello there";
    x = "Goodbye there";
    printf("String is: %s\n", x);
    return 0;
}
