#include <fstream>
#include <iostream>
#include <vector>

#include "PaperRollGrid.hpp"

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
    PaperRollGrid paper_roll_grid;

    while (getline(fin, line)) {
        paper_roll_grid.append_row(line);
    }

    vector<GridPosition> accessible_roll_positions = paper_roll_grid.list_accessible_roll_positions();

    cout << "Part 1 Answer: " << accessible_roll_positions.size() << "\n";

    unsigned long part_2_answer = 0;
    while (true) {
        accessible_roll_positions = paper_roll_grid.list_accessible_roll_positions();
        if (accessible_roll_positions.size() == 0) {
            break;
        }
        part_2_answer += accessible_roll_positions.size();
        paper_roll_grid.remove_roll_positions(accessible_roll_positions);
    }

    cout << "Part 2 Answer: " << part_2_answer << "\n";
}