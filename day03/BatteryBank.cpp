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

void BatteryBank::select_max_battery_in_subbank(
        size_t start_pos,               size_t end_pos,
        unsigned long& _OUT__max_power, size_t& _OUT__max_power_pos)
{
    for (size_t i = start_pos; i < end_pos; i++) {
        if ((i == start_pos) || (bank[i] > _OUT__max_power)) {
            _OUT__max_power = bank[i];
            _OUT__max_power_pos = i;
        }
    }
}

unsigned long long BatteryBank::compute_max_joltage(const size_t& battery_count)
{
    size_t start_pos = 0;
    unsigned long max_power;
    size_t max_power_pos;
    unsigned long long max_joltage = 0;


    for (size_t count = battery_count; count > 0; count--) {
        select_max_battery_in_subbank(
                start_pos, bank.size() - (count - 1),
                max_power, max_power_pos);
        for (size_t i = 1; i < count; i++) {
            max_power *= 10;
        }
        max_joltage += max_power;
        start_pos = max_power_pos + 1;
        max_power = 0;
        max_power_pos = 0;
    }

    return max_joltage;
}