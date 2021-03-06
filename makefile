DIRO = ./build
DIRI = ./src
CC= gcc
CFLAGS = -g -msse3 

all: borrar crear

crear: 
	mkdir -p $(DIRO)
	$(CC) $(DIRI)/lab1.c -o $(DIRO)/lab1 -lm
	$(CC) $(DIRI)/vis.c -o $(DIRO)/vis -lm

borrar:
	rm -rf $(DIRO)/*

test:
	./build/lab1 -i uvplaneco1.csv -o propiedades.txt -d 100 -n 3 -b
