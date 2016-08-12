/*
 * Michael Fosco
 * Chapter 1 of learnCPP
 */

#include <iostream>
#include "add.h"

void doPrint() {
    std::cout << "In doPrint\n";
}

//int add(int x, int y);

//void testLink();

//Add 2 numbers together
/*int add(int x, int y) {
    return x + y;
}*/

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
    cout << add(5,4) << std::endl;
    testLink();
    //std::cin >> x;
    //cout << "You entered: " << x << "\n";
    /* This is a mulit-line
     * comment */
    return 0;
}
