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

TESTS = test/quadratic_equation

all: $(SOURCES) $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(OBJECTS) -o $@ $(LIBS)

check-clean:
	rm -rf $(TESTS:=.tst_log)

check: all check-clean
	for test in $(TESTS) ; do \
        ./$$test.tst_in > $$test.tst_log; 2>&1\
        diff -q $$test.tst_log $$test.tst_out ; \
    done

clean: check-clean
	rm -rf $(OBJECTS) $(TARGET)
