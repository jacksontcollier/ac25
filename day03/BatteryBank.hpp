#ifndef __BATTERY_BANK_HPP__
#define __BATTERY_BANK_HPP__

#include <string>
#include <vector>

using namespace std;

class BatteryBank
{
public:
    BatteryBank(const string& battery_bank_str);
    unsigned long long compute_max_joltage(const size_t& battery_count);

private:
    string bank_description_str;
    vector<unsigned int> bank;
    void select_max_battery_in_subbank(
            size_t start_pos,               size_t end_pos,
            unsigned long& _OUT__max_power, size_t& _OUT__max_power_pos);

};

#endif