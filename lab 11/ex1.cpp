#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Definition of a tree node
class TNode {
public:
    char data;
    TNode* left;
    TNode* right;

    TNode(char val) {
         data = val; 
         left = nullptr; 
         right = nullptr;
         }
};

// Function to construct an expression tree from a postfix expression
TNode* constructTree(string postfix) {
    stack<TNode*> s;

    for (char c : postfix) {
        // Create a new node
        TNode* curr = new TNode(c);

        // If the symbol is an operand, push it onto the stack
        if (isalnum(c)) {
            s.push(curr);
        } 
        // If the symbol is an operator, pop two nodes from the stack, attach them as children
        else {
            TNode* t2 = s.top(); s.pop();
            TNode* t1 = s.top(); s.pop();

            curr->left = t1;
            curr->right = t2;

            // Push the current node back onto the stack
            s.push(curr);
        }
    }

    // The remaining node on the stack is the root of the tree
    return s.top();
}

// Function to perform postorder traversal
void postorder(TNode* root) {
    if (!root) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data;
}

int main() {
    // Postfix expression
    string postfix = "ab+ef*g*-";

    // Construct the expression tree
    TNode* root = constructTree(postfix);

    // Perform postorder traversal
    cout << "Postorder traversal of the expression tree: ";
    postorder(root);
    cout << endl;

    return 0;
}
