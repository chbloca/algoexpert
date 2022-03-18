/**
 * Sample Input
 * array = [2, 1, 5, 2, 3, 3, 4]
 * 
 * Sample Output
 * 2 //2 is the first integer that appears more than once
 * // 3 also appears more than once, but the second 3 appears after the second 2
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int firstDuplicateValue(vector<int> array) {
    // O(n) time
    // O(n) space
    unordered_map<int, bool> seen;

    for (int &value : array) {
        if (seen.find(value) != seen.end()) {
            return value;
        }
        seen[value] = true;
    }
    return -1;    
}

int firstDuplicateValueEnhanced(vector<int> array) {
    // O(n) time
    // O(1) space
    for (int &value : array) {
        int absValue = abs(value);
        if (array[absValue - 1] < 0)
            return absValue;
        array[absValue - 1] *= -1;
    }
    return -1;    
}

int main () {
    int result = firstDuplicateValue({2, 1, 5, 2, 3, 3, 4});
    int resultEnhanced = firstDuplicateValueEnhanced({2, 1, 5, 2, 3, 3, 4});
}