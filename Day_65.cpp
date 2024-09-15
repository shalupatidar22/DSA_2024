#include <iostream>
using namespace std;

// Definition for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Global pointers for previous node and head of the doubly linked list
Node* prev = NULL;
Node* head = NULL;

// Function to convert a binary tree to a doubly linked list
Node* bToDLL(Node* root) {
    // Base case: if the current node (root) is NULL, return NULL
    if (root == NULL) return NULL;
    
    // Recursive call to process the left subtree first (in-order traversal)
    bToDLL(root->left);
    
    // If 'prev' is NULL, this is the first node we encounter (leftmost node)
    if (prev == NULL) {
        head = root;  // Set this node as the head of the DLL
    } else {
        // Connect the current node (root) to the previous node (prev) in DLL fashion
        prev->right = root;  // The previous node's 'right' points to the current node
        root->left = prev;   // The current node's 'left' points to the previous node
    }
    
    // Move 'prev' to the current node (root) for the next iteration
    prev = root;
    
    // Recursive call to process the right subtree
    bToDLL(root->right);
    
    // Return the head of the doubly linked list
    return head;
}

// Helper function to print the doubly linked list
void printDLL(Node* head) {
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->right;
    }
    cout << endl;
}

// Helper function to create a new node
Node* newNode(int data) {
    return new Node(data);
}

int main() {
    /* Construct the following binary tree
              10
             /  \
            5    20
           / \     \
          1   8    30
    */
    
    Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(20);
    root->left->left = newNode(1);
    root->left->right = newNode(8);
    root->right->right = newNode(30);
    
    // Convert binary tree to doubly linked list
    Node* dllHead = bToDLL(root);
    
    // Print the doubly linked list
    cout << "Doubly Linked List: ";
    printDLL(dllHead);
    
    return 0;
}
