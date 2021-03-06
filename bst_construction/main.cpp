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
        // Average case (symmetrical tree): O(log n) time | O(1) space
        // Worst case (single rooted tree): O(n) time | O(1) space
        BST *currentNode = this;
        while (true) {
            if (val < currentNode->value) {
                if (currentNode->left == nullptr) {
                    BST *newNode = new BST(val);
                    currentNode->left = newNode;
                    break;
                } else {
                    currentNode = currentNode->left;
                }
            } else {
                if (currentNode->right == nullptr) {
                    BST *newNode = new BST(val);
                    currentNode->right = newNode;
                    break;
                } else {
                    currentNode = currentNode->right;
                }
            }
        }

        return *this; // this is to enable chained calls of the method
    }

    // Average case (symmetrical tree): O(log n) time | O(1) space
    // Worst case (single rooted tree): O(n) time | O(1) space
    bool contains(int val) {
        // Write your code here.
        BST *currentNode = this;
        while (currentNode != nullptr) {
            if (val < currentNode->value) {
                currentNode = currentNode->left;
            } else if (val > currentNode->value) {
                currentNode = currentNode->right;
            } else {
                return true;
            }
        }
        
        return false;
    }

    int getMinValue() {
        BST *currentNode = this;
        while (currentNode->left != nullptr) {
            currentNode = currentNode->left;
        }
        return currentNode->value;
    }

    // Average case (symmetrical tree): O(log n) time | O(1) space
    // Worst case (single rooted tree): O(n) time | O(1) space
    BST &remove(int val, BST *parentNode = nullptr) {
        // Write your code here.
        // Do not edit the return statement of this method.
        BST *currentNode = this;
        while (currentNode != nullptr) {
            if (val < currentNode->value) {
                parentNode = currentNode;
                currentNode = currentNode->left;
            } else if (val > currentNode->value) {
                parentNode = currentNode;
                currentNode = currentNode->right;
            } else {
                if (currentNode->left != nullptr && currentNode->right != nullptr) {
                    // edge case node has two children
                    // we want to find the smallest value in the right subtree
                    currentNode->value = currentNode->right->getMinValue();
                    currentNode->right->remove(currentNode->value, currentNode);
                } else if (parentNode == nullptr) {
                    // edge case node is root
                    if (currentNode->left != nullptr) {
                        currentNode->value = currentNode->left->value;
                        currentNode->right = currentNode->left->right;
                        currentNode->left = currentNode->left->left;
                    } else if (currentNode->right != nullptr) {
                        currentNode->value = currentNode->right->value;
                        currentNode->left = currentNode->right->left;
                        currentNode->right = currentNode->right->right; 
                    } else {
                        currentNode == nullptr;
                    }
                } else if (parentNode->left == currentNode) {
                    //   5
                    //  /
                    // 3
                    //  \
                    //   4 or nullptr
                    //
                    //   5
                    //  /
                    // 4 or nullptr
                    //
                    //
                    parentNode->left = currentNode->left != nullptr ? currentNode->left : currentNode->right;
                } else if (parentNode->right == currentNode) {
                    parentNode->right = currentNode->left != nullptr ? currentNode->left : currentNode->right;
                }
                break;
            }
        }

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