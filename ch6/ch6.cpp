#include <iostream>
#include <utility>
#include <cstring>
#include <cstddef>
#include <array>
#include <algorithm>
#include <vector>

struct Person {
    int age;
    double weight;
};

void selectionSort(int array[], int size) {
    using std::swap;
    using std::cout;

    for (int startIndex=0; startIndex<size; ++startIndex) {
        int smallestIndex = startIndex;

        for (int currIndx = startIndex+1; currIndx < size; ++currIndx) {
            if (array[currIndx] < array[smallestIndex]) 
                smallestIndex = currIndx;
        }
        swap(array[startIndex], array[smallestIndex]);
    }
}

void doSomething(std::nullptr_t ptr) {
    std::cout << "In doSomething()\n";
}

void printArray(int array[], int size) {
    using std::cout;

    for (int i=0; i < size; ++i) {
        cout << array[i] << ' ';

        if (!(i % 9) && i > 0)
            cout << '\n';
    }
    cout << '\n' << '\n';
}

int main() {
    using std::cout;
    using std::cin;
    using std::array;
    using std::vector;

    int prime[5];
    prime[0] =2;
    prime[1] = 3;
    prime[2] = 5;
    prime[3] = 7;
    prime[4] = 11;

    cout << "Sum of first 5 primes is: " << prime[0] + prime[1] + prime[2] + prime[3]+prime[4] << '\n';

    //or
    int primeII[5] = {2,3,5,7,11};//or int primeII[] = {2,3,5,7,11};
    //actual array is passed into function in C++
    
    int scores[] = {84, 92, 76, 81,56};
    const int numStudents = sizeof(scores) / sizeof(scores[0]);
    int totalScore=0;

    int x = 2;
    int y = 4;
    std::swap(x,y);

    cout << "After x = " << x << ", y = "<< y << '\n';

    for (int i =0; i < numStudents; ++i) 
        totalScore += scores[i];

    double avgScore = static_cast<double>(totalScore)/numStudents;

    cout << "Avg score is: " << avgScore << '\n';

    int marray[] = {1, 4, 3, 2, 99, 88, -4, 9, 44, 20, 22};
    int size = sizeof(marray)/sizeof(marray[0]);

    printArray(marray, size);
    selectionSort(marray, size);
    printArray(marray, size);

    char source[] = "copy this!";
    char dest[50];
    strcpy(dest, source); //should use strncpy(dest, source, strlen(dest)-1);
    cout << dest << '\n';
    int value =5;
    int *ptr = &value;

    int *nPtr(nullptr);//nPtr is now a null ptr

    int *iPtr = new int; //dynamically allocate an integer and assign address to ptr
    *iPtr = 7;

    int *ptr1 = new int(5);

    delete iPtr;//return memory of iPtr to OS
    delete ptr1;

    int *tVal = new (std::nothrow) int;
    //remember: can't dereference a null ptr
    //but you can always delete ptr if ptr is null, just not *ptr

    int *alArray = new int[50];

    alArray[0]=5;
    delete[] alArray; //use array delete to deallocate array
    alArray = nullptr;

    int dA[5] = {9, 7, 5, 3, 1};

    int *dArray = dA;
    delete[] dArray;

    const int vals = 5;
    const int *cPtr = &vals;
    //*cPtr = 6; is not allowed
    int valy = 88;
    const int *cPtrII = &valy;//also good

    int vall = 5;
    int *const ptrr = &vall;//ptrr is now a constant ptr

    int &ref = vall;//reference to variable vall

    Person person;
    Person *pPtr = &person;
    (*pPtr).age = 5;
    //or
    pPtr -> age = 10;

    int fib[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};

    //good place to use "auto" instead of type
    //ref means we aren't making an unnecessary copy of the array
    for (auto &num : fib)
        cout << num << ' ';
    cout << '\n';

    //std array won't decay to pointer when passed to function
    array<int,3> myStdArray = {9,7,5};
    myStdArray.at(1) = 77;
    int sizey = myStdArray.size();

    std::sort(myStdArray.begin(), myStdArray.end());

    vector<int> vect1;
    vector<int> vect = {9,7,5,3};
    vect[1] = 33;
    vect.at(0) = 99;
    //vector automatically deallocated when it goes out of scope
    int vSize = vect.size();
    cout << vSize << '\n';
    vect.resize(60);
    vSize = vect.size();
    cout << vSize << '\n';

    //must cast void pointer before dereferencing it
    return 0;
}
