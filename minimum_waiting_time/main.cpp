/**
 * Sample Input
 * queries = [3, 2, 1, 2, 6]    
 * 
 * Sample Output
 * [1, 2, 2, 3, 6]
 * 
 * 17
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minimumWaitingTime(vector<int> queries) {
  // Write your code here.
  // O(nlog n [sort] + n [for]) => O(nlog n) time
  // O(1) space
  sort(queries.begin(), queries.end());

  int waitingDuration = 0;
  for (int i = 0; i < queries.size(); i++) {
      int duration = queries[i];
      int queriesLeft = queries.size() - (i + 1);
      waitingDuration += duration * queriesLeft;
  }

  return waitingDuration;
}

int main () {
    int result = minimumWaitingTime({3, 2, 1, 2, 6});

    cout << result << endl;
}
