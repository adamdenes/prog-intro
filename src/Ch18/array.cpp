#include "../std_lib_facilities.h"

// #1.
int ga[10]{1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

// #2-3.
void f(int arr[], int size)
{
    int la[10];

    for (int i = 0; i < 10; ++i)
    {
        la[i] = ga[i];
    }

    cout << "local array:\t";
    for (int i = 0; i < 10; ++i)
    {
        cout << la[i] << ' ';
    }
    cout << endl;

    int *p = new int[size];

    for (int i = 0; i < size; ++i)
    {
        p[i] = arr[i];
    }

    cout << "frestore array:\t";
    for (int i = 0; i < size; ++i)
    {
        cout << p[i] << ' ';
    }
    cout << endl;

    delete[] p;
}

// #4.
int main()
{
    f(ga, 10);

    int aa[10]{
        1,
        2 * 1,
        3 * 2 * 1,
        4 * 3 * 2 * 1,
        5 * 4 * 3 * 2 * 1,
        6 * 5 * 4 * 3 * 2 * 1,
        7 * 6 * 5 * 4 * 3 * 2 * 1,
        8 * 7 * 6 * 5 * 4 * 3 * 2 * 1,
        9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1,
        10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1};

    f(aa, 10);

    return 0;
}