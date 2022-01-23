/**
 * Sample Input
 * tree =    1
 *        /     \
 *       2       3
 *     /   \   /   \
 *    4     5 6     7
 *  /  \   /
 * 8    9 10      
 * target = 12
 * 
 * Sample Output
 * [15, 16, 18, 10, 11]
 * 15 == 1 + 2 + 4 + 8
 * 16 == 1 + 2 + 4 + 9
 * 18 == 1 + 2 + 5 + 10
 * 10 == 1 + 3 + 6
 * 11 == 1 + 3 + 7 
 */

#include <iostream>
#include <vector>

using namespace std;

// This is the class of the input root. Do not edit it.
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

vector<int> branchSums(BinaryTree *root) {
  // Write your code here.
  return {};
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

    vector<int> result = branchSums(root);

    for (auto &element : result) {
        cout << element << endl;
    }
}