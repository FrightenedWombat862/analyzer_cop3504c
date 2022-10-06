#include <iostream>
#include <cmath>
#include "StringData.h"

using namespace std;

// uses a linear search algorithm to return the index integer of the given string, or -1 if not found
int linear_search(vector<string> container, string element) {
    for (int i = 0; i < container.size(); ++i) {
        if (container[i] == element) {
            return i;
        }
    }
    return -1;
}

// uses a binary search algorithm to return the index integer of the given string, or -1 if not found
int binary_search(vector<string> container, string element) {

    int upper = container.size();
    int lower = -1;
    int i = lower + floor((upper - lower) / 2);

    while (i != upper && i != lower) {
        if (container[i] == element) {
            return i;
        }
        else if (container[i] > element) {
            upper = i;
            i = lower + floor((upper - lower) / 2);
        }
        else if (container[i] < element) {
            lower = i;
            i = lower + floor((upper - lower) / 2);
        }
    }

}

int main() {

    vector<string> all_strings = getStringData();

    cout << endl;

    auto time_init = chrono::system_clock::now();
    int result = linear_search(all_strings, "not_here");
    auto time_end = chrono::system_clock::now();
    auto time_diff = time_end - time_init;
    cout << "Linear result for 'not here': " << result << " ;   Time = " << time_diff.count() << " seconds" << endl;

    return 0;

}