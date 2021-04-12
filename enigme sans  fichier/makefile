prog: enig.o  main.o
	gcc -o prog enig.o  main.o -lSDL -lSDL_ttf -lSDL_mixer -lSDL_image
main.o : main.c enig.h
	gcc -c main.c
perso.o : enigme.c enig.h
	gcc -c  enigme.c
