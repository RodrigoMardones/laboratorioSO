DIRO = ./build
DIRI = ./src
FILE = ./uvplaneco1.csv
CC= gcc
CFLAGS = -g

all: borrar crear

crear: 
	mkdir -p $(DIRO)
	$(CC) $(CFLAGS)  $(DIRI)/lab1.c -o $(DIRO)/lab1 -lm
	$(CC) $(CFLAGS)  $(DIRI)/vis.c -o $(DIRO)/vis -lm

borrar:
	rm -rf $(DIRO)/*

main:
	rm -rf build/*
	mkdir -p build
	gcc src/lab1.c -o build/lab1.out
run-main:
	./build/lab1.out -i $(FILE)
vis:
	gcc src/vis.c -o build/vis.out

run-vis:
	./build/vis.out