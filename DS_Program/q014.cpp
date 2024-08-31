#include <iostream>

using namespace std;

// Define a node structure for the BST
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Define a class for the Binary Search Tree
class BST {
private:
    Node* root;

    // Helper function to insert a node recursively
    Node* insertRecursively(Node* root, int value) {
        if (root == nullptr) {
            return new Node(value);
        }
        if (value < root->data) {
            root->left = insertRecursively(root->left, value);
        } else if (value > root->data) {
            root->right = insertRecursively(root->right, value);
        }
        return root;
    }

    // Helper function to perform inorder traversal recursively
    void inorderRecursively(Node* root) {
        if (root != nullptr) {
            inorderRecursively(root->left);
            cout << root->data << " ";
            inorderRecursively(root->right);
        }
    }

public:
    // Constructor
    BST() {
        root = nullptr;
    }

    // Function to insert a value into the BST
    void insert(int value) {
        root = insertRecursively(root, value);
    }

    // Function to perform inorder traversal of the BST
    void inorderTraversal() {
        cout << "Inorder traversal: ";
        inorderRecursively(root);
        cout << endl;
    }
};

int main() {
    BST bst;

    // Insert elements into the BST
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    // Perform inorder traversal
    bst.inorderTraversal();

    return 0;
}
