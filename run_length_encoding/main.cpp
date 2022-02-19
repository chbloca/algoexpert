/**
 * Sample Input
 * string = "AAAAAAAAAAAAABBCCCCDD"
 * 
 * Sample Output
 * "9A4A2B4C2D"
 */

#include <iostream>
#include <vector>

using namespace std;

string runLengthEncoding(string str) {
  // Write your code here.
  // O(n) time
  // O(n) space
  vector<char> encodedStringCharacters;
  int currentRunLength = 1;

  for (int i = 1; i < str.length(); i++) {
    char currentCharacter = str[i];
    char previousCharacter = str[i - 1];

    if (currentCharacter != previousCharacter || currentRunLength == 9) {
       encodedStringCharacters.push_back(to_string(currentRunLength)[0]);
       encodedStringCharacters.push_back(previousCharacter);

       currentRunLength = 0;
    }

    currentRunLength++;
  }

  encodedStringCharacters.push_back(to_string(currentRunLength)[0]);
  encodedStringCharacters.push_back(str[str.length() - 1]);

  string encodedString(encodedStringCharacters.begin(), encodedStringCharacters.end());

  return encodedString;
}

int main () { 
    string result = runLengthEncoding("AAAAAAAAAAAAABBCCCCDD");

    cout << result << endl;
}