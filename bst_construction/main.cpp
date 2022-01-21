/**
 * Each BST node has an integer value, a left child node, and a right child node.
 * A node is valid as long as:
 * - it is greater than or equal to the values of every node to its left
 * - it is less than to the values of every node to its right
 * 
 * Sample Input
 * Assume the following BST has already been created:
 *           10
 *        /     \
 *       5      15
 *     /   \   /   \
 *    2     5 13   22
 *  /           \
 * 1            14
 * 
 * All operations bellow are performed sequentially
 * insert (12):   10
 *             /     \
 *            5      15
 *          /   \   /   \
 *         2     5 13   22
 *       /        /  \
 *      1        12  14
 * 
 * remove (10):   12
 *             /     \
 *            5      15
 *          /   \   /   \
 *         2     5 13   22
 *       /           \
 *      1            14
 * 
 * contains(15): true
 */

#include <iostream>
#include <assert.h>

using namespace std;

// Do not edit the class below except for
// the insert, contains, and remove methods.
// Feel free to add new properties and methods
// to the class.
class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val) {
    value = val;
    left = nullptr;
    right = nullptr;
  }

  BST &insert(int val) {
    // Write your code here.
    // Do not edit the return statement of this method.
    return *this;
  }

  bool contains(int val) {
    // Write your code here.
    return false;
  }

  BST &remove(int val) {
    // Write your code here.
    // Do not edit the return statement of this method.
    return *this;
  }
};

int main () {
    BST *root = new BST(10);
    root->left = new BST(5);
    root->left->left = new BST(2);
    root->left->left->left = new BST(1);
    root->left->right = new BST(5);
    root->right = new BST(15);
    root->right->left = new BST(13);
    root->right->left->right = new BST(14);
    root->right->right = new BST(22);

    root->insert(12);
    assert(root->right->left->left->value == 12);

    root->remove(10);
    assert(root->contains(10) == false);
    assert(root->value == 12);

    assert(root->contains(15));
}