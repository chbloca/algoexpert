/**
 * Sample Input
 * characters = "Bste!hetsi ogEAxpelrt x "
 * document = "AlgoExpert is the Best!"
 * 
 * Sample Output
 * true
 */

#include <iostream>
#include <unordered_map>

using namespace std;

bool generateDocument(string characters, string document) {
  // Write your code here.
  // O(n + m) time
  // O(c) space
  unordered_map<char, int> characterCounts;

  for (char &character : characters) {
      if (characterCounts.find(character) == characterCounts.end()) {
          characterCounts[character] = 0;
      }
      characterCounts[character]++;
  }

  for (char &character : document) {
      if (characterCounts.find(character) == characterCounts.end() || characterCounts[character] == 0) {
          return false;
      }
      characterCounts[character]--;
  }
  return true;
}

int main () { 
    bool result = generateDocument("Bste!hetsi ogEAxpelrt x ", "AlgoExpert is the Best!");

    cout << result << endl;
}