/**
 * Sample Input
 * string = "abcdcba"
 * 
 * Sample Output
 * true // it's written the same forward and backward
 */

#include <iostream>

using namespace std;

bool helper(string str, int i) {
    int j = str.length() - 1 - i;
    return i >= j ? true : str[i] == str[j] && helper(str, i + 1);
}

bool isPalindromeRecursive(string str) {
    // O(n) time
    // O(n) space
    return helper(str, 0);
}

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
    bool resultRecursive = isPalindromeRecursive("abcdcba");
    bool result = isPalindrome("abcdcba");

    cout << resultRecursive << endl;
    cout << result << endl;
}