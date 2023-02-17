gryphflix: gryphflix.o main.o
	gcc -Wall -std=c99 gryphflix.o main.o -o gryphflix
gryphflix.o: gryphflix.c gryphflix.h
	gcc -Wall -std=c99 -c gryphflix.c
main.o: main.c gryphflix.h
	gcc -Wall -std=c99 -c main.c
clean:
	rm *.o gryphflix