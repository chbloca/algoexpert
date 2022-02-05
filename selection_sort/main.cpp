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

vector<int> selectionSort(vector<int> array) {
  // Write your code here.
  // O(n^2) time
  // O(1) space

  int currentIdx = 0;

  while (currentIdx < array.size() -1) {
      int smallestIdx = currentIdx;
      for (int i = currentIdx; i < array.size(); i++) {
          if (array[smallestIdx] > array[i]) {
              smallestIdx = i;
          }
      }
      swap(array[currentIdx], array[smallestIdx]);
      currentIdx++;
  }
  return array;
}

int main () {
    vector<int> result = selectionSort({8, 5, 2, 9, 5, 6, 3});

    for (auto &element : result) {
        cout << element << endl;
    }
}