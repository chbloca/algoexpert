/**
 * Sample Input
 * array = [5, 1, 22, 25, 6, -1, 8, 10]
 * sequence = [1, 6, -1, 10]
 * 
 * Sample Output
 * true
 */

#include <iostream>
#include <vector>
using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
    // Write your code here.
    int arrIdx = 0;
    int seqIdx = 0;

    // O(n) time | O(1) space
    while (arrIdx < array.size() && seqIdx < sequence.size()) {
        if (sequence[seqIdx] == array[arrIdx]) {
            seqIdx++;
        }
        arrIdx++;
    }
    
    return seqIdx == sequence.size();
}

int main () {
    bool output = isValidSubsequence({5, 1, 22, 25, 6, -1, 8, 10}, {1, 6, -1, 10});

    cout << output << endl;
}