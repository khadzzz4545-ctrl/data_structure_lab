
#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Node {
public:
    string category;
    Node* left;
    Node* right;

    Node(string categoryName) {
        category = categoryName;
        left = nullptr;
        right = nullptr;
    }
};

void BFS(Node* root) {
    if (root == nullptr) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    cout << "BFS Traversal: ";

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        cout << current->category << " ";

        if (current->left != nullptr) {
            q.push(current->left);
        }

        if (current->right != nullptr) {
            q.push(current->right);
        }
    }

    cout << endl;
}

int main() {
    Node* root = new Node("Electronics");

    root->left = new Node("Clothing");
    root->right = new Node("Mobiles");

    root->left->left = new Node("Men");
    root->left->right = new Node("Women");

    root->right->left = new Node("Laptops");
    root->right->right = new Node("Accessories");

    cout << "ONLINE SHOPPING CATEGORIES\n";

    BFS(root);

    return 0;
}
