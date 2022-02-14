/**
 * Sample Input
 * string = "xyz"
 * key = 2
 * 
 * Sample Output
 * "zab"
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

char getLetterCode(char letter, int key) {
    int newLetterCode = letter + key;
    return newLetterCode <= 122 ? newLetterCode : 96 + newLetterCode % 122; // a = 97, z = 122
}

string caesarCypherEncryptor(string str, int key) {
    // Write your code here.
    // O(n) time
    // O(n) space

    vector<char> newLetters;

    int newKey = key % 26; // 26 is the # of letters in the alphabet

    for (auto &letter : str) {
        newLetters.push_back(getLetterCode(letter, newKey));
    }

    return string(newLetters.begin(), newLetters.end());
}

int main () {
    string result = caesarCypherEncryptor("xyz", 2);

    cout << result << endl;
}