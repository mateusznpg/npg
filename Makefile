drzewo: main.o drzewo.o
	gcc main.o drzewo.o -o drzewo

main.o: main.c
	gcc -c -Wall main.c

drzewo.o: drzewo.c
	gcc -c -Wall drzewo.c

open:
	./drzewo
clean:
	rm -rf *o drzewo
