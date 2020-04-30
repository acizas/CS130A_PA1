# Makefile

#CXX=clang++
CXX=g++

#CXXFLAGS = -std=c++11 =Wall -Wextra -Werror

prog1Tests: prog1Tests.o prog1.o tddFuncs.o
	${CXX} $^ -o $@

tests: Tests
	./prog1Tests

clean:
	/bin/rm -f *.o
