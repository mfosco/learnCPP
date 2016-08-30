#include <cstdlib>
#include <iostream>
#include <cmath>
#include <ctime>
#include <random>

enum Color
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

double getDouble() {
    using std::cout;
    using std::cin;
    while (1) {
        cout << "Enter a double value: ";
        double x;
        cin >> x;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Input is invalid. Please try again.\n";
        } else {
            cin.ignore(32767,'\n');
            return x;
        }
    }
}
        

int getRandomNumber(int min, int max) {
    static const double fraction = 1.0/(static_cast<double>(RAND_MAX)+1.0);
    return static_cast<int>(rand()*fraction*(max-min+1)+min);
}

//poor pseudo random number generator
unsigned int PRNG()
{
    static unsigned int seed = 5323;
    seed = (8253729*seed + 2396403);
    return seed % 32768;
}


void printColor(Color color)
{
    using std::cout;

    switch (color)
    {
        case BLACK:
            cout << "Black";
            break; 
        case WHITE:
            cout << "White";
            break;
        case RED:
            cout << "Red";
            break;
        case GREEN:
            cout << "Green";
            break;
        case BLUE:
            cout << "Blue";
            break;
        default:
            cout << "Unknown color";
            break;
    }
    cout << '\n';
}


int main()
{
    using std::cout;
    std::random_device rd;
    std::mt19937 mersenne(rd());
    //exit(0) forces termination and return of 0 to system

    int x = 5;

    if (x > 10)
        ;//this is a null statement

    Color paint = BLUE;
    printColor(paint);

    /*
    double z;
tryAgain:
    cout << "Enter a nonneg number: ";
    std::cin >> z;

    if (z < 0.0)
        goto tryAgain;//this is a goto statement
    cout << "The sqrt of " << z << is << sqrt(z) << '\n';
    */ //Generally want to avoid goto statements

    for (int count = 0; count < 10; count++)
        cout << count << " ";
    cout << '\n';

    for (int iii =0, jjj=9; iii<10; ++iii,--jjj)
        cout << iii << " " << jjj << '\n';

    /*
    for (int ii=0; ii < 100; ++ii) {
        cout << PRNG() << '\t';
        if (!((ii+1)%5))
            cout << '\n';
    }*/

    srand(static_cast<unsigned int>(time(0)));
    for (int count=0; count <100; ++count) {
        cout << rand() <<'\t';
        if (!((count+1)%5))
            cout << '\n';
    }

    cout << "Mersenne now" << '\n';

    for (int count =0; count <48; ++count) {
        cout << mersenne() << '\t';
        if (!((count+1)%4))
            cout << '\n';
    }

    /*
     * To clear bad input from cin:
     * if(cin.fail()) {
     *  cin.clear();
     *  cin.ignore(32767,'\n');
     * }
     **/

    return 0;
}
