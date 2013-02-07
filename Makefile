SRC=$(wildcard utils/*.c) $(wildcard commands/*.c)
.PHONY: clean test

all: bin/shell

bin/shell: shell.c $(SRC)
	mkdir -p bin
	gcc $^ -o bin/shell

clean:
	rm -f *.o bin/*

test: bin/shell
	./bin/shell
