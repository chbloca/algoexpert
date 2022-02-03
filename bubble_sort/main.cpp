/**
 * Sample Input
 * array = [8, 5, 2, 9, 5, 6, 3]
 * 
 * Sample Output
 * [2, 3, 5, 5, 6, 8, 9]
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> bubbleSort(vector<int> array) {
    // Write your code here.
    // O(n^2) time for the worst / average case, since the array is traversed multiple times
    // O(n) time for the best case, since the array is traversed once
    // O(1) space
    bool isSorted = false;
    int counter = 0;
    while (!isSorted) {
        isSorted = true;
        for (int i = 0; i < array.size() - 1 - counter; i++) {
            if (array[i] > array[i + 1]) {
                swap(array[i], array[i + 1]);
                isSorted = false;
            }
        }
        counter++;
    }
    return array;
}

int main () {
    vector<int> result = bubbleSort({8, 5, 2, 9, 5, 6, 3});

    for (auto &element : result) {
        cout << element << endl;
    }
}