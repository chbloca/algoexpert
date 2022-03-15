/**
 * Sample Input
 * array = [5, 1, 4, 2]
 * 
 * Sample Output
 * [8, 40, 10, 20]
 * 8 is equal to 1 x 4 x 2
 * 40 is equal to 5 x 4 x 2
 * 10 is equal to 5 x 1 x 2
 * 20 is equal to 5 x 1 x 4
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> arrayOfProductsNaive(vector<int> array) {
    // Write your code here.
    // O(n^2) time
    // O(n) space 
    vector<int> products(array.size());

    for (int i = 0; i < array.size(); i++) {
        int currentProd = 1;
        for (int j = 0; j < array.size(); j++) {
            if (i != j) {
                currentProd *= array[j];
            }
        }
        products[i] = currentProd;
    }
    return products;
}

vector<int> arrayOfProducts(vector<int> array) {
    // Write your code here.
    // O(n) time
    // O(n) space 
    vector<int> products(array.size());
    vector<int> leftProducts(array.size());
    vector<int> rightProducts(array.size());

    int leftCurrentProd = 1;
    for (int i = 0; i < array.size(); i++) {
        leftProducts[i] = leftCurrentProd;
        leftCurrentProd *= array[i];
    }

    int rightCurrentProd = 1;
    for (int i = array.size() - 1; i >= 0; i--) {
        rightProducts[i] = rightCurrentProd;
        rightCurrentProd *= array[i];        
    }

    for (int i = 0; i < array.size(); i++) {
        products[i] = leftProducts[i] * rightProducts[i];
    }

    return products;
}


int main () {
    vector<int> result = arrayOfProductsNaive({5, 1, 4, 2});
    vector<int> result = arrayOfProducts({5, 1, 4, 2});
}