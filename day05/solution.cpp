#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef pair<unsigned long long, unsigned long long> IdRange;
// Print out all of the fresh ingredient id's
void print_fresh_ids(const set<unsigned long>& fresh_ids);

// Print out all of the available ingredient id's
void print_ingredient_ids(const vector<unsigned long>& ingredient_ids);

int main(int argc, char* argv[])
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
    bool is_reading_fresh_ranges = true;
    vector<IdRange> fresh_ingredient_ranges;
    vector<unsigned long long> ingredient_ids;
    unsigned long long num_fresh_ingredients = 0;

    while (getline(fin, line)) {
        if (line.empty()) {
            is_reading_fresh_ranges = false;
            continue;
        } else if (is_reading_fresh_ranges) {
            // Parse start and end id from range
            size_t hyphen_pos = line.find('-');
            string start_id_str = line.substr(0, hyphen_pos);
            string end_id_str = line.substr(hyphen_pos+1);
            unsigned long start_id = stoul(start_id_str);
            unsigned long end_id = stoul(end_id_str);
            fresh_ingredient_ranges.push_back(make_pair(start_id, end_id));
        } else {
            ingredient_ids.push_back(stoul(line));
        }
    }

    cout << "Number of Fresh Ingredient Ranges: " << fresh_ingredient_ranges.size() << "\n";
    cout << "Number of Fresh Ingredient Id's: " << ingredient_ids.size() << "\n";

    sort(fresh_ingredient_ranges.begin(), fresh_ingredient_ranges.end());

    for (auto& ingredient_id : ingredient_ids) {
        for (auto& id_range : fresh_ingredient_ranges) {
            if (ingredient_id >= id_range.first && ingredient_id <= id_range.second) {
                num_fresh_ingredients++;
                break;
            }
        }
    }

    cout << "Number of Fresh Ingredients: " << num_fresh_ingredients << "\n";

    return 0;
}

// Print out all of the fresh ingredient id's
void print_fresh_ids(const set<unsigned long>& fresh_ids)
{
    cout << "Fresh Id's: ";
    for (auto sit = fresh_ids.begin(); sit != fresh_ids.end(); sit++) {
        if (sit != fresh_ids.begin()) {
            cout << ", ";
        }
        cout << *sit;
    }
    cout << "\n";

}

// Print out all of the available ingredient id's
void print_ingredient_ids(const vector<unsigned long>& ingredient_ids)
{
    cout << "Ingredient Id's: ";
    for (auto id = ingredient_ids.begin(); id != ingredient_ids.end(); id++) {
        if (id != ingredient_ids.begin()) {
            cout << ", ";
        }
        cout << *id;
    }
    cout << "\n";

}