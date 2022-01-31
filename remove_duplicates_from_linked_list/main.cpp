/**
 * Sample Input
 * linkedList =  = 1 -> 1 -> 3 -> 4 -> 4 -> 4 -> 5 -> 6 -> 6 // the head node with value 1
 * 
 * Sample Output
 * 1 -> 3 -> 4 -> 5 -> 6 // the head with value 1
 */

#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

LinkedList *addMany(LinkedList *linkedList, vector<int> values);
vector<int> getNodesInArray(LinkedList *linkedList);

// This is an input struct. Do not edit.
class LinkedList {
public:
    int value;
    LinkedList *next = nullptr;

    LinkedList(int value) { this->value = value; }

    
};

LinkedList *removeDuplicatesFromLinkedList(LinkedList *linkedList) {
  // Write your code here.
  return nullptr;
}

int main () {
    auto input = addMany(new LinkedList(1), vector<int>{1, 3, 4, 4, 4, 5, 6, 6});
    auto expected = addMany(new LinkedList(1), vector<int>{3, 4, 5, 6});
    auto result = removeDuplicatesFromLinkedList(input);

    assert(getNodesInArray(result) == getNodesInArray(expected));
}

LinkedList *addMany(LinkedList *linkedList, vector<int> values) {
        LinkedList *current = linkedList;
        while (current->next != nullptr) {
            current = current->next;
        }
        for (auto value : values) {
            current->next = new LinkedList(value);
            current = current->next;
        }
        return linkedList;
    }

vector<int> getNodesInArray(LinkedList *linkedList) {
    vector<int> nodes;
    LinkedList *current = linkedList;
    while (current != nullptr) {
        nodes.push_back(current->value);
        current = current->next;
    }
    return nodes;
}