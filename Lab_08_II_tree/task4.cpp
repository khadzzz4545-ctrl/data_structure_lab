
#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int token;
    Node* left;
    Node* right;
    int height;

    Node(int value) {
        token = value;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

int getHeight(Node* node) {
    if (node == nullptr)
        return 0;

    return node->height;
}

int getBalanceFactor(Node* node) {
    if (node == nullptr)
        return 0;

    return getHeight(node->left) - getHeight(node->right);
}

// Right Rotation
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* middleSubtree = x->right;

    x->right = y;
    y->left = middleSubtree;

    y->height = 1 + max(getHeight(y->left),
                        getHeight(y->right));

    x->height = 1 + max(getHeight(x->left),
                        getHeight(x->right));

    return x;
}

// Left Rotation
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* middleSubtree = y->left;

    y->left = x;
    x->right = middleSubtree;

    x->height = 1 + max(getHeight(x->left),
                        getHeight(x->right));

    y->height = 1 + max(getHeight(y->left),
                        getHeight(y->right));

    return y;
}

Node* insert(Node* root, int value) {

    // Normal BST Insertion
    if (root == nullptr)
        return new Node(value);

    if (value < root->token)
        root->left = insert(root->left, value);

    else if (value > root->token)
        root->right = insert(root->right, value);

    else
        return root;

    // Update Height
    root->height = 1 + max(getHeight(root->left),
                           getHeight(root->right));

    // Calculate Balance Factor
    int balance = getBalanceFactor(root);

    // LL Case
    if (balance > 1 && value < root->left->token)
        return rightRotate(root);

    // RR Case
    if (balance < -1 && value > root->right->token)
        return leftRotate(root);

    // LR Case
    if (balance > 1 && value > root->left->token) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL Case
    if (balance < -1 && value < root->right->token) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// In-order Traversal
void inOrder(Node* root) {
    if (root == nullptr)
        return;

    inOrder(root->left);
    cout << root->token << " ";
    inOrder(root->right);
}

// Display Tree
void displayTree(Node* root, int space = 0) {
    if (root == nullptr)
        return;

    space += 5;

    displayTree(root->right, space);

    cout << endl;

    for (int i = 5; i < space; i++)
        cout << " ";

    cout << root->token
         << " (Height=" << root->height
         << ", BF=" << getBalanceFactor(root) << ")"
         << endl;

    displayTree(root->left, space);
}

int main() {
    Node* root = nullptr;

    int tokens[] = {15, 25, 35, 45, 55, 65, 75};

    int size = sizeof(tokens) / sizeof(tokens[0]);

    cout << "HOSPITAL APPOINTMENT SYSTEM - AVL TREE\n\n";

    for (int i = 0; i < size; i++) {
        root = insert(root, tokens[i]);
        cout << "Inserted token: " << tokens[i] << endl;
    }

    cout << "\nIn-order Traversal: ";
    inOrder(root);

    cout << "\n\nFinal Balanced AVL Tree:\n";
    displayTree(root);

    cout << "\nBalance factor must be -1, 0, or 1.";

    return 0;
}
