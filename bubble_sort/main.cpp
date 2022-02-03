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
  return {};
}

int main () {
    vector<int> result = bubbleSort({8, 5, 2, 9, 5, 6, 3});

    for (auto &element : result) {
        cout << element << endl;
    }
}