output: main.o BST.o
	gcc main.o BST.o -o program

main.o: main.c
	gcc -c main.c

student.o: BST.c BST.h
	gcc -c BST.c

clean:
	rm *.o program
