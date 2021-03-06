/**
 * Sample Input
 * array  = [-1, -5, -10, -1100, -1100, -1101, -1102, -9001]
 * 
 * Sample Output
 * true
 */

#include <iostream>
#include <vector>

using namespace std;

bool isMonotonic(vector<int> array) {
    // Write your code here.
    // O(n) time
    // O(1) space
    bool isNonDecreasing = true;
    bool isNonIncreasing = true;

    for (int i = 1; i < array.size(); i++) {
        if (array[i] < array[i - 1]) {
            isNonDecreasing = false;
        }

        if (array[i] > array[i - 1]) {
            isNonIncreasing = false;
        }
    }

    return isNonDecreasing || isNonIncreasing;
}

int main() {
    bool result = isMonotonic({-1, -5, -10, -1100, -1100, -1101, -1102, -9001});
    cout << result << endl;
}