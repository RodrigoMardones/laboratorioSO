DIRO = ./build
DIRI = ./src
CC= gcc
CFLAGS = -g -msse3 

all: borrar crear

crear: 
	mkdir -p $(DIRO)
	$(CC) $(CFLAGS)  $(DIRI)/lab1.c -o $(DIRO)/lab1 -lm
	$(CC) $(CFLAGS)  $(DIRI)/vis.c -o $(DIRO)/vis -lm

borrar:
	rm -rf $(DIRO)/*
