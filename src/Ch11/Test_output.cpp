#include "../std_lib_facilities.h"

int main()
{
    // #1.
    int birth_year{1993};
    int age{28};

    // #2-3-4.
    // #7. showbase
    cout << showbase << setw(5) << birth_year << "\t(decimal)\n"
         << hex << birth_year << "\t(hexadecimal)\n"
         << oct << birth_year << "\t(octal)" << endl;

    // #5-6. hex, oct, dec are "sticky"
    cout << dec << setw(5) << age << "\t(my_age)\n\n";

    // #8. 1234 1234 1234 1234
    // dec     oct      hex     hex
    // 1234    668     4660    4660
    int a, b, c, d;
    cout << "Input: 1234 1234 1234 1234" << endl;
    cin >> a >> oct >> b >> hex >> c >> d;
    cout << a << '\t' << b << '\t' << c << '\t' << d << "\n\n";

    // #9.
    // defaultfloat: outputs 6 integers by default,
    //               above 6 it converts to fixed or scientific
    // fixed:        outputs 6 integers after floating point
    // scientifix:   outputs the scientific notation
    cout << defaultfloat << 1234567.89 << "\t(defaultfloat)\n"
         << fixed << 1234567.89 << "\t(fixed)\n"
         << scientific << 1234567.89 << "\t(scientific)\n"
         << endl;

    // #10.
    cout << "------------------------------------------------------------------\n"
         << '|' << setw(11) << "last name" << setw(2) << '|'
         << setw(11) << "first name" << setw(2) << '|'
         << setw(11) << "telephone" << setw(3) << '|'
         << setw(13) << "email" << setw(12) << '|'
         << "\n------------------------------------------------------------------\n"
         << '|' << setw(11) << "Denes" << setw(2) << '|'
         << setw(11) << "Adam" << setw(2) << '|'
         << setw(11) << "+36301234567" << setw(2) << '|'
         << setw(22) << "adam.denes@email.com" << setw(3) << '|'
         << "\n------------------------------------------------------------------\n"
         << '|' << setw(11) << "Solak" << setw(2) << '|'
         << setw(11) << "Sverre" << setw(2) << '|'
         << setw(11) << "+37302234567" << setw(2) << '|'
         << setw(22) << "solak.Sverre@email.com" << setw(3) << '|'
         << "\n------------------------------------------------------------------\n"
         << '|' << setw(11) << "Alst" << setw(2) << '|'
         << setw(11) << "Lien" << setw(2) << '|'
         << setw(11) << "+38303234567" << setw(2) << '|'
         << setw(22) << "lien.alst@email.com" << setw(3) << '|'
         << "\n------------------------------------------------------------------\n"
         << '|' << setw(11) << "Ivan" << setw(2) << '|'
         << setw(11) << "Andries" << setw(2) << '|'
         << setw(11) << "+39304234567" << setw(2) << '|'
         << setw(22) << "ivan.andries@email.com" << setw(3) << '|'
         << "\n------------------------------------------------------------------\n"
         << '|' << setw(11) << "Bartos" << setw(2) << '|'
         << setw(11) << "Tejal" << setw(2) << '|'
         << setw(11) << "+40305234567" << setw(2) << '|'
         << setw(22) << "tejal.bartos@email.com" << setw(3) << '|'
         << "\n------------------------------------------------------------------\n";
    return 0;
}