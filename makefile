managementSys: managementSys.o main.o
	gcc -Wall -std=c99 managementSys.o main.c -o managementSys
managementSys.o: functions.c heaader.h
	gcc -Wall -std=c99 -c functions.c
main.o: main.c header.h
	gcc -Wall -std=c99 -c main.c
clean:
	rm *.o managementSys
