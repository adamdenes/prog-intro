#include "../std_lib_facilities.h"

constexpr double yen_to_usd{0.0088};
constexpr double krone_to_usd{0.16};
constexpr double pounds_to_usd{1.38};

double yen_to_dollar(int x)
{
    return x * yen_to_usd;
}

double krone_to_dollar(int x)
{
    return x * krone_to_usd;
}

double pounds_to_dollar(int x)
{
    return x * pounds_to_usd;
}

int main()
{
    cout << "Please enter currency type to convert from ['k', 'y', 'p'] to $USD and the value:\n";
    int unit;
    char curr_type{'y'};
    cin >> curr_type >> unit;

    switch (curr_type)
    {
    case 'k':
        cout << "♔" << unit << "==$" << krone_to_dollar(unit) << '\n';
        break;
    case 'y':
        cout << "¥" << unit << "==$" << yen_to_dollar(unit) << '\n';
        break;
    case 'p':
        cout << "£" << unit << "==$" << pounds_to_dollar(unit) << '\n';
        break;
    default:
        cout << "Unkown currency type.\n";
        break;
    }
}