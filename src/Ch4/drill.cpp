#include "../std_lib_facilities.h"

int main()
{
    double a{0.0};
    double b{0.0};

    while (cin >> a >> b)
    {
        // cin terminates upon any input other than 'double'
        cout << "a=" << a << " b=" << b << '\n';

        if (a < b)
        {
            cout << "the smaller value is: " << a << '\n';
        }
        else if (a > b)
        {
            cout << "the larger value is: " << a << '\n';
        }
        else
        {
            cout << "the numbers are equal\n";
        }

        if (abs(a - b) <= 0.01)
        {
            cout << "the numbers are almost equal\n";
        }
    }

    return 0;
}