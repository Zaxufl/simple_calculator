#include <QDebug>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

bool is_cin_ok(double);
bool is_cin_ok(string, char);
void quit(char);
double calculate(double, char, double);
char decision_to_continue();
void continue_play(double);
double n1_num(bool);
double n2_num(bool);
char select_operator(bool);

struct machine
{
    bool calculator{true}, n1_launch{true}, op_launch{true}, n2_launch{true};
};

int main()
{
    machine is_fine;

    double n1{n1_num(is_fine.n1_launch)};

    while (is_fine.calculator) {
        char op{select_operator(is_fine.op_launch)};

        double n2{n2_num(is_fine.n2_launch)};

        double ans{calculate(n1, op, n2)};

        n1 = ans;

        if (tolower(decision_to_continue() == 'n')) {
            is_fine.calculator = false;
        }
    }

    return 0;
}

bool is_cin_ok(double num)
{
    if (cin.fail()) {
        qInfo() << "Not a number, try again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return true;
    } else {
        return false;
    }
}

bool is_cin_ok(string operators, char op)
{
    if (operators.find(op) == -1) {
        qInfo() << "Not a operator, try again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return true;
    } else {
        return false;
    }
}

double calculate(double n1, char op, double n2)
{
    cout << n1 << " " << op << " " << n2 << " = ";

    double ans{};

    switch (op) {
    case '-':
        ans = n1 - n2;
        break;
    case '+':
        ans = n1 + n2;
        break;
    case '/':
        ans = n1 / n2;
        break;
    case '*':
        ans = n1 * n2;
        break;
    }

    if (fmod(ans, 1) == 0) {
        ans = int(ans);
        cout << ans;
    } else {
        cout << fixed << setprecision(2) << ans;
    }

    return ans;
}

char decision_to_continue()
{
    cout << '\n' << "Do you want to continue?" << '\n';
    cout << '\t' << "'Y' – yes" << '\n';
    cout << '\t' << "'N' – no" << '\n';
    char play;

    bool decision_key{true};

    while (decision_key) {
        cin >> play;
        switch (play) {
        case 'N':
        case 'n':
            cout << "Sayonara." << '\n';
            decision_key = false;
            break;
        case 'y':
        case 'Y':
            decision_key = false;
            break;
        default:
            qInfo() << "Wrong key, try again: ";
        }
    }

    return play;
}

char select_operator(bool is_ok)
{
    char op;
    while (is_ok) {
        qInfo() << "Write one of these operators '+ – / *':";
        cin >> op;

        is_ok = is_cin_ok(".-+/*", op);
    }

    return op;
}

double n1_num(bool is_ok)
{
    double n1{};
    while (is_ok) {
        qInfo() << "Write first number:";
        cin >> n1;

        is_ok = is_cin_ok(n1);
    }

    return n1;
}

double n2_num(bool is_ok)
{
    double n2{};
    while (is_ok) {
        qInfo() << "Write second number:";
        cin >> n2;

        is_ok = is_cin_ok(n2);
    }

    return n2;
}
