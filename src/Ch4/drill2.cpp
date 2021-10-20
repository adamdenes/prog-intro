#include "../std_lib_facilities.h"

int main()
{
    double a;
    double smaller;
    double larger;

    while (cin >> a)
    {
        // #6.
        cout << "a=" << a << '\n';

        if (a < smaller)
        {
            smaller = a;
            cout << smaller << ", the smallest sofar" << '\n';
        }
        if (a > larger)
        {
            larger = a;
            cout << larger << ", the largest sofar" << '\n';
        }
    }

    return 0;
}