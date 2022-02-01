/**
 * Sample Input
 * n = 2
 * 
 * Sample Output
 * 1 // 0, 1
 * 5 // 0, 1, 1, 2, 3, 5
 */

#include <iostream>

using namespace std;

int getNthFibNaive(int n) {
  // Write your code here.
  // O(2^n) time as it diverges exponentially fib(6) -> [fib(5) -> [fib(4) -> ... & fib(3) ->...] & fib(4) -> ... ]
  // O(n) as the recursive function stores on the call stack
  //  all the upstream functions waiting for the downstream ones to end
  if (n == 1) {
      return 0;
  } else if (n == 2) {
      return 1;
  } else {
    return getNthFibNaive(n - 1) + getNthFibNaive(n - 2);
  }
}

int getNthFib(int n) {
  // Write your code here.
  // O(n) time
  // O(1) space
  int lastTwo[] = {0, 1};
  int counter = 3;
  while (counter <= n) {
      int nextFib = lastTwo[0] + lastTwo[1];
      lastTwo[0] = lastTwo[1];
      lastTwo[1] = nextFib;
      counter++;
  }
  return n > 1 ? lastTwo[1] : lastTwo[0];
}

int main () {
    int output_naive = getNthFibNaive(1);
    int output2_naive = getNthFibNaive(35);
    int output = getNthFib(1);
    int output2 = getNthFib(35);

    cout << output_naive << endl;
    cout << output2_naive << endl;
    cout << output << endl;
    cout << output2 << endl;
}