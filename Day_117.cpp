#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Helper function to calculate sum of all root-to-leaf paths
void treePathsSumfun(Node* root, int &sum, int temp) {
    if (!root) return;

    // Update the current path number
    temp = temp * 10 + root->data;
    
    // If leaf node, add the current path number to sum
    if (root->left == NULL && root->right == NULL) {
        sum += temp;
        return;
    }
    
    // Recursively calculate the sum for left and right subtrees
    if (root->left)
        treePathsSumfun(root->left, sum, temp);
    if (root->right)
        treePathsSumfun(root->right, sum, temp);
}

// Function to initiate sum calculation from the root
int treePathsSum(Node* root) {
    int sum = 0;
    treePathsSumfun(root, sum, 0);
    return sum;
}

// Utility function to create a new node
Node* newNode(int data) {
    Node* node = new Node(data);
    return node;
}

int main() {
    // Example tree
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    
    cout << "Sum of all root-to-leaf paths: " << treePathsSum(root) << endl;
    return 0;
}
