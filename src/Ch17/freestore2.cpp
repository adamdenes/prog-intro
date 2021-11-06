#include "../std_lib_facilities.h"

void print_array(ostream &os, int *a, int n, string name)
{
    if (a == nullptr)
        error("nullptr");

    os << "print_array(" << name << "): " << endl;
    for (int i = 0; i < n; ++i)
        os << "\tAddress==" << &a[i] << " | Content==" << a[i] << endl;
    os << '\n';
}

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
    /* Part II. */

    // #1-2.
    int *p1 = new int{7};
    cout << "Address==" << p1 << " | Content==" << *p1 << endl;

    // #3-4 - p2 is pointing to the 1st element of the array
    int *p2 = new int[7]{1, 2, 4, 8, 16, 32, 64};
    // cout << "First Address==" << p2 << endl;
    print_array(cout, p2, 7, "p2");

    // #5-8.
    int *p3 = p2;
    p2 = p1;
    // cout << p2 << "(p2) == " << p1 << " (p1)" << endl;
    p2 = p3;
    // cout << p2 << "(p2) == " << p3 << " (p3)" << endl;
    print_array(cout, p1, 1, "p1");
    print_array(cout, p2, 7, "p2");

    // #9. p2 == p3 ! --> no need to delete p3
    delete p1;
    delete[] p2;
    // delete[] p3; // free(): double free detected in tcache 2

    // #10-12.
    p1 = new int[10]{1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    p2 = new int[10];

    for (auto i = 0; i < 10; ++i)
    {
        if (p2)
        {
            p2[i] = p1[i];
            cout << "Copying p1[" << i << "]==" << p1[i] << " to p2[" << i << "]==" << p2[i] << endl;
        }
    }
    print_array(cout, p2, 10, "p2");

    // #13.
    vector<int> v1{1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

    // first try
    // vector<int> v2;
    // for (int element : v1)
    // {
    //     v2.push_back(element);
    // }

    // print_vector(cout, v2);

    // second try
    vector<int> v2(10);
    for (int i = 0; i < v1.size(); ++i)
    {
        v2[i] = v1[i];
    }

    print_vector(cout, v2);

    return 0;
}
catch (const std::exception &e)
{
    std::cerr << e.what() << '\n';
}
catch (...)
{
    std::cerr << "Uhm..." << '\n';
}