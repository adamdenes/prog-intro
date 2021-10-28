#include "../std_lib_facilities.h"

struct Date
// 1. version from 9.4.1
{
    int y, m, d;
};

enum class Month
{
    jan = 1,
    feb,
    mar,
    apr,
    may,
    jun,
    jul,
    aug,
    sep,
    oct,
    nov,
    dec
};

void init_day(Date &dd, int y, int m, int d)
{
    dd.y = (y < 0) ? 2001 : y;
    dd.m = (m < 1 || m > 12) ? int(Month::jan) : m;
    dd.d = (d < 1 || d > 31) ? 1 : d;
}

void add_day(Date &dd, int n)
{
    // if (dd.d + n <= 31) dd.d += n;
    // if (dd.d + n > 31) abs(31 - (dd.d + n));
    dd.d = (dd.d + n > 31) ? abs(31 - (dd.d + n)) : dd.d + n;
}

ostream &operator<<(ostream &os, const Date &d)
{
    return os << '(' << d.y
              << ',' << d.m
              << ',' << d.d
              << ')';
}

int main()
{
    Date today;
    init_day(today, 1978, int(Month::jun), 25);
    // init_day(today, 2004, 13, -5);

    Date tomorrow{today};
    add_day(tomorrow, 13);

    cout << "today:\t\t" << today << "\ntomorrow:\t" << tomorrow << endl;

    return 0;
}