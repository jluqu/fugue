OBJS = App.o Level.o LevelObject.o LevelXmlParser.o DynamicObject.o Player.o Block.o \
	TextureManager.o ObjectFactory.o StaticObject.o
CHIPMUNK_PATH=/opt/Chipmunk-6.1.4
CXXFLAGS = -Wall -I/usr/include/libxml2 -I/usr/include/SDL -I/usr/include/GL -I$(CHIPMUNK_PATH)/include
LDFLAGS = -L/usr/lib -L/usr/lib/i386-linux-gnu -L$(CHIPMUNK_PATH)/lib -lxml2 -lSDL -lSDL_image -lGL \
	-lchipmunk -Wl,-rpath,$(CHIPMUNK_PATH)/lib
CXX = clang++
# -g3 -O0 -ggdb

fugue: $(OBJS)
	$(CXX) -o fugue $(CXXFLAGS) $(OBJS) $(LDFLAGS)

clean:
	rm -rf fugue *.o
