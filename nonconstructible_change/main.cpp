/**
 * Sample Input
 * coins = [5, 7, 1, 1, 2, 3, 22]
 * 
 * Sample Output
 * results = 20
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int nonConstructibleChange(vector<int> coins) {
    // Write your code here.
    // O(nlogn [sort] + n [loop]) --> O(nlogn) time
    // O(1) [variable is manipulated and no auxiliar variable is created] space
    sort(coins.begin(), coins.end());

    int currentChangeCreated = 0;
    for (auto coin : coins) {
        if (coin > currentChangeCreated + 1)
            return currentChangeCreated + 1;

        currentChangeCreated += coin; 
    }
    return currentChangeCreated + 1; // this is for the case no coins are given
}

int main () {
    int output = nonConstructibleChange({5, 7, 1, 1, 2, 3, 22});
    int output2 = nonConstructibleChange({});

    cout << output << endl;
    cout << output2 << endl;
}