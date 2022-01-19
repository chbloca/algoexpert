/**
 * Sample Input
 * array = [3, 5, -4, 8, 11, 1, -1, 6]
 * targetSum = 10
 * 
 * Sample Output
 * [-1, 11]
 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
    // Write your code here.
    // O(n^2) time | O(1) space
    // we do not iterate on the last item as there is no latter numbers to compare
    for (int i = 0; i < array.size() - 1; i++) {
        int firstNum = array[i];
        // we initialize j to the following ith number to avoid duplicated results
        // the computations are made on an upper half matrix
        for (int j = i + 1; j < array.size(); j++) {
            int secondNum = array[j];
            if (array[i] + array[j] == targetSum) {
                return vector<int> {firstNum, secondNum};             
            }
        }
    }
    return {};
}

int main () {
    vector<int> output = twoNumberSum({3, 5, -4, 8, 11, 1, -1, 6}, 10);

    for (auto& i: output) {
        cout << i << endl;
    }
}