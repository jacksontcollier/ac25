#include "PaperRollGrid.hpp"

#include <iostream>
#include <string>

using namespace std;

void PaperRollGrid::append_row(const string& row)
{
    grid.push_back(row);
    NROWS = grid.size();
    NCOLS = grid[0].size();
}

void PaperRollGrid::print(ostream& out)
{
    out << "Paper Roll Grid\n";
    for (auto &grid_line : grid) {
        out << grid_line << "\n";
    }
}

vector<GridPosition> PaperRollGrid::list_adjacent_positions(GridPosition& pos)
{
    size_t r = pos.r;
    size_t c = pos.c;
    vector<GridPosition> adjacent_positions;

    // Top left
    if ((r > 0) && (c > 0)) {
        adjacent_positions.push_back(GridPosition(r - 1, c - 1));
    }

    // Top
    if (r > 0) {
        adjacent_positions.push_back(GridPosition(r - 1, c));
    }

    // Top right
    if ((r > 0) && (c + 1 < NCOLS)) {
        adjacent_positions.push_back(GridPosition(r - 1, c + 1));
    }

    // Right
    if (c + 1 < NCOLS) {
        adjacent_positions.push_back(GridPosition(r, c + 1));
    }

    // Bottom Right
    if ((r + 1 < NROWS) && (c + 1 < NCOLS)) {
        adjacent_positions.push_back(GridPosition(r + 1, c + 1));
    }

    // Bottom
    if (r + 1 < NROWS) {
        adjacent_positions.push_back(GridPosition(r + 1, c));
    }

    // Bottom Left
    if ((r + 1 < NROWS) && (c > 0)) {
        adjacent_positions.push_back(GridPosition(r + 1, c - 1));
    }

    // Left
    if (c > 0) {
        adjacent_positions.push_back(GridPosition(r, c - 1));
    }

    return adjacent_positions;
}

vector<GridPosition> PaperRollGrid::list_accessible_roll_positions()
{
    vector<GridPosition> accessible_roll_positions;

    for (size_t r = 0; r < grid.size(); r++) {
        for (size_t c = 0; c < grid[r].size(); c++) {
            bool is_location_paper_roll = (grid[r][c] == PAPER_ROLL_SYMBOL);

            if (is_location_paper_roll) {
                GridPosition grid_position(r, c);
                vector<GridPosition> adjacent_positions = list_adjacent_positions(grid_position);

                unsigned long adjacent_roll_pos_count = 0;

                for (auto& adjacent_pos : adjacent_positions) {
                    if (grid[adjacent_pos.r][adjacent_pos.c] == PAPER_ROLL_SYMBOL) {
                        adjacent_roll_pos_count++;
                    }
                }

                if (adjacent_roll_pos_count < 4) {
                    accessible_roll_positions.push_back(grid_position);
                }
            }
        }
    }

    return accessible_roll_positions;
}

void PaperRollGrid::remove_roll_positions(const vector<GridPosition>& roll_positions)
{
    for (auto& roll_position : roll_positions) {
        grid[roll_position.r][roll_position.c] = OPEN_POS_SYMBOL;
    }
}
