.PHONY: clean test

all: bin/shelly

bin/shelly: $(wildcard *.cpp)
	mkdir -p bin
	g++ -W -Wall -Wextra -pedantic -std=c++0x $^ -o bin/shelly

clean:
	rm -f *.o bin/*

test: bin/shelly
	./bin/shelly
