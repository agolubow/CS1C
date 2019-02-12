CC = g++
FLAGS = -std=c++14 -Wall -g
OBJS = cardDeckClass.o

all:hw02

hw02:hw02.cpp cardDeckClass.o

	$(CC) $(FLAGS) hw02.cpp -o hw02 $(OBJS)

cardDeckClass.o: cardDeckClass.cpp cardDeckClass.h

	$(CC) $(FLAGS) -c cardDeckClass.cpp -o cardDeckClass.o

clean:

	rm *.o hw02 hw02.tar

tar:

	tar cf hw02.tar hw02.scr Makefile hw02.cpp cardDeckClass.h cardDeckClass.cpp