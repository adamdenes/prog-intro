#include "Point.h"
#include "../std_lib_facilities.h"

Point::Point() : x{0}, y{0} {}
Point::Point(int xx, int yy) : x{xx}, y{yy} {}

int Point::get_x() const { return x; }
int Point::get_y() const { return y; }

void end_of_loop(istream &is, char term, const string &msg)
{
    if (is.fail())
    {
        is.clear();
        char ch;
        if (is >> ch && ch == term)
            return;
        error(msg);
    }
}

iostream &operator>>(iostream &is, Point &p)
{
    int x, y;
    char ch1, ch2, ch3;

    is.exceptions(is.exceptions() | ios_base::badbit);

    if (is >> ch1 && ch1 != '(')
    {
        is.unget();
        is.clear(ios_base::failbit);
        return is;
    }

    is >> x >> ch2 >> y >> ch3;
    if (!is || ch2 != ',' || ch3 != ')')
    {
        error("bad reading");
    }
    end_of_loop(is, '*', "bad termination character");

    p = Point{x, y};
    return is;
}

ostream &operator<<(ostream &os, const Point &p)
{
    return os << '(' << p.get_x() << ',' << p.get_y() << ')';
}

void print_vector(vector<Point> &points)
{
    cout << "printing vector: { ";
    for (const Point &point : points)
    {
        cout << point;
    }
    cout << " }\n";
}

void write_file(ofstream &ofs, string fname, vector<Point> &o)
{
    if (!ofs)
        error("can't open file", fname);
    for (Point &point : o)
    {
        ofs << point << endl;
    }
    ofs.close();
}

// void read_file(ifstream &ifs, string fname, vector<Point> &i)
// {
//     if (!ifs)
//         error("can't open file", fname);

//     int x1, y1;
//     char ch1, ch2, ch3;

//     while (true)
//     {
//         ifs >> ch1 >> x1 >> ch2 >> y1 >> ch3;
//         i.push_back(Point{x1, y1});
//     }
// }

int main()
try
{
    int x, y;
    char ch1, ch2, ch3;
    vector<Point> original_points;
    cout << "Please enter 7 coordinates in the form of '(x,y)':\n";

    while (cin >> ch1 >> x >> ch2 >> y >> ch3)
    {
        if (!cin)
        {
            break;
        }
        original_points.push_back(Point{x, y});
    }

    print_vector(original_points);
    string file{"mydata.txt"};
    ofstream ofs{file};
    write_file(ofs, file, original_points);

    vector<Point> processed_points;
    ifstream ifs{file};
    // read_file(ifs, file, processed_points);

    while (true)
    {
        ifs >> ch1 >> x >> ch2 >> y >> ch3;
        if (!ifs)
        {
            break;
        }
        processed_points.push_back(Point{x, y});
    }
    print_vector(processed_points);

    if (original_points.size() != processed_points.size())
    {
        cout << "Something's wrong! -> vector sizes differ.\n"
             << original_points.size()
             << " != "
             << processed_points.size()
             << endl;
    }
    else
    {
        for (int i = 0; i < original_points.size(); ++i)
        {
            if (original_points[i].get_x() != processed_points[i].get_x() &&
                original_points[i].get_y() != processed_points[i].get_y())
            {
                cout << "Something's wrong! -> Point values differ.\n"
                     << original_points[i].get_x()
                     << " != "
                     << processed_points[i].get_x()
                     << " && "
                     << original_points[i].get_y()
                     << " != "
                     << processed_points[i].get_y()
                     << endl;
            }
        }
        cout << "All good!" << endl;
    }

    return 0;
}
catch (exception &e)
{
    cerr << e.what() << endl;
    return 1;
}
catch (...)
{
    cerr << "exception\n";
    return 2;
}