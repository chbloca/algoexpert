/**
 * Sample Input
 * array = [0, 1, 21, 33, 45, 45, 61, 71, 72, 73]
 * target = 33   
 * 
 * Sample Output
 * 3
 */

#include <iostream>
#include <vector>

using namespace std;

int binarySearchRecursiveHelper(vector<int> &array, int &target, int left, int right) {
    if (left > right) {
        return -1;
    }
    int middle = (left + right) / 2;
    int potentialMatch = array[middle];

    if (target == potentialMatch) {
        return middle;
    } else if (target < potentialMatch) {
        return binarySearchRecursiveHelper(array, target, left, middle - 1);
    } else {
        return binarySearchRecursiveHelper(array, target, middle + 1, right);
    }
}

int binarySearchRecursive(vector<int> array, int target) {
  // Write your code here.
  // It requires a sorted array
  // O(log n) time
  // O(log n) space
  return binarySearchRecursiveHelper(array, target, 0, array.size() - 1);
}

int binarySearch(vector<int> array, int target) {
    // Write your code here.
    // It requires a sorted array
    // O(log n) time
    // O(1) space
    int left = 0;
    int right = array.size() - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        int potentialMatch = array[middle];

        if (target == potentialMatch) {
            return middle;
        } else if (target < potentialMatch) {
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }
    return -1;
}

int main () {
    int result_recursive = binarySearchRecursive({0, 1, 21, 33, 45, 45, 61, 71, 72, 73}, 33);
    int result = binarySearch({0, 1, 21, 33, 45, 45, 61, 71, 72, 73}, 33);

    cout << result_recursive << endl;
    cout << result << endl;
}