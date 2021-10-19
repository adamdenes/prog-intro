#include "../std_lib_facilities.h"

int main()
{
    cout << "#Enter your first name: ";
    string first_name;
    cin >> first_name;

    cout << "Hello, " << first_name << ".\n";
    cout << "#Enter the name of the person you want ot write to: ";
    cin >> first_name;

    cout << "\nDear " << first_name << ",\n"
         << "How are you? I am fine. I miss you.\n"
         << "I am writing to you because it is part of the drill.\n\n";

    cout << "#Enter your friends name: ";
    string friends_name;
    cin >> friends_name;
    cout << "Have you seen " << friends_name << " lately?\n";

    char friend_sex{0};
    cout << "#Enter your friends sex ('m' for male | 'f' for female): ";
    cin >> friend_sex;

    if (friend_sex == 'm')
    {
        cout << "If you see " << friends_name << " please ask him to call me.\n";
    }
    else if (friend_sex == 'f')
    {
        cout << "If you see " << friends_name << " please ask her to call me.\n";
    }
    else
    {
        cout << "Wrong input.\n";
    }

    cout << "#Enter your age: ";
    int age{0};
    cin >> age;
    cout << "I hear you just had a birthday and you are " << age << " years old.\n";

    if (age <= 0 || age >= 110)
    {
        simple_error("you're kidding!");
    }
    else if (age < 12)
    {
        cout << "Next year you will be " << ++age << " years old.\n";
    }
    else if (age == 17)
    {
        cout << "Next year you will be able to vote.\n";
    }
    else if (age > 70)
    {
        cout << "I hope you are enjoying retirement.\n";
    }

    cout << "Yours sincerely,\n\n"
         << "Adam Denes\n";

    return 0;
}