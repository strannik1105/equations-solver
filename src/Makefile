TARGET = quadratic-equation

CC = gcc
CFLAGS = -c -Wall

SOURCES = main.c custom_module/some_test.c
OBJECTS = $(SOURCES:.c=.o)


all: $(SOURCES) $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

clean:
	rm -rf $(OBJECTS) $(TARGET)
