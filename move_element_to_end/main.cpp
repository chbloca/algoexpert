/**
 * Sample Input
 * array = [2, 1, 2, 2, 2, 3, 4, 2]
 * toMove = 2
 * 
 * Sample Output
 * [1, 3, 4, 2, 2, 2, 2, 2] // the numbers 1, 3, and 4 could be ordered differently
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> moveElementToEnd(vector<int> array, int toMove) {
  // Write your code here.
  // O(n) time
  // O(1) space

  int i = 0;
  int j = array.size() - 1;

  while (i < j) {
      while (i < j && array[j] == toMove){
          j--;
      }
      if (array[i] == toMove) {
        swap(array[i], array[j]);
      }
      i++;

  }

  return array;
}

int main() {
    vector<int> result = moveElementToEnd({2, 1, 2, 2, 2, 3, 4, 2}, 2);
}