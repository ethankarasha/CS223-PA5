out: clean compile execute

compile: main.cpp product.cpp MurmurHash3.cpp
	g++ -g -Wall -std=c++14 main.cpp product.cpp MurmurHash3.cpp -o mainexe -lxxhash

execute: mainexe
	./mainexe

clean:
	rm -f mainexe