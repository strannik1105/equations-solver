TARGET = quadratic-equation

CC = gcc
CFLAGS = -Wall
CPPFLAGS = -I.
LIBS = -lm

SOURCES = \
	src/main.c \
	src/common/alloc.c \
	src/common/list.c \
	src/common/cmd.c \
	src/common/func_result.c \
	src/common/utils.c \
	src/equations/quadratic/quadratic_equation.c \
	src/equations/linear/linear_equation.c

OBJECTS = $(SOURCES:.c=.o)


all: $(SOURCES) $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(OBJECTS) -o $@ $(LIBS)


clean:
	rm -rf $(OBJECTS) $(TARGET)
