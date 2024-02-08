OBJS = src/main.cpp src/RenderWindow.cpp
CC = g++
COMPILER_FLAGS = -w -g
LINKER_FLAGS = -lSDL2 -lSDL2_image
OBJ_NAME = Game

all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)