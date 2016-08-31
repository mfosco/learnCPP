#include <iostream>
#include <utility>
#include <cstring>

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

    int array[] = {1, 4, 3, 2, 99, 88, -4, 9, 44, 20, 22};
    int size = sizeof(array)/sizeof(array[0]);

    printArray(array, size);
    selectionSort(array, size);
    printArray(array, size);

    char source[] = "copy this!";
    char dest[50];
    strcpy(dest, source); //should use strncpy(dest, source, strlen(dest)-1);
    cout << dest << '\n';

    return 0;
}
