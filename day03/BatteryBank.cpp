#include "BatteryBank.hpp"

#include <string>

using namespace std;

BatteryBank::BatteryBank(const string& battery_bank_str)
{
    bank_description_str = battery_bank_str;

    for (char& joltage_char : bank_description_str) {
        bank.push_back(joltage_char - '0');
    }
}

unsigned int BatteryBank::compute_max_joltage()
{
    size_t first_max_battery_pos = 0;
    unsigned int first_max_battery_power = 0;

    for (size_t bpos = 0; bpos < bank.size() - 1; bpos++) {
        unsigned int battery_power = bank[bpos];
        if ((bpos == 0) ||  (battery_power > first_max_battery_power)) {
            first_max_battery_power = battery_power;
            first_max_battery_pos = bpos;
        }
    }

    unsigned int second_max_power = 0;
    size_t second_max_power_bpos = 0;;

    for (size_t bpos = first_max_battery_pos + 1; bpos < bank.size(); bpos++) {
        unsigned int battery_power = bank[bpos];
        if ((bpos == first_max_battery_pos + 1) || (battery_power > second_max_power)) {
            second_max_power = battery_power;
            second_max_power_bpos = bpos;
        }
    }

    return (bank[first_max_battery_pos] * 10) + bank[second_max_power_bpos];
}