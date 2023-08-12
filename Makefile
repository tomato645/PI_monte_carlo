CC = g++

main: main.cpp
	$(CC) main.cpp -o main && ./main 5000 2 false

build: main.cpp
	$(CC) main.cpp -o main