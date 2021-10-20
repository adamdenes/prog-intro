#include "../std_lib_facilities.h"

int main()
{
    string disliked{"broccoli"};

    for (string word; cin >> word;)
    {
        string result = (word == disliked) ? "BEEP" : word;
        cout << result << '\n';
    }

    return 0;
}