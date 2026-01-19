#include "BatteryBank.hpp"

#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    if (argc != 2) {
        cout << "Usage: ./solution input.txt\n";
        return 0;
    }

    ifstream fin;
    string infile = argv[1];
    fin.open(infile, fstream::in);

    if (!fin.is_open()) {
        cout << "Failed to open " << infile << "for reading, exiting...\n";
        return 0;
    }

    string line;
    unsigned long long p1_answer = 0;    
    while (getline(fin, line)) {
        BatteryBank battery_bank(line);
        p1_answer += battery_bank.compute_max_joltage();
    }

    fin.close();
    cout << "Day 3, Part 1 Answer is " << p1_answer << "\n";

    return 0;
}