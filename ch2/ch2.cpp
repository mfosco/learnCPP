/* * Michael Fosco
 * Chapter 2 of learnCPP
 */

#include <iostream>
#include <iomanip> //for setprecision

#define MAX_STUDENTS_PER_CLASS 30

#include "constants.h"

void doPrint() {
    std::cout << "In doPrint\n";
}

//use void to say no input params
//though empty parens are the preferred method
int getValue()
{
    int x;
    std::cin >> x;
    return x;
}

int main()
{
    using std::cout; //declaration tells compiler that cout should resolve to std::cout
    int nValue = 5; //copy initialization
    int tVariable(5); //direct initialization

    
    //int value{5}; // uniform initialization
    //int xValue{}; // default initialization of 0

    int c(7), d(8);
    //define variables as close to their first use as possible

    long long ll;
    short s;
    unsigned char ck;
    unsigned int z;

    double du(5.0);
    float f(5.0f);

    double d1(5000.0);
    double d2(5e3);
    bool b = d1 == d2;
    cout << (d1 == d2) << std::endl; 
    float f1 = 3.33333333333333333333333333f;
    cout << f1 << std::endl;
    cout << std::setprecision(16);

    cout << f1 << std::endl;

    if (b) {
        cout << "In if\n";
    } else {
        cout << "In else\n";
    }

    char ch(97);
    cout << ch << '\n';
    cout << static_cast<int>(ch) << '\n';
    cout << ch << '\n';

    cout << "Alert: " << '\a' << '\n';

    const double gravity(9.8);
    //can use const for function parameters to tell caller that the inputted
    //variable won't change
    //constexpr is used to say this is a compile-time constant

    //constants:: lets us access pi
    double circum = 2*5 * constants::pi;
    cout << circum << '\n';


    return 0;
}
