/**
 * Sample Input
 * tree =    1
 *        /     \
 *       2       3
 *     /   \   /   \
 *    4     5 6     7
 *  /  \   /
 * 8    9 10      
 * 
 * Sample Output
 * 16
 * The depth of the node with value 2 is 1.
 * The depth of the node with value 3 is 1.
 * The depth of the node with value 4 is 2.
 * The depth of the node with value 5 is 2.
 * ...
 * Summing all of these depths yields 16
 */

#include <iostream>

using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }
};

int nodeDepths(BinaryTree *root) {
  // Write your code here.
  return -1;
}

int main () {
    BinaryTree *root = new BinaryTree(1);
    root->left = new BinaryTree(2);
    root->left->left = new BinaryTree(4);
    root->left->left->left = new BinaryTree(8);
    root->left->left->right = new BinaryTree(9);
    root->left->right = new BinaryTree(5);
    root->left->right->left = new BinaryTree(10);
    root->right = new BinaryTree(3);
    root->right->left = new BinaryTree(6);
    root->right->right = new BinaryTree(7);

    int result = nodeDepths(root);

    cout << result << endl;
}