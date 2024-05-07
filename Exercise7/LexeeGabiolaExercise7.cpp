/*
* Lexee Gabiola
* 10/24/2022
* This file is designed to meet the requirements of Exercise 7 from CS 1181.
*/

#include <iostream>
#include <string>
#include <ctime>
#include <thread>

using namespace std;

/*
* Lexee Gabiola
* 10/24/2022
* This function accepts a string and returns the character with the largest ASCII value
*/
char largestChar(string s1) {
    char largestChar = ' ';
    for (int i = 0; i < s1.length(); ++i) {
        if (s1[i] > s1[i + 1]) {
            if (s1[i] > largestChar) {
                largestChar = s1[i];
            }
        }
    }
    return largestChar;
}

/*
* Lexee Gabiola
* 10/31/2022
* This function accepts a 1D array of integers and an integer size, and returns the index of the minimum value in the array
*/
int minIndex(int a[], int aSize) {
    int minIndex = 0;
    for (int i = 1; i < aSize; ++i) {
        if (a[i] < a[i + 1] || a[i] < a[i - 1]) {
            if (a[i] < a[minIndex]) {
                minIndex = i;
            }
        }
    }
    return minIndex;
}

/*
* Lexee Gabiola
* 10/31/2022
* This function accepts a 1D array of integers and an integer size, and returns the minimum value in the array
*/
int minValue(int a[], int aSize) {
    return a[minIndex(a, aSize)];
}

/*
* Lexee Gabiola
* 11/1/2022
* This function accepts a 1D array of integers and an integer size, and returns the second to largest value
*/
int penultimateValue(int a[], int aSize) {
    int maxValue = 0;
    int penultValue = 0;
    for (int i = 0; i < aSize; ++i) {
        if (a[i] >= a[i + 1] || a[i] >= a[i - 1]) {
            if (a[i] >= penultValue && !(a[i] >= maxValue)) {
                penultValue = a[i];
            }
            else if (a[i] >= maxValue) {
                penultValue = maxValue;
                maxValue = a[i];
            }
        }
    }
    return penultValue;
}

/*
* Lexee Gabiola
* 11/1/2022
* This function accepts a string and returns a count of upper and lower case letters
*/
int letterCount(string s2) {
    int countOfLetters = 0;
    for (int i = 0; i < s2.length(); ++i) {
        if (s2[i] >= 'A' && s2[i] <= 'Z') {
            countOfLetters += 1;
        }
        else if (s2[i] >= 'a' && s2[i] <= 'z') {
            countOfLetters += 1;
        }
    }
    return countOfLetters;
}
/*
* Lexee Gabiola
* 11/1/2022
* This function accepts an integer array and returns the index of the second to last occurrence of a target
*/
int penultimateTarget(int a[], int aSize, int b) {
    int targetLastIndex = -1;
    int targetPenultIndex = -1;
    for (int i = 0; i < aSize; ++i) {
        if (a[i] == b) {
            targetPenultIndex = targetLastIndex;
            targetLastIndex = i;
        }
    }
    return targetPenultIndex;
}

/*
* Lexee Gabiola
* 11/1/2022
* This function counts the number of times an integer occurs in an array
*/
int countTarget(int a[], int aSize, int t) {
    int targetCount = 0;
    for (int i = 0; i < aSize; ++i) {
        if (a[i] == t) {
            targetCount += 1;
        }
    }
    return targetCount;
}

/*
* Lexee Gabiola
* 11/1/2022
* This function accepts an array, an integer array size, and an integer, and adds that integer to all array elements
*/
void increaseArray(int a[], int SizeA, int n) {
    cout << "Increased array: { ";
    for (int i = 0; i < SizeA; ++i) {
        cout << (a[i] += n) << ", ";
    }
    cout << "}" << endl;
}

/*
* Lexee Gabiola
* 11/1/2022
* This function calculates the sum of all the values in an array of integers
*/
int sumArrayIntegers(int a[], int aSize) {
    int sum = 0;
    for (int i = 0; i < aSize; ++i) {
        sum += a[i];
    }
    return sum;
}

/*
* Lexee Gabiola
* 11/1/2022
* This function calculates the mean of all the values in an array of integers
*/
int arrayMean(int a[], int aSize) {
    int mean;
    mean = sumArrayIntegers(a, aSize) / aSize;
    return mean;
}

/*
* Lexee Gabiola
* 11/1/2022
* This function uses a bubble sort to sort an array in decending order
*/
void arrayBubbleSort(int a[], int aSize) {
    for (int i = aSize - 1; i > 0; --i) {
        for (int j = aSize - 1; j > aSize - i - 1; --j) {
            if (a[j] < a[j - 1]) {
                int temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
        }
    }

    cout << "Sorted array: { ";
    for (int i = 0; i < aSize; ++i) {
        if (i != aSize - 1) {
            cout << a[i] << ", ";
        }
        else {
            cout << a[i];
        }
    }
    cout << " }" << endl;
}

/*
* Lexee Gabiola
* 10/24/2022
* This main function shows that all of the above functions work correctly.
*/
int main() {
    string s1;
    cout << "Enter a string: ";
    getline(cin >> ws, s1);
    cout << "The character with the largest ASCII is: " << largestChar(s1) << endl;

    const int aSize = 10;
    int a[aSize]{};
    cout << "Your random array: { ";
    for (int i = 0; i < aSize; ++i) {
        a[i] = rand() % 10;
        if (i != aSize - 1) {
            cout << a[i] << ", ";
        }
        else {
            cout << a[i];
        }
    }
    cout << " }" << endl;

    cout << "Index of lowest value: [" << minIndex(a, aSize) << "]" << endl;
    cout << "Lowest value in array: " << minValue(a, aSize) << endl;

    cout << "Second to largest value: " << penultimateValue(a, aSize) << endl;

    string s2;
    cout << "Enter another string: ";
    getline(cin >> ws, s2);
    cout << "The number of letters in this string: " << letterCount(s2) << endl;

    int target;
    cout << "Enter a target for the earlier array: ";
    cin >> target;
    cout << "The second to last occurance of the target is at index [" << penultimateTarget(a, aSize, target) << "]" << endl;
    cout << "The number of times this target occurs is: " << countTarget(a, aSize, target) << endl;

    int increase;
    cout << "Enter a number to increase your array elements by: ";
    cin >> increase;
    increaseArray(a, aSize, increase);

    cout << "The mean of the elements in the increased array is: " << arrayMean(a, aSize) << endl;

    // get starting value of timer
    clock_t start = clock();

    //code to be timed goes here
    arrayBubbleSort(a, aSize);

    // get ending value of timer
    clock_t end = clock();

    cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
}

/* Results for Bubble Sort Timer
* 100 = 0.016
* 1000 = 0.565
* 10000 = 1.823
* 100000 = 49.083
* 250000 = 284.543
* Based on the results, it is clear that the bubble sort takes an exponentially increasing amount
* of time to run as the size of the array increases.
*/
