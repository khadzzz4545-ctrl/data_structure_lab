
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string folderName;
    Node* left;
    Node* right;

    Node(string name) {
        folderName = name;
        left = nullptr;
        right = nullptr;
    }
};

// In-order: Left, Root, Right
void inOrder(Node* root) {
    if (root == nullptr)
        return;

    inOrder(root->left);
    cout << root->folderName << " ";
    inOrder(root->right);
}

// Pre-order: Root, Left, Right
void preOrder(Node* root) {
    if (root == nullptr)
        return;

    cout << root->folderName << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// Post-order: Left, Right, Root
void postOrder(Node* root) {
    if (root == nullptr)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->folderName << " ";
}

int main() {
    Node* root = new Node("C:");

    root->left = new Node("Program Files");
    root->right = new Node("Users");

    root->left->left = new Node("Microsoft Office");
    root->left->right = new Node("Games");

    root->right->left = new Node("Khadija");
    root->right->right = new Node("Downloads");

    cout << "COMPUTER FILE EXPLORER\n\n";

    cout << "In-order (Left, Root, Right): ";
    inOrder(root);

    cout << "\nPre-order (Root, Left, Right): ";
    preOrder(root);

    cout << "\nPost-order (Left, Right, Root): ";
    postOrder(root);

    cout << endl;

    return 0;
}
