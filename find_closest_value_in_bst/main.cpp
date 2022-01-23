/**
 * Sample Input
 * tree =    10
 *        /     \
 *       5      15
 *     /   \   /   \
 *    2     5 13   22
 *  /           \
 * 1            14
 * target = 12
 * 
 * Sample Output
 * result = 13
 */

#include <iostream>
#include <cmath>

using namespace std;

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
};

int findClosestValueInBstHelper(BST *tree, int target, int closestValue) {
  BST *currentNode = tree;
  while (currentNode != nullptr) {
    // We must stop the recursion once we reach the bottom of the tree (a leaf)
    if (abs(target - closestValue) > abs(target - currentNode->value))
      closestValue = currentNode->value;
    
    if (target < currentNode->value) {
      currentNode = currentNode->left;
    } else if (target > currentNode->value) {
      currentNode = currentNode->right;
    } else {
      break;
    }
  }
  return closestValue;
}

int findClosestValueInBst(BST *tree, int target) {
    // Write your code here.
    // Average case (symmetrical tree): O(log n) time | O(1) space
    // Worst case (single rooted tree): O(n) time | O(1) space
    // As we want to keep track of the closes value variable, we will use a helper method
    return findClosestValueInBstHelper(tree, target, tree->value);
}

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

    int output = findClosestValueInBst(root, 12);

    cout << output << endl;
}