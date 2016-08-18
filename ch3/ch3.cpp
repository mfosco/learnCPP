#include <cmath>
#include <bitset>
#include <iostream>

//My power function. Note, exp >=0
//Could have overflow problems
int myPow(int base, unsigned int exp) {
    int result = 1;

    while (exp) {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }
    return result;
}

//Return true if diff btwn a and b is less than absEpsilon or
//return true if diff btwn a and b is within relEpsilon percent of the
//larger of a and b
bool approxEqual(double a, double b, double absEpsilon, double relEpsilon) {
    double difference = fabs(a-b);
    if (difference <= absEpsilon)
        return true;

    return fabs(a-b) <= ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) *relEpsilon); 
}

int main() {
    using std::cout;
    using std::bitset;
    //double x = pow(3.0, 4.0);
    int x = 7;
    int y = 4;

    cout << "int / int = " << x/y << '\n';
    cout << "double/int = " << x / static_cast<double>(y) << '\n';

    int a = 0;
    int b = 2;
    int z = (++a, ++b); //increment a and b
    cout << "Z: " << z << '\n';

    bool testy = true;
    int c;
    (testy) ? c = 1: c = 0;

    int larger = (x > y) ? x : y;


    const unsigned char option1 = 0x01; 

    const unsigned char option4 = 0x08;
    const unsigned char option5 = 0x10; //hex for 0001 0000

    const unsigned char option8 = 0x80;

    unsigned char myflags = 0;

    if (myflags & option8)
        cout << "Something" << '\n';


    myflags &= ~option4 & ~option5;//turn 4 and 5 off

    //can use bit flags to optimize memory usage

    bitset<8> bits;//need 8 bits

    //can set up as bitset<8> bits(option1 | option2);
    //bitset has test() (see if bit is on/off)
    //set() (turn bit on)
    //reset() (turn bit off)
    //flip() (flip bit from 0 to 1 and vice versa)
    //position of rt-most bit is 0
    return 0;
}
