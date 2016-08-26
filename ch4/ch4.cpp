#include <iostream>
#include "constants.h"
#include "foo.h"
#include "goo.h"
#include <string>

static int g_x; //global variable g_x can now only be used in this file

struct Employee
{
    short id;
    int age;
    double wage;
};

struct Company
{
    Employee CEO;
    int numEmployees;
};

//Company myCompany = {{1, 42, 60000.0f},5}

// auto d = 5.0; <=> double d = 5.0;
/*
 * typedef double distance_t; //define distance_t as an alias for double
 * using distance_t = double; is equivalent to line above
 * double howFar;
 * distance_t howFar; //both statements are equivalent
 * */

enum class Color
{
    BLACK,
    RED,
    BLUE,
    GREEN,
    WHITE,
    CYAN,
    YELLOW,
    MAGENTA
};

const int g_y(2); //global variable g_y
int val(5);
extern double g_yy(9.8); //g_yy is external, can be used by other files

static double g_gravityII(9.8);

int something() {
    g_x = 3;
    std::cout << g_y << '\n';
    return 5;
}

double getGravity()
{
    return g_gravityII;
}

//this function is static, so it can now only be used in this file
static int add( int x, int y) {
    return x+y;
}

namespace Uh
{
    namespace Oh
    {
        const int g_xx(5);
    }
}

namespace Boo = Uh::Oh;

int main()
{
    using std::cout;
    using std::string;
    g_x = 5;
    std::cout << g_y << '\n';
    int val = 7;
    val++;
    ::val--;
    cout << "global val: " << ::val << '\n';
    cout << "local value: " << val << '\n';
    
    //could do: using Foo::doSomething;

    cout << Foo::doSomething(4,3) << '\n';
    cout << Goo::doSomething(4,3) << '\n';

    cout << Boo::g_xx << '\n';

    //following c-style cast is not good
    int i1 = 10;
    int i2 = 4;
    float f = (float)i1 / i2;

    //static cast:
    int i11 = 10;
    float f2 = static_cast<float>(i11) / i2;

    cout << f << '\n';

    string myName("Mike");
    cout << "My name is: " << myName << '\n';

    /*std::cout << "Enter your full name: ";
    string name;
    std:getline(std::cin, name);

    cout << "Enter your age: ";
    string age;
    std::getline(std::cin, age);

    cout << "Your name is " << name << " and your age is " << age << '\n';
    //std::cin.ignore(32767, '\n'); means ignore up to 32767 characters until a
    //\n is removed
    //myName.length();
    */
    Color paint = Color::YELLOW;
    cout << static_cast<int>(paint) << '\n';

    Employee joe = {1, 32, 50000.0};
    
        
    return 0;
}


