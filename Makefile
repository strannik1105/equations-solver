TARGET = quadratic-equation

CC = gcc
CFLAGS = -c -Wall

SOURCES = src/main.c src/common/alloc.c src/equations/quadratic/quadratic_equation.c src/equations/linear/linear_equation.c
OBJECTS = $(SOURCES:.c=.o)


all: $(SOURCES) $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

clean:
	rm -rf $(OBJECTS) $(TARGET)
