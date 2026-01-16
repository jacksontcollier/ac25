#include "ProductId.hpp"

#include <iostream>
#include <string>

using namespace std;

bool ProductId::is_invalid()
{
    string string_id = to_string(id);

    if (string_id.size() & 0x1) {
        return false;
    }

    string left_half = string_id.substr(0, string_id.size() / 2);
    string right_half = string_id.substr(string_id.size() / 2);

    if (left_half == right_half) {
        return true;
    }

   return false; 
}

bool ProductId::is_invalid_p2()
{
    string string_id = to_string(id);
    
    if (string_id.size() == 1) {
        return false;
    }

    size_t half_len = string_id.size() / 2;

    for (size_t i = 1; i <= half_len; i++) {
        if (string_id.size() % i != 0) {
            continue;
        }

        bool is_invalid = true;

        for (size_t j = 0; j + i < string_id.size(); j += i) {
            if (string_id.substr(j, i) != string_id.substr(j + i, i)) {
                is_invalid = false;
                break;
            }
        }

        if (is_invalid) {
            return true;
        }
    }

    return false;
}