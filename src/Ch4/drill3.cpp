#include "../std_lib_facilities.h"

constexpr double m_to_cm{100};
constexpr double in_to_cm{2.54};
constexpr double ft_to_in{12};

bool is_smallest(double s, double min)
{
    return min > s;
}

bool is_largest(double l, double max)
{
    return max < l;
}

double converter(double c, string unit)
{
    if (unit == "cm")
    {
        // cout << "cm=" << c << "\tm=" << c / 100 << '\n';
        return c / 100;
    }
    if (unit == "in")
    {
        // cout << "in=" << c << "\tm=" << c * in_to_cm / 100 << '\n';
        return c * in_to_cm / 100;
    }
    if (unit == "ft")
    {
        // cout << "ft=" << c << "\tm=" << (c * ft_to_in) * in_to_cm / 100 << '\n';
        return (c * ft_to_in) * in_to_cm / 100;
    }
    if (unit == "m")
    {
        // cout << "m=" << c << "\tm=" << c << '\n';
        return c;
    }

    return -1;
}

int main()
{
    double a;
    double min{0};
    double max{0};
    double base{0};
    double sum{0};
    string unit{""};

    vector<double> meters{};

    while (cin >> a >> unit)
    {
        // #7-11.
        // cout << "a=" << a << unit << '\n';
        if (unit == "cm" || unit == "in" || unit == "ft" || unit == "m")
        {
            base = converter(a, unit);
            meters.push_back(base);
            sum += base;

            if (min == 0 || is_smallest(base, min))
            {
                min = base;
                // cout << "new min=" << min << '\n';
            }
            
            if (is_largest(base, max))
            {
                max = base;
                // cout << "new max=" << max << '\n';
            }

            cout << "current sum=" << sum
                 << " | current min=" << min
                 << " | current max=" << max
                 << '\n';
        }
        else
        {
            cout << "Invalid conversion unit!\n";
        }
    }

    sort(meters);
    cout << "Values in vector:\n";
    for (double meter : meters)
    {
        cout << meter << '\n';
    }

    return 0;
}