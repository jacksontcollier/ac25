all: solution

solution: solution.o ProductId.o
	g++ ProductId.o solution.o -o solution

solution.o: solution.cpp ProductId.hpp
	g++ -Wall -c solution.cpp -o solution.o

ProductId.o: ProductId.hpp ProductId.cpp
	g++ -Wall -c ProductId.cpp -o ProductId.o