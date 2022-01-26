/**
 * Sample Input
 * graph = A
 *     /  |  \
 *    B   C   D
 *   / \     / \
 *  E   F   G   H
 *     / \   \
 *    I   J   K
 * 
 * Sample Output
 * ["A", "B", "E", "F", "I", "J", "C", "D", "G", "K", "H"]
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Do not edit the class below except
// for the depthFirstSearch method.
// Feel free to add new properties
// and methods to the class.
class Node {
public:
  string name;
  vector<Node *> children;

  Node(string str) { name = str; }

  // Version 1
  // Cons: You cannot see the value of array during the debugging
//   vector<string> depthFirstSearch(vector<string> *array) {
//     // Write your code here.
//     // O(v + e) time [v: vertices = nodes, e: edges = relationships]
//     // O(v) space
//     array->push_back(this->name);
//     for (int i = 0; i < this->children.size(); i++) {
//         children[i]->depthFirstSearch(array);
//     }
//     return *array;
//   }

  // Version 2
  vector<string> depthFirstSearch(vector<string> &array) {
    // Write your code here.
    // O(v + e) time [v: vertices = nodes, e: edges = relationships]
    // O(v) space
    array.push_back(this->name);
    for (int i = 0; i < this->children.size(); i++) {
        children[i]->depthFirstSearch(array);
    }
    return array;
  }

  Node *addChild(string name) {
    Node *child = new Node(name);
    children.push_back(child);
    return this;
  }
};

int main () {
    Node graph("A");
    graph.addChild("B")->addChild("C")->addChild("D");
    graph.children[0]->addChild("E")->addChild("F");
    graph.children[2]->addChild("G")->addChild("H");
    graph.children[0]->children[1]->addChild("I")->addChild("J");
    graph.children[2]->children[0]->addChild("K");

    vector<string> inputArray {};

    // Version 1
    // vector<string> result = graph.depthFirstSearch(&inputArray);
    // Version 2
    vector<string> result = graph.depthFirstSearch(inputArray);

    for (auto &i : result) {
        cout << i << endl;
    }
}