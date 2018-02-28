all:final
	rm -f *.o
final:main
	gcc main.o menu.o funcoes.o arvore.o -o tp -lm
dbug:main
	gcc main.o menu.o funcoes.o arvore.o -o tp -lm -Wall -g
main:menu
	gcc -c main.c -lm -Wall
menu:funcoes
	gcc -c menu.c -lm -Wall
funcoes:arvore
	gcc -c funcoes.c -lm -Wall
arvore:limpar
	gcc -c arvore.c -lm -Wall
limpar:
	clear||cls
clean_erro:
	rm -f tp *.o
clean:
	rm -f tp *.o
