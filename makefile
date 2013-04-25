OBJS = App.o Level.o LevelObject.o DynamicObject.o Player.o Block.o TextureManager.o
CXXFLAGS = -Wall -I/usr/include/libxml2 -I/usr/include/SDL -I/usr/include/GL
LDFLAGS = -L/usr/lib -L/usr/lib/i386-linux-gnu -lxml2 -lSDL -lSDL_image -lGL
CXX = clang++

fugue: $(OBJS)
	$(CXX) -o fugue $(CXXFLAGS) $(OBJS) $(LDFLAGS)

clean:
	rm -rf fugue *.o
