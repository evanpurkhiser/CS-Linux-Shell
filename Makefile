.PHONY: clean test

all: bin/shell

bin/shell: shell.c
	mkdir -p bin
	gcc shell.c -o bin/shell

clean:
	rm -f *.o bin/*

test: bin/shell
	./bin/shell
