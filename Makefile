# Hello world

CC=g++
LIBS=lib/*.h
INC=inc/*.cpp

all: main.o chapter_one.o chapter_two.o data_structures.o
	$(CC) main.o chapter_one.o chapter_two.o data_structures.o -o cci
	rm -rf *.o

main.o: main.cpp
	$(CC) -c main.cpp

data_structures.o: $(INC) $(LIBS)
	$(CC) -c $(INC)

chapter_one.o: chapter_one.cpp $(LIBS)
	$(CC) -c chapter_one.cpp

chapter_two.o: chapter_two.cpp $(LIBS)
	$(CC) -c chapter_two.cpp

clean:
	rm -rf *.o

uninstall:
	rm -rf cci
