all:final
	rm -f *.o
final:main
	gcc main.o exec.o menu.o quick.o insertion.o -o tp -lm
dbug:main
	gcc main.o exec.o menu.o quick.o insertion.o -o tp -lm -Wall -g
main:exec
	gcc -c exec.c -lm -Wall
exec:menu
	gcc -c main.c -lm -Wall
menu:quick
	gcc -c menu.c -lm -Wall
quick:insertion
	gcc -c quick.c -lm -Wall
insertion:limpar
	gcc -c insertion.c -lm -Wall
limpar:
	clear||cls
clean_erro:
	rm -f tp *.o
clean:
	rm -f tp *.txt
