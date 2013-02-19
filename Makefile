SRC=$(wildcard utils/*.cpp) $(wildcard commands/*.cpp)
.PHONY: clean test

all: bin/shell

bin/shell: shell.cpp $(SRC)
	mkdir -p bin
	g++ $^ -o bin/shell

clean:
	rm -f *.o bin/*

test: bin/shell
	./bin/shell
