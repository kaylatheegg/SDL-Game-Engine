#CSRC specifies which files we need to compile
#engine components, just for clarity sake

RENDER = engine/source/renderer/init.c \
engine/source/renderer/render.c \
engine/source/renderer/texture.c

OBJECT = engine/source/object/init.c  \
engine/source/object/object.c \
engine/source/object/movement.c

RUNTIME = engine/source/runtime/clean.c \
engine/source/runtime/main.c

LEVEL = engine/source/level/init.c \
engine/source/level/level.c

PLAYER = engine/source/player/init.c \
engine/source/player/player.c 

CSRC = $(RENDER) $(OBJECT) $(RUNTIME) $(LEVEL) $(PLAYER)


#LCC is our linux compiler
LCC = gcc

WCC = x86_64-w64-mingw32-gcc-win32

#LCFLAGS are our compile time flags for linux
LCFLAGS = -lm -lSDL2 -lSDL2_image -Werror


#WCFLAGS are our compile time flags for windows
WCFLAGS = -lmingw32 -lm -lSDL2main -lSDL2 -lSDL2_image -Werror 

a.out : $(CSRC)
	$(LCC) $(CSRC) $(LCFLAGS)

a.exe : $(CSRC)
	$(WCC) $(CSRC) $(WCFLAGS)