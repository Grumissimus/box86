FILES =

OBJS = box86.cpp $(FILES)

CC = g++

COMPILER_FLAGS = -Wall -Wextra -pedantic -std=c++17 

LINKER_FLAGS = -lm

OBJ_NAME = box86

all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
	
debug : $(OBJS)
	$(CC) $(OBJS) -g -O0 $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)