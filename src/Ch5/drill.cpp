#include "../std_lib_facilities.h"

int main()
try
{
    cout << "1. Success!\n"; // ‘Cout’ was not declared in this scope
    cout << "2. Success!\n"; // missing terminating " character
    cout << "3. Success" << "!\n"; // stray ‘\’ in program; missing terminating " character
    string success = "4. Success!"; cout << success << '\n'; // ‘success’ was not declared in this scope

    // conversion from ‘int’ to non-scalar type ‘std::string’
    // cannot convert ‘std::string’ ... to ‘int’ in assignment
    int res = 7; vector<int> v(10); v[5] = res; cout << "5. Success!\n";

    // no match for call to ‘(Vector<int>) (int)’
    vector<int> v2(10); v2[5] = 7; if (v2[5] != 7) cout << "6. Success!\n";

    // ‘cond’ was not declared in this scope
    bool cond = true; if (cond) cout << "7. Success!\n"; else cout << "Fail!\n";
    bool c = false; if (!c) cout << "8. Success!\n"; else cout << "Fail!\n";

    // ‘boo’ was not declared in this scope; did you mean ‘bool’?
    string s = "ape"; bool c2 = "fool" > s; if (c2) cout << "9. Success!\n";
    string s2 = "ape"; if (s2 == "ape") cout << "10. Success!\n";
    string s3 = "ape"; if (s3 == "fool") cout << "11. Success!\n";
    string s4 = "ape"; if (s4 != "fool") cout << "12. Success!\n"; // could not convert...

    vector<char> v3(5); for (int i = 0; i < v3.size(); ++i); cout << "13. Success!\n"; // 0 < v.size() -> i
    vector<char> v4(5); for (int i = 0; i < v4.size(); ++i); cout << "14. Success!\n"; // out_of_range

    string s5 = "15. Success!\n"; for (int i = 0; i < s5.length()-1; ++i) cout << s5[i]; cout << '\n';
    if (true) cout << "16. Success!\n"; else cout << "Fail!\n";
    int x = 2000; int c3 = x; if (c3 == 2000) cout << "17. Success!\n"; // overflow
    string s6 = "18. Success!\n"; for (int i = 0; i < s6.length()-1; ++i) cout << s6[i]; cout << '\n';

    vector<char> v5(5); for (int i = 0; i < v5.size(); ++i) /*cout << v5.size() << v5[i] << '\t' << i << '\n'*/; cout << "19. Success!\n"; // out_of_range
    int i = 0; int j = 9; while (i < 10) ++i; if (j < i) cout << "20. Success!\n"; // ++i
    int x2 = 2; double d = 5.0/x2; if (d == x2 + 0.5) cout << "21. Success!\n"; // 0 divison

    string s7 = "22. Success!\n"; for (int i = 0; i < s7.length()-1; ++i) cout << s7[i]; cout << '\n'; // ‘std::string’ ... is not a template
    int i2 = 0; while (i2 < 10) ++i2; if (j < i2) cout << "23. Success!\n";
    int x3 = 4; double d2 = 5.0/(x3-2); if (d2 == x3/2 + 0.5) cout << "24. Success!\n";
    cout << "25. Success!\n"; // no match for ‘operator<<’
    
    return 0;
}
catch (exception &e)
{
    cerr << "error: " << e.what() << '\n';
    return 1;
}
catch (...)
{
    cerr << "Oops: unknown exception!\n";
    return 2;
}