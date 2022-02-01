/**
 * Sample Input
 * array = [5, 2, [7, -1], 3, [6, [-13, 8], 4]]
 * 
 * Sample Output
 * 12 // calculated as: 5 + 2 + 2 * (7 - 1) + 3 + 2 * (6 + 3 * (-13 + 8) + 4)
 */

#include <iostream>
#include <vector>
#include <any>

using namespace std;

int productSum(vector<any> array) {
  // Write your code here.
  return -1;
}

int main () {
    vector<any> test = {5, 2, vector<any>{7, -1}, 3, vector<any>{6, vector<any>{-13, 8}, 4}};
    int output = productSum(test);

    cout << output << endl;
}