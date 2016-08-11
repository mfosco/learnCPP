#include <iostream>

void doPrint() {
    std::cout << "In doPrint\n";
}

//Add 2 numbers together
int add(int x, int y) {
    return x + y;
}

// Basic Hello World program
int main()
{
    using std::cout; //declaration tells compiler that cout should resolve to std::cout
    cout << "Hello world!" << std::endl;
    cout << "It is very nice to meet you!" << std::endl;
    int x = 4;
    cout << "The value of x is: " << x;
    cout << "\nDoes this \n split?\n";
    //cout << "Enter value for x: ";
    //read input from user:
    doPrint();
    //std::cin >> x;
    //cout << "You entered: " << x << "\n";
    /* This is a mulit-line
     * comment */
    return 0;
}
