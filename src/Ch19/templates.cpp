#include "../std_lib_facilities.h"

template <typename T>
struct S
{
private:
    T val;

public:
    S(T v) : val{v} {}

    T &get();
    T &get() const;
    void set(T v);
    S &operator=(const T &);
};

template <typename T>
T &S<T>::get()
{
    return val;
}

template <typename T>
T &S<T>::get() const
{
    return val;
}

template <typename T>
void S<T>::set(T v)
{
    val = v;
}

template <typename T>
S<T>& S<T>::operator=(const T &v)
{
    val = v;
    return *this;
}

template <typename T>
istream &operator>>(istream &is, vector<T>& vec)
{
    cout << "operator>> ";

    char ch;
    
    // int i = 0;
    for (T val; is >> val; )
    {
        vec.push_back(val);
        // cout << vec.at(i) << endl;
        is >> ch;
        if (ch != ',')
            break;
        // ++i;
    }

    return is;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> vec)
{
    os << "operator<< ";
    for (int i = 0; i < vec.size(); ++i)
    {
        os << vec[i] << ' ';
    }
    // os << endl;
    return os;
}

template <typename T>
void read_val(T &v)
{
    cin >> v;
}

int main()
{
    S<int> i{12345};
    cout << i.get() << endl;

    S<char> c{'a'};
    cout << c.get() << endl;

    S<double> d{12345.6789};
    cout << d.get() << endl;

    S<string> s{"S initialized with type string"};
    cout << s.get() << endl;

    S<vector<int>> v{vector<int>{1, 2, 3, 4, 5}};

    for (auto &&i : v.get())
    {
        cout << i << ' ';
    }
    cout << endl;

    // i.set(6789);
    // cout << i.get() << endl;
    // c.set('b');
    // cout << c.get() << endl;
    // d.set(6789.12345);
    // cout << d.get() << endl;
    // s.set("S set with this random string");
    // cout << s.get() << endl;

    // v.set(vector<int>{6, 7, 8, 9, 10});

    // for (auto &&i : v.get())
    // {
    //     cout << i << ' ';
    // }
    // cout << endl;

    i = -90;
    c = 'c';
    d = 1.0;
    s = "assignment 'operator='";
    v = vector<int>(5);

    cout << i.get() << endl;
    cout << c.get() << endl;
    cout << d.get() << endl;
    cout << s.get() << endl;
    cout << v.get() << endl;

    int i2{0};
    read_val(i2);
    S<int> s_i2 = i2;
    cout << "s_i2->" << s_i2.get() << endl;

    vector<int> v2;
    read_val(v2);

    S<vector<int>> s_vi{v2};
    cout << s_vi.get() << endl;

    return 0;
}