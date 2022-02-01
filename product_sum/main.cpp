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

// Tip: You can use el.type() == typeid(vector<any>) to check whether an item is
// a list or an integer.
// If you know an element of the array is vector<any> you can cast it using:
//     any_cast<vector<any>>(element)
// If you know an element of the array is an int you can cast it using:
//     any_cast<int>(element)
int productSum(vector<any> array, int multiplier = 1) {
    // Write your code here.
    // O(n) time where n is 12 [total number of elements and sub elements]
    // O(d) space where d is the maximum depth of the recursive calls
    int sum = 0;
    for (auto element : array) {
        if (element.type() == typeid(vector<any>)) {
            sum += productSum(any_cast<vector<any>>(element), multiplier + 1);
        } else {
            sum += any_cast<int>(element);
        }
    }
    return sum * multiplier;
}

int main () {
    vector<any> test = {5, 2, vector<any>{7, -1}, 3, vector<any>{6, vector<any>{-13, 8}, 4}};
    int output = productSum(test);

    cout << output << endl;
}