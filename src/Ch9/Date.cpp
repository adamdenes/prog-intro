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

bool is_leap_year(const int &y)
{
    if (y % 4 == 0 && y % 100 == 0 && y % 400 == 0 || y % 4 == 0 && y % 100 != 0)
        return true;
    return false;
}

int next_month(const Date &d)
{
    int next{0};
    if (d.m >= 1 && d.m < 12)
    {
        next = d.m + 1;
    }
    else
    {
        next = 1;
    }
    return next;
}

void init_day(Date &dd, int y, int m, int d)
{
    dd.y = (y < 0) ? 2001 : y;
    dd.m = (m < 1 || m > 12) ? int(Month::jan) : m;
    dd.d = (d < 1 || d > 31) ? 1 : d;
}

void add_day(Date &dd, int n)
{
    int max{0};

    if (n < 0)
        return;

    switch (dd.m)
    {
    case 2:
        max = is_leap_year(dd.y) ? 29 : 28;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        max = 30;
        break;
    default:
        max = 31;
        break;
    }

    if ((dd.d + n) <= max)
    {
        dd.d += n;
    }
    if ((dd.d + n) > max)
    {
        dd.m = next_month(dd);
        dd.d = abs(max - (dd.d + n));
    }
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
    // init_day(today, 2020, int(Month::apr), 21);

    Date tomorrow{today};
    // add_day(tomorrow, 1);
    add_day(tomorrow, 11);

    cout << "today:\t\t" << today << "\ntomorrow:\t" << tomorrow << endl;

    return 0;
}