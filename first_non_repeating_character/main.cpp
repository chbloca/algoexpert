/**
 * Sample Input
 * string = "abcdcaf"
 * 
 * Sample Output
 * 1 // The first non-repeating character is "b" and is found at index 1
 */

#include <iostream>
#include <unordered_map>

using namespace std;

int firstNonRepeatingCharacter(string string) {
    // Write your code here.
    // O(2n) --> O(n) time
    // O(26) --> O(1) space
    unordered_map<char, int> characterFrequencies;
    for (char &character : string) {
        if (characterFrequencies.find(character) == characterFrequencies.end()) {
            characterFrequencies[character] = 0;
        }
        characterFrequencies[character]++;
    }
    for (int idx = 0; idx < string.length(); idx++) {
        char character = string[idx];
        if (characterFrequencies[character] == 1) {
            return idx;
        }
    }

    return -1;
}

int main () { 
    int result = firstNonRepeatingCharacter("abcdcaf");

    cout << result << endl;
}