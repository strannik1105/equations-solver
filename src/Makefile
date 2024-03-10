TARGET = quadratic-equation

CC = gcc
CFLAGS = -c -Wall

all: $(TARGET)

$(TARGET): main.o some_test.o
	$(CC) main.o some_test.o -o $(TARGET)

main.o: main.c
	$(CC) $(CFLAGS) main.c

some_test.o:
	$(CC) $(CFLAGS) custom_module/some_test.c

clean:
	rm -rf *.o $(TARGET)