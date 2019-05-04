prog:main.o personne.o jeu.o background.o 
	gcc main.o personne.o jeu.o background.o  -o prog -lSDL -lSDL_ttf -g
main.o:main.c
	gcc -c main.c -g
jeu.o:jeu.c
	gcc -c jeu.c -g
personne.o:personne.c
	gcc -c personne.c -g
background.o:background.c
	gcc -c background.c -g

clean:
	rm -fr *.o
mrproper:clean
	rm -f prog
