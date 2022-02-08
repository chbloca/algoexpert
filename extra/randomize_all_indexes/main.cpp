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

vector<int> randomizer(vector<int> array) {
    // O(n^2) time
    // O(n) space
    
    srand(time(0));
    vector<int> temp = array;

    if (array.size() == 1) return array;

    for (int i = 0; i < array.size(); i++) {
        int newPosition = i == 0 ? rand() % array.size() : array.size() - 1;

        while (newPosition == i || temp.at(newPosition) == 999) { /// 999 is a flag, it would be nice to use null value instead
            newPosition = rand() % array.size();
        }

        array[i] = temp[newPosition];
        temp[newPosition] = 999;
    }
    return array;
}


int main () {
    vector<int> input {0, 1, 2, 5};
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
