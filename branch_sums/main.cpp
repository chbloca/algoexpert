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

void calculateBranchSums(BinaryTree *node, int runningSum, vector<int> &sums) {
    if (node == nullptr)
        return;

    int newRunningSum = runningSum + node->value;

    if (node->left == nullptr && node->right == nullptr) {
        sums.push_back(newRunningSum);
        return;
    }

    calculateBranchSums(node->left, newRunningSum, sums);
    calculateBranchSums(node->right, newRunningSum, sums);
}

vector<int> branchSums(BinaryTree *root) {
    // Write your code here.
    // O(n) time | O(k) space
    // n is the number of nodes in the tree
    // k is the number of leafs
    // k < n

    vector<int> sums;
    calculateBranchSums(root, 0, sums);
    return sums;
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