/**
 * Sample Input
 * redShirtSpeeds = [5, 5, 3, 9, 2]    
 * blueShirtSpeeds = [3, 6, 7, 2, 1]
 * fastest = true    
 * 
 * Sample Output
 * 32
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int tandemBicycle(vector<int> redShirtSpeeds, vector<int> blueShirtSpeeds,
                  bool fastest) {
    // Write your code here.
    // O(nlog n) time where n is the number of tandem bycicles
    // O(1) space
    sort(redShirtSpeeds.begin(), redShirtSpeeds.end());
    sort(blueShirtSpeeds.begin(), blueShirtSpeeds.end());

    int totalSpeed = 0;
    for (int idx = 0; idx < redShirtSpeeds.size(); idx++) {
        if (fastest) {
            totalSpeed += max(redShirtSpeeds[idx], blueShirtSpeeds[blueShirtSpeeds.size() - 1 - idx]) ;
        } else {
            totalSpeed += max(redShirtSpeeds[idx], blueShirtSpeeds[idx]);
        }
    }

    return totalSpeed;
}

int main () {
    int result = tandemBicycle({5, 5, 3, 9, 2}, {3, 6, 7, 2, 1}, false);

    cout << result << endl;
}