.PHONY: clean test

all: bin/shell

bin/shell: $(wildcard *.cpp)
	mkdir -p bin
	g++ $^ -o bin/shell

clean:
	rm -f *.o bin/*

test: bin/shell
	./bin/shell
