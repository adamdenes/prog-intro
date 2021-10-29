#include "../std_lib_facilities.h"

struct Date
// 2. version from 9.4.2
{
    int y, m, d;
    Date(int y, int m, int d);
    void add_day(int n);
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

Date::Date(int yy, int mm, int dd)
    // : y{yy}, m{mm}, d{dd}
{
    y = (yy <= 0) ? 2001 : yy;
    m = (mm < 1 || mm > 12) ? 1 : mm;
    d = (dd < 1 || dd > 31) ? 1 : dd;
}

void Date::add_day(int n)
{
    static int max{0};

    switch (m)
    {
    case 2:
        max = is_leap_year(y) ? 29 : 28;
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

    if ((d + n) <= max)
    {
        d += n;
    }
    else if ((d + n) > max)
    {
        m = next_month(Date(y, m, d));
        d = abs(max - (d + n));
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
    Date today{1978, 6, 25};
    // Date today{2004, 13, -5};
    // Date today{2020, 4, 21};

    Date tomorrow{today};
    tomorrow.add_day(1);
    // tomorrow.add_day(11);

    cout << "today:\t\t" << today << "\ntomorrow:\t" << tomorrow << endl;
    return 0;
}