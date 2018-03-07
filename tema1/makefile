all: tema1

bin/main.o: src/main.cpp
	g++ -c -o bin/main.o src/main.cpp
tema1: bin/main.o
	g++ -o tema1 bin/main.o

clean: rm bin/*.o tema1