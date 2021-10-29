#include "../std_lib_facilities.h"

enum class Month
{
    jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

class Date
// 4. version from 9.7.1
{
private:
    int y, d;
    Month m;

public:
    Date(int y, Month m, int d);
    void add_day(int n);
    int year() const { return y; }
    Month month() const { return m; }
    int day() const { return d; }
};

bool is_leap_year(const int &y)
{
    if (y % 4 == 0 && y % 100 == 0 && y % 400 == 0 || y % 4 == 0 && y % 100 != 0)
        return true;
    return false;
}

Month next_month(const Date &d)
{
    int next{0};
    if (int(d.month()) >= 1 && int(d.month()) < 12)
    {
        next = int(d.month()) + 1;
    }
    else
    {
        next = int(Month::jan);
    }
    return static_cast<Month>(next);
}

Date::Date(int yy, Month mm, int dd)
// : y{yy}, m{mm}, d{dd}
{
    y = (yy <= 0) ? 2001 : yy;
    m = (int(mm) >= 1 || int(mm) <= 12) ? mm: Month::jan;
    d = (dd < 1 || dd > 31) ? 1 : dd;
}

void Date::add_day(int n)
{
    static int max{0};

    switch (m)
    {
    case Month::feb:
        max = is_leap_year(y) ? 29 : 28;
        break;
    case Month::apr:
    case Month::jun:
    case Month::sep:
    case Month::nov:
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
    return os << '(' << d.year()
              << ',' << int(d.month())
              << ',' << d.day()
              << ')';
}

int main()
{
    Date today{1978, Month::jun, 25};
    // Date today{2004, Month::dec, -5};
    // Date today{2020, Month::apr, 21};

    Date tomorrow{today};
    tomorrow.add_day(1);
    // tomorrow.add_day(11);

    cout << "today:\t\t" << today << "\ntomorrow:\t" << tomorrow << endl;
    return 0;
}