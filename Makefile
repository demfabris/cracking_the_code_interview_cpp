# Hello world

CC=g++

all: main.o chapter_one.o chapter_two.o
	$(CC) main.o chapter_one.o chapter_two.o -o cci

main.o: main.cpp
	$(CC) -c main.cpp

chapter_one.o: chapter_one.cpp chapter_one.h
	$(CC) -c chapter_one.cpp

chapter_two.o: chapter_two.cpp chapter_two.h
	$(CC) -c chapter_two.cpp

clean:
	rm -rf *.o
