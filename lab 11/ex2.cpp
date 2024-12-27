#include <iostream>
using namespace std;

// Definition of a tree node
class TNode {
public:
    int data;
    TNode* left;
    TNode* right;

    TNode(int val){
        data = val;
        left = nullptr;
        right = nullptr; 
        }
};

// Function to count leaf nodes
int count_leaf(TNode* root) {
    if (!root)
        return 0;
    if (!root->left && !root->right) // Leaf node condition
        return 1;
    return count_leaf(root->left) + count_leaf(root->right);
}

// Function to count non-leaf nodes
int count_nonleaf(TNode* root) {
    if (!root || (!root->left && !root->right)) // Ignore null and leaf nodes
        return 0;
    return 1 + count_nonleaf(root->left) + count_nonleaf(root->right);
}

// Function to check if a queried node is a leaf
bool isleaf(TNode* root, int value) {
    if (!root)
        return false;

    // Check if the current node matches the value and is a leaf
    if (root->data == value && !root->left && !root->right)
        return true;

    // Recursively search in left and right subtrees
    return isleaf(root->left, value) || isleaf(root->right, value);
}

// Function to create the tree (as shown in the image)
TNode* createTree() {
    TNode* root = new TNode(14);
    root->left = new TNode(4);
    root->right = new TNode(15);

    root->left->left = new TNode(3);
    root->left->right = new TNode(9);
    root->left->right->left = new TNode(7);
    root->left->right->left->left = new TNode(4);
    root->left->right->left->right = new TNode(5);

    root->right->left = new TNode(14);
    root->right->right = new TNode(18);
    root->right->right->left = new TNode(16);
    root->right->right->left->left = new TNode(17);
    root->right->right->right = new TNode(20);

    return root;
}

// Main function
int main() {
    // Create the tree
    TNode* root = createTree();

    // Count and display the number of leaf nodes
    cout << "Total leaf nodes: " << count_leaf(root) << endl;

    // Count and display the number of non-leaf nodes
    cout << "Total non-leaf nodes: " << count_nonleaf(root) << endl;

    // Check if a queried node is a leaf
    int query = 5;
    cout << "Is " << query << " a leaf node? " << (isleaf(root, query) ? "Yes" : "No") << endl;

    return 0;
}
