struct Point
{
    int x, y;
    Point() : x{0}, y{0} {}
    Point(int xx, int yy) : x{xx}, y{yy} {}
    int get_x() const { return x; };
    int get_y() const { return y; };
};
