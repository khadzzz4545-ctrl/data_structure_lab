#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string memberName) {
        name = memberName;
        left = nullptr;
        right = nullptr;
    }
};

void displayHierarchy(Node* root) {
    if (root == nullptr) {
        return;
    }

    cout << "Member: " << root->name << endl;

    cout << "Left child: ";
    if (root->left != nullptr)
        cout << root->left->name;
    else
        cout << "None";

    cout << endl << "Right child: ";
    if (root->right != nullptr)
        cout << root->right->name;
    else
        cout << "None";

    cout << "\n\n";

    displayHierarchy(root->left);
    displayHierarchy(root->right);
}

int main() {
    Node* root = new Node("HOD");

    root->left = new Node("Coordinator - AI");
    root->right = new Node("Coordinator - Data Science");

    root->left->left = new Node("Faculty Member - AI 1");
    root->left->right = new Node("Faculty Member - AI 2");

    root->right->left = new Node("Faculty Member - DS 1");
    root->right->right = new Node("Faculty Member - DS 2");

    cout << "UNIVERSITY DEPARTMENT HIERARCHY\n\n";

    displayHierarchy(root);

    return 0;
}
