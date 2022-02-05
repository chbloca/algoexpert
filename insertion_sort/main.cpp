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

vector<int> insertionSort(vector<int> array) {
  // Write your code here.
  // O(n^2) time for the worst/average cases
  // O(n) time for the best case
  // O(1) space

  for (int i = 0; i < array.size(); i++) {
      int j = i;
      while (j > 0 && array[j] < array[j - 1]) {
          swap(array[j], array[j -1]);
          j -= 1;
      }
  }
  return array;
}

int main () {
    vector<int> result = insertionSort({8, 5, 2, 9, 5, 6, 3});

    for (auto &element : result) {
        cout << element << endl;
    }
}