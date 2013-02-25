.PHONY: clean test

all: bin/shell

bin/shell: $(wildcard *.cpp)
	mkdir -p bin
	g++ -std=c++0x $^ -o bin/shell

clean:
	rm -f *.o bin/*

test: bin/shell
	./bin/shell
