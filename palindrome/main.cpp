/**
 * Sample Input
 * string = "abcdcba"
 * 
 * Sample Output
 * true // it's written the same forward and backward
 */

#include <iostream>

using namespace std;

bool isPalindrome(string str) {
    // Write your code here.
    // O(n) time
    // O(1) space
    int leftIdx = 0;
    int rightIdx = str.size() - 1;

    while (leftIdx != rightIdx) {
        if (str[leftIdx] != str[rightIdx])
            return false;

        leftIdx++;
        rightIdx--;        
    }

    return true;
}

int main () {
    bool result = isPalindrome("abcdeba");

    cout << result << endl;
}