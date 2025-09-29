#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
using namespace std;

class Account
{
private:
    string name;
    double balance{};
public:
    Account(string name_val = "None", double balance_val = 0);
    string show_name();
};

#endif
