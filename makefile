DIRO = ./build
DIRI = ./src
CC= gcc
CFLAGS = -g -msse3 

all: borrar crear

crear: 
	mkdir -p $(DIRO)
	$(CC) $(CFLAGS) $(DIRI)/lab1.c -lm $(DIRI)/vis.c -lm -o $(DIRO)/lab1

borrar:
	rm -rf $(DIRO)/*

test:
	./build/lab1 -i uvplaneco1.csv -o propiedades.txt -d 100 -n 3