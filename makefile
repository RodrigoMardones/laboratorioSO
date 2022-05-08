DIRO = ./build
DIRI = ./src
CC= gcc
CFLAGS = -g -msse3 

all: borrar crear

crear: 
	mkdir -p $(DIRO)
	$(CC) $(DIRI)/lab1.c -o $(DIRO)/lab1.out

borrar:
	rm -rf $(DIRO)/*

test:
	./build/lab1.out -i uvplaneco1.csv -o propiedades.txt -d 100 -n 3