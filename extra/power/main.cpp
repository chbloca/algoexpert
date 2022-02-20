// power() returns base raised to the power exp, ignoring over- and overflow
// https://www.geeksforgeeks.org/write-a-c-program-to-calculate-powxn/

#include <iostream>

using namespace std;

int powerNaive(int base, int exp) {
    // Write your code here
    // O(n) time
    // O(1) space
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }

    return result;
}

int power(int base, int exp) {
    // O(log n) time
    // O(1) space
    if (exp == 0)
        return 1;
    
    if (base == 0)
        return 0;
    
    return base * power(base, exp - 1);
}

int main() {
    int resultNaive = powerNaive(2, 4);
    int result = power(2, 4);

    cout << resultNaive << endl;
    cout << result << endl;
}