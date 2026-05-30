#ifndef __PAPER_ROLL_GRID_H__
#define __PAPER_ROLL_GRID_H__

#include <ostream>
#include <string>
#include <vector>

using namespace std;

struct GridPosition
{
    size_t r; // row index in grid
    size_t c; // column index in grid
    GridPosition() : r(0), c(0) {};
    GridPosition(size_t _r, size_t _c) : r(_r), c(_c) {}
};

class PaperRollGrid
{
public:
    void append_row(const string& row);
    void print(ostream& out);
    vector<GridPosition> list_accessible_roll_positions();
    void remove_roll_positions(const vector<GridPosition>& roll_positions);
    size_t NROWS;
    size_t NCOLS;

private:
    vector<string> grid;
    const char PAPER_ROLL_SYMBOL = '@';
    const char OPEN_POS_SYMBOL = '.';
    vector<GridPosition> list_adjacent_positions(GridPosition& pos);
};

#endif