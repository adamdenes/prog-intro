#include "../std_lib_facilities.h"

void swap_v(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swap_r(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swap_cr(const int &a, const int &b)
// not going to compile with const assignment
{
    int temp;
    temp = a;
    // a = b;
    // b = temp;
}

int main()
{
    int x{7};
    int y{9};
    swap_v(x, y); // x=7 y=9
    cout << "x=" << x << " y=" << y << endl;
    swap_r(x, y); // x=9 y=7
    cout << "x=" << x << " y=" << y << endl;
    // swap_cr(x, y);    // error: assignment of read-only reference

    swap_v(7, 9); // x=9 y=7
    // swap_r(7, 9);  // error: there is nothing to refere to

    const int cx{7};
    const int cy{9};
    swap_v(cx, cy); // cx=7 cy=9
    cout << "cx=" << cx << " cy=" << cy << endl;
    // swap_r(cx, cy);     // error: const cannot be changed

    swap_v(7.7, 9.9); // truncated: cx=9 cy=7
    // swap_r(7.7, 9.9); // error: there is nothing to refere to

    double dx{7.7};
    double dy{9.9};
    swap_v(dx, dy); // dx=7.7 dy=9.9
    cout << "dx=" << dx << " dy=" << dy << endl;
    // swap_r(dx, dy);  // error: cannot reference int& to double
    swap_v(7.7, 9.9); // dx=9.9 dy=7.7
    // swap_r(7.7, 9.9); // error: there is nothing to refere to

    /* Result:
        x=7 y=9
        x=9 y=7
        cx=7 cy=9
        dx=7.7 dy=9.9
    */
    return 0;
}