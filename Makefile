# Turn on debugging and extra warnings, but hide unused parameter warnings:
CXXFLAGS=-std=c++11 -g -Wall -Wextra -Wno-unused-parameter

all: list-tests vector-tests

test: all
	./list-tests
	./vector-tests

tests: all
	./list-tests
	./vector-tests

test-list: list-tests
	./list-tests

test-vector: vector-tests
	./vector-tests

# For more information on the magical make variables, see:
# https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html
list-tests: list-tests.o list.o test-functions.o
	${CXX} $(LDFLAGS) -o $@ $^

vector-tests: vector-tests.o vector.o test-functions.o
	${CXX} $(LDFLAGS) -o $@ $^

list-tests.o: tests.cpp | list.h
	${CXX} $(CXXFLAGS) -DTYPE=LinkedList -DWRAP=list -c -o $@ $^

vector-tests.o: tests.cpp | vector.h
	${CXX} $(CXXFLAGS) -DTYPE=Vector -DWRAP=vector -c -o $@ $^

clean:
	rm -f list-tests vector-tests *.o
