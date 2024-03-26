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

TESTS = \
	test/common \
	test/quadratic_equation \
	test/linear_equation

all: $(SOURCES) $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(OBJECTS) -o $@ $(LIBS)

check-clean:
	rm -rf $(TESTS:=/log.txt)

check: all check-clean
	for test in $(TESTS) ; do \
        ./$$test/in.txt > $$test/log.txt; \
        echo $$(diff -q $$test/log.txt $$test/out.txt); \
    done

clean: check-clean
	rm -rf $(OBJECTS) $(TARGET)
