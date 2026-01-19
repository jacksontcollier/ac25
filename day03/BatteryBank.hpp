#ifndef __BATTERY_BANK_HPP__
#define __BATTERY_BANK_HPP__

#include <string>
#include <vector>

using namespace std;

class BatteryBank
{
public:
    BatteryBank(const string& battery_bank_str);
    unsigned int compute_max_joltage();

private:
    string bank_description_str;
    vector<unsigned int> bank;

};

#endif