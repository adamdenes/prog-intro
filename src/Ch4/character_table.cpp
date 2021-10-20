#include "../std_lib_facilities.h"

void printer(char val)
{
    cout << val << '\t' << int(val) << '\n';
}

int main()
{
    char current{'a'};

    // do
    // {
    //     printer(current);
    //     ++current;

    // } while (current <= 'z');

    for (char current = 'a'; current <= 'z'; ++current)
    {
        printer(current);
    }

    return 0;
}