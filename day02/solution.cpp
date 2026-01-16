#include "ProductId.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

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
        cout << "Failed to open " << infile << "for reading, exiting.\n";
        return 0;
    }

    string line;
    stringstream token_parser;

    getline(fin, line);
    fin.close();

    size_t prev_delim_pos = 0;
    size_t next_delim_pos = 0;
    unsigned long long answer = 0;
    unsigned long long p2_answer = 0;
    bool is_done_reading_input = false;

    while (true) {
        next_delim_pos = line.find(",", prev_delim_pos);
        string range_spec;
        if (next_delim_pos == string::npos) {
            is_done_reading_input = true;
            range_spec = line.substr(prev_delim_pos);
        } else {
            range_spec = line.substr(prev_delim_pos, next_delim_pos - prev_delim_pos);
        }

        prev_delim_pos = next_delim_pos + 1;
        // Parse lower and upper range
        size_t hyphen_delim_pos = range_spec.find("-");
        string lower_range_str = range_spec.substr(0, hyphen_delim_pos);
        string upper_range_str = range_spec.substr(hyphen_delim_pos+1);
        unsigned long lower_range = stoul(lower_range_str);
        unsigned long upper_range = stoul(upper_range_str);
        
        // Iterate over range specification
        for (unsigned long i = lower_range; i<= upper_range; i++) {
            ProductId product_id(i);
            if (product_id.is_invalid()) {
                answer += product_id.id;
            }

            if (product_id.is_invalid_p2()) {
                p2_answer += product_id.id;
            }
        }

        if (is_done_reading_input) {
            break;
        }
    }

    cout << "Part 1 Answer: " << answer << "\n";
    cout << "Part 2 Answer: " << p2_answer << "\n";

    return 0;
}