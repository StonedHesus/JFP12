CC=gcc
CFLAGS=		-Wall -g -pedantic

ALL = test tetris

all:$(ALL)

test: test.o io.o game-components.o 
tetris: tetris.o game-components.o io.o second-task.o

test.o: test.c io.o first-task.o
io.o: io.c io.h game-components.o first-task.o
first-task.o: first-task.c first-task.h 
second-task.o: second-task.c second-task.h	game-components.o
tetris.o: tetris.c game-components.h io.o second-task.o
game-components.o: game-components.c game-components.h 

clean:
	rm -rf *~
cleanall:
	rm  -rf *~  *.o  $(ALL)