/**
 * Sample Input
 * array = [
 * [1,   2,  3, 4],
 * [12, 13, 14, 5],
 * [11, 16, 15, 6],
 * [10,  9,  8, 7],
 * ]
 * 
 * Sample Output
 * [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16]
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralTraverse(vector<vector<int>> array) {
    // Write your code here.
    // O(n) time
    // O(n) space
    if (array.size() == 0)
      return {};
	
    vector<int> result = {};

    int startRow = 0;
    int endRow = array.size() - 1;
    int startCol = 0;
    int endCol = array[0].size() - 1;

    while (startRow <= endRow && startCol <= endCol) {
      for (int col = startCol; col <= endCol; col++) {
        result.push_back(array[startRow][col]);
      }

      for (int row = startRow + 1; row <= endRow; row++) {
        result.push_back(array[row][endCol]);
      }

      for (int col = endCol - 1; col >= startCol; col--) {
        result.push_back(array[endRow][col]);
      }

      for (int row = endRow - 1; row > startRow; row--) {
        result.push_back(array[row][startCol]);
      }

      startRow++;
      endRow--;
      startCol++;
      endCol--;
    }

    return result;
}


int main() {
    vector<int> result = spiralTraverse({{1, 2, 3, 4}, {12, 13, 14, 5}, {11, 16, 15, 6}, {10,  9,  8, 7}});
}