khanAyeshaA1: khanAyeshaA1.o khanAyeshaA1Main.o
	gcc -Wall -std=c99 khanAyeshaA1.o khanAyeshaA1Main.c -o khanAyeshaA1
khanAyeshaA1.o: khanAyeshaA1.c givenA1.h
	gcc -Wall -std=c99 -c khanAyeshaA1.c
khanAyeshaA1Main.o: khanAyeshaA1Main.c givenA1.h
	gcc -Wall -std=c99 -c khanAyeshaA1Main.c
clean:
	rm *.o khanAyeshaA1
