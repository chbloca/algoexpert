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

  vector<string> depthFirstSearch(vector<string> *array) {
    // Write your code here.
    return {};
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

    vector<string> result = graph.depthFirstSearch(&inputArray);

    for (auto &i : result) {
        cout << i << endl;
    }
}