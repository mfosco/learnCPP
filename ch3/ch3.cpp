#include <cmath>
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

int main() {
    using std::cout;
    //double x = pow(3.0, 4.0);
    int x = 7;
    int y = 4;

    cout << "int / int = " << x/y << '\n';
    cout << "double/int = " << x / static_cast<double>(y) << '\n';

    return 0;
}
