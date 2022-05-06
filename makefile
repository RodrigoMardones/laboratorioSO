DIRO = ./build
DIRI = ./src
FILE = ./src/uvplaneco1.csv
CC= gcc
CFLAGS = -g

all: borrar crear

crear: 
	mkdir -p $(DIRO)
	$(CC) $(CFLAGS)  $(DIRI)/lab1.c -o $(DIRO)/lab1 -lm
	$(CC) $(CFLAGS)  $(DIRI)/vis.c -o $(DIRO)/vis -lm

borrar:
	rm -rf $(DIRO)/*

run-lab1:
	./build/lab1
run-vis:
	./build/vis

main:
	rm -rf build/*
	mkdir -p build
	gcc src/lab1.c -o build/lab1.out
run-main:
	./build/lab1.out -i $(FILE)