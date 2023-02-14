program: program.c matrix.o factor.o
	gcc program.c matrix.o factor.o -o program
matrix.o: matrix.c
	gcc -c matrix.c -o matrix.o
factor.o: factor.c
	gcc -c factor.c -o factor.o
clean:
	rm *.o
	rm program