all: solution

solution: solution.o PaperRollGrid.o
	g++ solution.o PaperRollGrid.o -o solution

solution.o: solution.cpp PaperRollGrid.hpp
	g++ -Wall -c solution.cpp -o solution.o

PaperRollGrid.o: PaperRollGrid.cpp PaperRollGrid.hpp
	g++ -Wall -c PaperRollGrid.cpp -o PaperRollGrid.o
