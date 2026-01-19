all: solution

solution: solution.o BatteryBank.o
	g++ BatteryBank.o solution.o -o solution

solution.o: solution.cpp BatteryBank.hpp
	g++ -Wall -c solution.cpp -o solution.o

BatteryBank.o: BatteryBank.cpp BatteryBank.hpp
	g++ -Wall -c BatteryBank.cpp -o BatteryBank.o

