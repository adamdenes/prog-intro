
/*
	calculator08buggy.cpp

	Helpful comments removed.

	We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/

#include "../std_lib_facilities.h"

struct Token
{
    char kind;
    double value;
    string name;
    Token() {}
    Token(char ch) : kind(ch), value(0) {}
    Token(char ch, double val) : kind(ch), value(val) {}
    Token(char ch, string &s) : kind(ch), name(s) {}
};

class Token_stream
{
private:
    bool full;
    Token buffer;

public:
    Token_stream() : full(0), buffer(0) {}

    Token get();
    void unget(Token t)
    {
        buffer = t;
        full = true;
    }

    void ignore(char);
};

constexpr char let = 'L';
constexpr char quit = 'Q';
constexpr char print = ';';
constexpr char number = '8';
constexpr char name = 'a';
constexpr char root = 'R';      // #7.
constexpr char power = 'P';     // #9.
const char dec_vars = '#';    // #10.
const string dec_quit = "exit"; // #11.
const string dec_root = "sqrt";
const string dec_power = "pow";

Token Token_stream::get()
{
    if (full)
    {
        full = false;
        return buffer;
    }
    char ch;
    cin >> ch;
    switch (ch)
    {
    case quit:
    case print:
    case '(':
    case ')':
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
    case ',':
    case '=':
        return Token(ch);
    case '.':
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    {
        cin.unget();
        double val;
        cin >> val;
        return Token(number, val);
    }
    default:
        if (isalpha(ch)|| ch == dec_vars)
        {
            string s;
            s += ch;
            while (cin.get(ch) && (isalpha(ch) || isdigit(ch)))
                s += ch;
            cin.unget();
            if (s == "#")
                return Token(let);
            if (s == dec_quit)
                return Token(quit);
            if (s == dec_root)
                return Token(root);
            if (s == dec_power)
                return Token(power);
            return Token(name, s);
        }
        error("Bad token");
        return 0;
    }
}

void Token_stream::ignore(char c)
{
    if (full && c == buffer.kind)
    {
        full = false;
        return;
    }
    full = false;

    char ch;
    while (cin >> ch)
        if (ch == c)
            return;
}

class Variable
{
public:
    string name;
    double value;
    Variable(string n, double v) : name(n), value(v) {}
};

vector<Variable> var_table;

double get_value(string s)
{
    for (const Variable &v : var_table)
    {
        if (v.name == s)
        {
            return v.value;
        }
    }
    error("get: undefined name ", s);
    return 0;
}

void set_value(string s, double d)
{
    for (Variable &v : var_table)
    {
        if (v.name == s)
        {
            v.value = d;
            return;
        }
    }
    error("set: undefined name ", s);
}

bool is_declared(string s)
{
    for (const Variable &v : var_table)
        if (v.name == s)
            return true;
    return false;
}

double define_name(string var, double val)
{
    if (is_declared(var))
        error(var, " declared twice");
    var_table.push_back(Variable(var, val));
    return val;
}

Token_stream ts;

double expression();

double primary()
{
    Token t = ts.get();
    switch (t.kind)
    {
    case '(':
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')')
            error("'(' expected");
    }
    case '-':
        return -primary();
    case number:
        return t.value;
    case name:
        return get_value(t.name);
    case root:
    case power:
    {
        ts.unget(t);
        return 0;
    }
    default:
        error("primary expected");
        return 0;
    }
}

// // #7. sqrt() function
// // #9. pow() function
double secondary()
{
    double left = primary();
    Token t = ts.get();
    // Token t2;
    double d;
    double d2;

    while (true)
    {
        switch (t.kind)
        {
        case root:
        {
            t = ts.get();
            if (t.kind != '(')
                error("opening '(' expected");

            d = expression();

            // #8. no negatives
            if (d < 0)
                error("negative argument in sqrt() is not allowed");
            left = sqrt(d);

            t = ts.get();
            if (t.kind != ')')
                error("closing ')' expected");
            return left;
        }
        case power: // #9.
        {
            t = ts.get();
            if (t.kind != '(')
                error("opening '(' expected");

            d = expression();

            t = ts.get();
            if (t.kind != ',')
                error("',' expected");

            d2 = expression();
            t = ts.get();
            if (t.kind != ')')
                error("closing ')' expected");

            // make sure that the 2nd parameter is integer
            left = pow(d, int(d2));
            return left;
        }
        default:
            ts.unget(t);
            return left;
        }
    }
}

double term()
{
    double left = secondary();
    while (true)
    {
        Token t = ts.get();
        switch (t.kind)
        {
        case '*':
            left *= primary();
            break;
        case '/':
        {
            double d = primary();
            if (d == 0)
                error("'/' divide by zero");
            left /= d;
            break;
        }
        case '%':
        {
            double d = primary();
            if (d == 0)
                error("'%' divide by zero");
            left = fmod(left, d);
            break;
        }
        default:
            ts.unget(t);
            return left;
        }
    }
}

double expression()
{
    double left = term();
    while (true)
    {
        Token t = ts.get();
        switch (t.kind)
        {
        case '+':
            left += term();
            break;
        case '-':
            left -= term();
            break;
        default:
            ts.unget(t);
            return left;
        }
    }
}

double declaration()
{
    Token t = ts.get();
    // cout << "t.kind: " << t.kind << '\n';
    if (t.kind != 'a')
        error("name expected in declaration");
    string name = t.name;
    if (is_declared(name))
        error(name, " declared twice");
    Token t2 = ts.get();
    if (t2.kind != '=')
        error("= missing in declaration of ", name);
    double d = expression();
    // var_table.push_back(Variable(name, d));
    define_name(name, d);
    return d;
}

double statement()
{
    Token t = ts.get();
    switch (t.kind)
    {
    case let:
        return declaration();
    default:
        ts.unget(t);
        return expression();
    }
}

void clean_up_mess()
{
    ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate()
{
    while (true)
        try
        {
            cout << prompt;
            Token t = ts.get();
            while (t.kind == print)
                t = ts.get();
            if (t.kind == quit)
                return;
            ts.unget(t);
            cout << result << statement() << endl;
        }
        catch (runtime_error &e)
        {
            cerr << e.what() << endl;
            clean_up_mess();
        }
}

int main()

try
{
    define_name("k", 1000); // #6.

    calculate();
    return 0;
}
catch (exception &e)
{
    cerr << "exception: " << e.what() << endl;
    char c;
    while (cin >> c && c != ';')
        ;
    return 1;
}
catch (...)
{
    cerr << "exception\n";
    char c;
    while (cin >> c && c != ';')
        ;
    return 2;
}
