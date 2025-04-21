out: clean compile execute

compile: main.cpp product.cpp MurmurHash3.cpp
	g++ -g -Wall -std=c++14 main.cpp product.cpp MurmurHash3.cpp xxhash.c -o mainexe

execute: mainexe
	./mainexe

clean:
	rm -f mainexe