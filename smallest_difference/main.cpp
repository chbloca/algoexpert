/**
 * Sample Input
 * arrayOne = [-1, 5, 10, 20, 28, 3]
 * arrayTwo = [26, 134, 135, 15, 17]
 * 
 * Sample Output
 * [28, 26]
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
    // Write your code here.
    // O(n logn + m logm) time
    // O(1) space

    sort(arrayOne.begin(), arrayOne.end());
    sort(arrayTwo.begin(), arrayTwo.end());

    int idxOne = 0;
    int idxTwo = 0;
    int smallest = INT_MAX;
    int current = INT_MAX;

    vector<int> smallestPair;

    while (idxOne < arrayOne.size() && idxTwo < arrayTwo.size()) {
        int firstNum = arrayOne[idxOne];
        int secondNum = arrayTwo[idxTwo];

        if (firstNum < secondNum) {
            current = secondNum - firstNum;
            idxOne++;
        } else if (secondNum < firstNum) {
            current = firstNum - secondNum;
            idxTwo++;
        } else { // if they are equal
            return {firstNum, secondNum};
        }

        if (smallest > current) {
            smallest = current;
            smallestPair = {firstNum, secondNum};
        }
    }

    return smallestPair;
}

int main() {
    vector<int> result = smallestDifference({-1, 5, 10, 20, 28, 3}, {26, 134, 135, 15, 17});
}