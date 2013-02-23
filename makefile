OBJS = App.o Level.o LevelMap.o LevelObject.o DynamicObject.o Player.o Block.o \
		TextureManager.o
CXXFLAGS = -Wall
LDFLAGS = -lSDL -lSDL_image -lGL
CXX = clang++

gldemo: $(OBJS)
	$(CXX) -o gldemo $(CXXFLAGS) $(OBJS) $(LDFLAGS)

clean:
	rm -rf gldemo *.o
