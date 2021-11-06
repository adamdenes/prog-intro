#include "../std_lib_facilities.h"

// #4.
void print_array10(ostream &os, int *a)
{
    if (a == nullptr)
        error("nullptr");

    os << "print_array10(): ";
    for (int i = 0; i < 10; ++i)
        os << a[i] << " ";
    os << '\n';
}

// #7.
void print_array(ostream &os, int *a, int n)
{
    if (a == nullptr)
        error("nullptr");

    os << "print_array(" << n << "): ";
    for (int i = 0; i < n; ++i)
        os << a[i] << " ";
    os << '\n';
}

// #10.
void print_vector(ostream &os, vector<int> v)
{
    os << "print_vector(" << v.size() << "): ";
    for (auto &&i : v)
    {
        os << i << " ";
    }
    os << '\n';
}

int main()
try
{
    /* Part I. */

    // #1-3.
    int *pi = new int[10];

    for (int i = 0; i < 10; ++i)
        cout << pi[i] << endl;

    delete[] pi;

    // #5-6.
    int *a = new int[10]{100, 101, 102, 103, 104, 105, 106, 107, 108, 109};
    print_array10(cout, a);

    delete[] a;

    int *b = new int[11]{100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
    print_array10(cout, b);

    delete[] b;

    // #8-9.
    int *c = new int[20]{100, 101, 102, 103, 104, 105, 106, 107, 108, 109,
                         110, 111, 112, 113, 114, 115, 116, 117, 118, 119};
    print_array(cout, c, 20);

    delete[] c;

    // #10.
    /* this not really needed
    vector<int> *vp5 = new vector<int>{100, 101, 102, 103, 104, 105, 106, 107, 108, 109};
    for (int i = 0; i < (*vp5).size(); ++i)
        cout << (*vp5)[i] << endl;
    */ 

    // instead:
    vector<int> vp10{100, 101, 102, 103, 104, 105, 106, 107, 108, 109};
    print_vector(cout, vp10);

    vector<int> vp11{100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
    print_vector(cout, vp11);

    return 0;
}
catch (const std::exception &e)
{
    std::cerr << e.what() << '\n';
}