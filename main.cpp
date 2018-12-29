#include <iostream>

#include "wine.hpp"
#include "wine_private.hpp"

int main() {
    using std::cin;
    using std::cout;
    using std::endl;

    cout << "Enter name of wine: ";
    char lab[50] = "";
    cin.getline(lab, 50);
    cout << "Enter number of years: ";
    int yrs{0};
    cin >> yrs;

    Wine holding(lab, yrs);
    holding.getBottles();
    holding.getAge();
    holding.show(); // print wine info
    holding.showAge();

    constexpr int kYears = 3;
    int y[kYears] = { 1993, 1995, 1998 };
    int b[kYears] = { 48, 60, 72 };

    Wine more("Chianti", kYears, y, b);
    more.show();
    cout << "Total bottles for " << more.label() << ": " << more.sum() << endl;
    cout << "================================= Private Inheritance ==============================\n";


    cout << "Enter name of wine: ";
    cin.ignore(250, '\n');
    cin.getline(lab, 50);
    cout << "Enter number of years: ";
    yrs = 0;
    cin >> yrs;

    WinePrv holding2(lab, yrs);
    holding2.getBottles();
    holding2.getAge();
    holding2.show(); // print wine info
    holding2.showAge();

    WinePrv more2("Chianti", kYears, y, b);
    more2.show();
    cout << "Total bottles for " << more2.label() << ": " << more2.sum() << endl;

    return 0;
}
