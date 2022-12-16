all: game.e

game.e: main.o util.o features.o output.o
	gcc -o game.e main.o util.o features.o output.o

main.o: main.c
	gcc -o main.o -c main.c

util.o: util.c
	gcc -o util.o -c util.c

features.o: features.c
	gcc -o features.o -c features.c

output.o: output.c
	gcc -o output.o -c output.c

clean:
	rm -f *.o game.e