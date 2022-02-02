/**
 * Sample Input
 * array = [141, 1, 17, -7, -17, -27, 18, 541, 8, 7, 7]
 * 
 * Sample Output
 * [18, 141, 541]
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> findThreeLargestNumbers(vector<int> array) {
  // Write your code here.
  return {};
}

int main () {
    vector<int> result = findThreeLargestNumbers({141, 1, 17, -7, -17, -27, 18, 541, 8, 7, 7});

    for (auto &element : result) {
        cout << element << endl;
    }
}