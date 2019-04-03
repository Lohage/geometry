FLAGS := -std=c99

all: main.o functions.o
	gcc -Wall main.o functions.o -o main -lm $(FLAGS)
main.o: main.c
	gcc -Wall -c main.c -o main.o $(FLAGS)
functions.o: functions.c
	gcc -Wall -c functions.c -o functions.o $(FLAGS)

clean:
	rm -f *.o
	rm -f main
