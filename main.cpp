#include <iostream>
#include <vector>
#include <string>
#include <chrono>

#include "StringData.h"

using namespace std;

int linearSearch(vector<string> container, string element) {
    int index = -1;
    for (int i = 0; i < container.size(); i++) {
        if (container[i] == element) {
            index = i;
            break;
        }
    }
    return index;
}

// Horribly inefficient algorithm on memory (in C++, but works perfectly fine in Python), but I don't know how to code a better one in C++
int binarySearch(vector<string> container, string element, int minValue, int maxValue) {
    if (minValue == maxValue) {
        if (container[minValue] == element) {
            return minValue;
        }
        else {
            return -1;
        }
    }
    else if (element < container[(minValue + maxValue) / 2]) {
        return binarySearch(container, element, minValue, (minValue + maxValue) / 2);
    }
    else if (element > container[(minValue + maxValue) / 2]) {
        return binarySearch(container, element, (minValue + maxValue) / 2 + 1, maxValue);
    }
    else {
        return (minValue + maxValue) / 2;
    }
}

void find(string needle, vector<string> haystack) {
    cout << endl << "Trying to find " << needle << " in container using linear search." << endl;
    auto start = std::chrono::system_clock::now();
    cout << "Found " << needle << " at location " << linearSearch(haystack, needle) << endl;
    auto end = std::chrono::system_clock::now() - start;
    cout << "The operation took " << end.count() / 1000000000.0 << " seconds." << endl;
    cout << "Trying to find " << needle << " in container using binary search." << endl;
    start = std::chrono::system_clock::now();
    cout << "Found " << needle << " at location " << binarySearch(haystack, needle, 0, haystack.size()) << endl;
    end = std::chrono::system_clock::now() - start;
    cout << "The operation took " << end.count() / 1000000000.0 << " seconds." << endl;  // There has GOT to be a better way to do this.
}

int main() {
    cout << "Generating the strings..." << endl;
    vector<string> container = getStringData();

    // To make binary search fast, get a computer with 128GB of memory
    find("not_here", container);
    find("mzzzz", container);
    find("aaaaa", container);

    return 0;
}
