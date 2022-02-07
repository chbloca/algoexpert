/**
 * Sample Input
 * string = [1, 2, 3, 4, 5]
 * 
 * Sample Output
 * [2, 1, 4, 5, 3]
 */

#include <iostream>
#include <vector>

// extras: https://cs.stackexchange.com/questions/133660/randomize-list-with-guaranteed-index-change

using namespace std;

int generate_unused_random(vector<int> &array, int idx, vector<int> &idx_array) {
    // create random number between 0 and size-1 except for i-th
    srand(time(0));
    int random_value;
    while (idx_array.size() < array.size()) {
        random_value = rand() % array.size();
        bool isUsed = false;

        for (int &element : idx_array) {
            if (element == random_value)
                isUsed = true;
        }

        if (random_value != idx && !isUsed) {
            cout << "random value: " << random_value << " at index " << idx << endl;
            return random_value;
        }
    } 
}

vector<int> randomizer(vector<int> array) {
    // Write your code here.
    // O(n^3) time
    // O(n) space
    
    vector<int> usedIndexes;
    bool indexed = false;

    for (int i = 0; i < array.size() / 2 + 1; i++) {
        cout << "array size: " << array.size() / 2 << endl;

        int random_value = generate_unused_random(array, i, usedIndexes);

        swap(array[i], array[random_value]);
        usedIndexes.push_back(i);
        usedIndexes.push_back(random_value);
    }
    return array;
}


int main () {
    vector<int> input {0, 1, 2, 3, 4, 5};
    vector<int> result = randomizer(input);

    bool dearranged = true;
    int idx;

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
        if (result[i] == input[i]) {
            dearranged = false;
            idx = i;
        }
    }
    if (dearranged) {
        cout << "Dearranged done properly" << endl;
    } else {
        cout << "Dearranged NOT done properly at index " << idx << endl;
    }
}
