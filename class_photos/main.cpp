/**
 * Sample Input
 * redShirtHeights = [5, 8, 1, 3, 4]    
 * blueShirtHeights = [6, 9, 2, 4, 5]    
 * 
 * Sample Output
 * true
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool classPhotos(vector<int> redShirtHeights, vector<int> blueShirtHeights) {
  // Write your code here.
  // O(nlog n) time
  // O(1) space
  sort(redShirtHeights.rbegin(), redShirtHeights.rend()); // in the reverse order
  sort(blueShirtHeights.rbegin(), blueShirtHeights.rend());

  string shirtColorInFirstRow = redShirtHeights[0] < blueShirtHeights[0] ? "RED" : "BLUE";

  for (int i = 0; i < redShirtHeights.size(); i++) {
      int redShirtHeight = redShirtHeights[i];
      int blueShirtHeight = blueShirtHeights[i];

      if (shirtColorInFirstRow == "RED") {
          if (redShirtHeight >= blueShirtHeight)
            return false;
      } else {
          if (blueShirtHeight >= redShirtHeight)
            return false;
      }
  }
  return true;
}

int main () {
    int result = classPhotos({5, 8, 1, 3, 4}, {6, 9, 2, 4, 5});

    cout << result << endl;
}