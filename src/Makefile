main: main.o some_test.o
	gcc main.o some_test.o -o main

main.o: main.c
	gcc -c main.c

some_test.o:
	gcc -c custom_module/some_test.c

clean:
	rm -rf *.o main