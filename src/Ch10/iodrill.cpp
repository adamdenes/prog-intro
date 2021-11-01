#include "Point.h"
#include "../std_lib_facilities.h"

void handle_failbit(istream &is, char term, const string &msg)
{
    is.clear();
    char ch;
    if (is >> ch && ch == term)
    {
        cout << "terminating --> '" << ch << '\'' << endl;
        return;
    }
    error(msg);
}

Point get_coordinates()
{
    static constexpr int terminated = -1234;

    int x, y;
    char ch1, ch2, ch3;

    while (true)
    {
        cin >> ch1 >> x >> ch2 >> y >> ch3;
        if (cin.fail())
        {
            handle_failbit(cin, '*', "bad/no input");
            return Point{terminated, terminated};
        }
        return Point{x, y};
    }
}

void input_loop(int counter, vector<Point> &v)
{
    int i = 0;
    while (i < counter)
    {
        Point p = get_coordinates();
        // failed to get value or terminated?
        if (p.get_x() == -1234 && p.get_y() == -1234)
        {
            break;
        }
        v.push_back(p);
        ++i;
    }
    return;
}

iostream &operator>>(iostream &is, Point &p)
{
    int x, y;
    char ch1, ch2, ch3;

    is >> ch1;
    if (!is)
        return is;
    if (ch1 != '(' || ch2 != ',' || ch3 != ')')
    {
        is.unget();
        is.clear(ios_base::failbit);
        return is;
    }

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

void read_file(ifstream &ifs, string fname, vector<Point> &i)
{
    if (!ifs)
        error("can't open file", fname);

    int x1, y1;
    char ch1, ch2, ch3;

    while (true)
    {
        ifs >> ch1 >> x1 >> ch2 >> y1 >> ch3;
        if (ifs.bad() || ifs.eof())
            break;
        i.push_back(Point{x1, y1});
    }
}

bool compare_vec_size(vector<Point> &original, vector<Point> &processed)
{
    if (original.size() != processed.size())
    {
        return false;
    }
    return true;
}

void compare_vals(vector<Point> &original, vector<Point> &processed)
{
    for (int i = 0; i < original.size(); ++i)
    {
        if (original[i].get_x() != processed[i].get_x() &&
            original[i].get_y() != processed[i].get_y())
        {
            cout << "Something's wrong! -> Point values differ.\n"
                 << original[i].get_x()
                 << " != "
                 << processed[i].get_x()
                 << " && "
                 << original[i].get_y()
                 << " != "
                 << processed[i].get_y()
                 << endl;
        }
    }
    cout << "All good!" << endl;
}

int main()
try
{
    int x, y;
    char ch1, ch2, ch3;
    vector<Point> original_points;
    cout << "Please enter 7 coordinates in the form of '(x,y)':\n";
    input_loop(7, original_points);

    print_vector(original_points);
    string file{"mydata.txt"};
    ofstream ofs{file};
    write_file(ofs, file, original_points);

    vector<Point> processed_points;
    ifstream ifs{file};
    read_file(ifs, file, processed_points);
    print_vector(processed_points);

    if (!compare_vec_size(original_points, processed_points))
    {
        cout << "Something's wrong! -> vector sizes differ.\n"
             << original_points.size()
             << " != "
             << processed_points.size()
             << endl;
    }
    else
    {
        compare_vals(original_points, processed_points);
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