/**
 * Sample Input
 * array = [1, 2, 3, 4, 5, 6, 7, 8, 9]
 * array = [-2, 1, 3, 4, 5, 6, 7, 8, 9]
 * 
 * Sample Output
 * [1, 4, 9, 25, 36, 64, 81]
 * [1, 4, 9, 25, 36, 64, 81]
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sortedSquaredArray(vector<int> array) {
  // Write your code here.
  // O(n logn) time (as we need to sort the output vector) | O(n) space (since we store values in a new vector)
  // actually time complexity es n (loop) + n log n (sort), bot the O notation simplifies to n log n
  vector<int> result;
  for (auto& element : array) {
      result.push_back(element * element);
  }
  sort(result.begin(), result.end()); // this fixes the case there are negative values in the input
  return result;
}

int main () {
    vector<int> output = sortedSquaredArray({-2, 1, 3, 4, 5, 6, 7, 8, 9});

    for (auto& i : output) {
        cout << i << endl;
    }
}