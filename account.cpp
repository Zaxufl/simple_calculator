#include "account.h"
#include <string>
#include <iostream>
using namespace std;

Account::Account(string name_val, double balance_val)
    : name{name_val}
    , balance{balance_val}
{
    cout << "No parameters" << '\n';
}


string Account::show_name()
{
    return name;
}
