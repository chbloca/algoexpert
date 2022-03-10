/**
 * Sample Input
 * array = [1, 2, 3, 3, 4, 0, 10, 6, 5, -1, -3, 2, 3]
 * 
 * Sample Output
 * 6 // 0, 10, 6, 5, -1, -3
 */

#include <iostream>
#include <vector>

using namespace std;

int longestPeak(vector<int> array) {
    // Write your code here.
    // O(n) time
    // O(1) space

    int longestPeakLength = 0;

    int i = 1;

    while (i < array.size() - 1) {
        bool isPeak = array[i - 1] < array[i] && array[i] > array[i + 1];
        if (!isPeak) {
            i++;
            continue;
        }

        int leftIdx = i - 2;
        while (leftIdx >= 0 && array[leftIdx] < array[leftIdx + 1])
             leftIdx--;

        int rightIdx = i + 2;
        while (rightIdx < array.size() && array[rightIdx] < array[rightIdx - 1])
            rightIdx++;

        int currentPeakLength = rightIdx - leftIdx - 1;
        longestPeakLength = max(longestPeakLength, currentPeakLength);
        i = rightIdx; 
    }

    return longestPeakLength;
}

int main() {
    int result = longestPeak({{1, 2, 3, 3, 4, 0, 10, 6, 5, -1, -3, 2, 3}});
    cout << result << endl;
}