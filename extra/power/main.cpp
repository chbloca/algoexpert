// power() returns base raised to the power exp, ignoring over- and overflow

#include <iostream>

using namespace std;

int power(int base, int exp) {
    // Write your code here
    // O(n) time
    // O(1) space
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }

    return result;
}

int main() {
    int result = power(2, 4);

    cout << result << endl;
}