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

vector<int> twoNumberSum(vector<int>& array, int& targetSum) {
  // Write your code here.
    for (int i = 0; i < array.size(); i++) {
        int firstNum = array[i];
        for (int j = 0; j < array.size(); j++) {
            int secondNum = array[j];
            if (array[i] + array[j] == targetSum) {
                return vector<int> {firstNum, secondNum};             
            }
        }
    }
    return {};
}

int main () {
    vector<int> array {3, 5, -4, 8, 11, 1, -1, 6};
    int targetSum = 10;

    vector<int> result;

    result = twoNumberSum(array, targetSum);

    for (auto& i: result) {
        cout << i << endl;
    }
}