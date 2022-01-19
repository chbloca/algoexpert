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
	vector<int> result;
	for (int i = 0; i < array.size(); i++) {
		for (int j = 0; j < array.size(); j++) {
			if ((i != j) && (array[i] + array[j] == targetSum)) {
                result.push_back(array[i]);
                result.push_back(array[j]);             
            }
		}
	}
  return result;
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