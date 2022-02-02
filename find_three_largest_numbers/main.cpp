/**
 * Sample Input
 * array = [141, 1, 17, -7, -17, -27, 18, 541, 8, 7, 7]
 * 
 * Sample Output
 * [18, 141, 541]
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

vector<int> findThreeLargestNumbersNaive(vector<int> array) {
    // Write your code here.
    // O(n log n) time
    // O(1) space
    sort(array.begin(), array.end());

    return {array[(array.size() - 1) - 2], array[(array.size() - 1) - 1], array[(array.size() - 1) - 0]};
}

/// ---------------------------------------------------------------------------------------------------------

void shiftAndUpdate(vector<int> &array, int num, int idx) {
    // [0, 1, 2]
    // [x, y, z]
    // if i == 2
    // [y, z, num]
    for (int i = 0; i <= idx; i++) {
        if (i == idx) {
            array[i] = num;
        } else {
            array[i] = array[i + 1];
        }
    }
}

void updateLargets(vector<int> &threeLargest, int num) {
    if (threeLargest[2] == INT_MIN || num > threeLargest[2]) {
        shiftAndUpdate(threeLargest, num, 2);
    } else if (threeLargest[1] == INT_MIN || num > threeLargest[1]) {
        shiftAndUpdate(threeLargest, num, 1);
    } else if (threeLargest[0] == INT_MIN || num > threeLargest[0]) {
        shiftAndUpdate(threeLargest, num, 0);
    }
}

vector<int> findThreeLargestNumbers(vector<int> array) {
    // Write your code here.
    // O(n) time
    // O(1) space
    vector<int> threeLargest {INT_MIN, INT_MIN, INT_MIN};

    for (auto &element : array) {
        updateLargets(threeLargest, element);
    }

    return threeLargest;
}

int main () {
    vector<int> result_naive = findThreeLargestNumbersNaive({141, 1, 17, -7, -17, -27, 18, 541, 8, 7, 7});
    vector<int> result = findThreeLargestNumbers({141, 1, 17, -7, -17, -27, 18, 541, 8, 7, 7});

    for (auto &element : result_naive) {
        cout << element << endl;
    }

    for (auto &element : result) {
        cout << element << endl;
    }
}