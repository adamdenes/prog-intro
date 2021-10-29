#include "../std_lib_facilities.h"

/* enum class */
enum class Month
{
    jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

Month operator++(Month &m)
{
    m = (m == Month::dec) ? Month::jan : Month(int(m) + 1);
    return m;
}

Month operator+=(Month &m, int &n)
{
    m = Month(int(m) + n);
    return m;
}

Month operator+(Month &m, int &n)
{
    m = Month(int(m) + n);
    return m;
}
/* end enum class */

/* class Date declaration*/
class Date
// 5. version from 9.7.4
{
private:
    int y, d;
    Month m;

public:
    Date(int y, Month m, int d);

    // const functions (getters)
    int year() const { return y; }
    Month month() const { return m; }
    int day() const { return d; }

    // modifiers (setters)
    void add_year(int n);
    void add_month(int n);
    void add_day(int n);
};
/* end class Date declaration*/

/* helper functions */
bool is_leap_year(const int &y)
{
    if (y % 4 == 0 && y % 100 == 0 && y % 400 == 0 || y % 4 == 0 && y % 100 != 0)
        return true;
    return false;
}

ostream &operator<<(ostream &os, const Date &d)
{
    return os << '(' << d.year()
              << ',' << int(d.month())
              << ',' << d.day()
              << ')';
}
/* end helper functions */

/* class Date definitions  */
Date::Date(int yy, Month mm, int dd)
{
    y = (yy <= 0) ? 2001 : yy;
    m = (int(mm) >= 1 || int(mm) <= 12) ? mm : Month::jan;
    d = (dd < 1 || dd > 31) ? 1 : dd;
}

void Date::add_year(int n)
{
    y += n;
}

void Date::add_month(int n)
{
    if ((int(m) + n) >= 1 && (int(m) + n) <= 12)
    {
        m += n;
    }
    else
    {
        if ((int(m) + n) % 12 == 0)
        {
            y += (int(m) + n) / 12;
            m = Month::jan;
        } 
        else 
        {
            y += int((int(m) + n) / 12);
            m = Month((int(m) + n) % 12);
        }
    }
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
        ++m;
        d = abs(max - (d + n));
    }
}
/* end class Date definitions */

int main()
{
    Date today{1978, Month::jun, 25};
    // Date today{2004, Month::dec, -5};
    // Date today{2020, Month::apr, 21};

    Date tomorrow{today};
    // testing day conversion
    tomorrow.add_day(1);
    // tomorrow.add_day(11);

    // testing month conversion
    tomorrow.add_month(1);
    // tomorrow.add_month(6);
    // tomorrow.add_month(7);
    // tomorrow.add_month(12);
    // tomorrow.add_month(13);
    // tomorrow.add_month(14);
    // tomorrow.add_month(33);

    // testing year converison 
    tomorrow.add_year(1);

    cout << "today:\t\t" << today << "\ntomorrow:\t" << tomorrow << endl;
    return 0;
}