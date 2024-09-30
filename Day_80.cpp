#include <iostream>
#include <vector>
using namespace std;

// Definition of the Node structure
struct Node {
    int data;
    Node *left, *right;

    // Constructor to initialize a node with a given value
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    // Function to perform in-order traversal of the tree and store the node values in a vector
    void inorder(Node *root, vector<int> &temp) {
        if (root == NULL) return;  // Base case: If node is null, return

        // Recursively visit the left subtree
        inorder(root->left, temp);
        // Store the current node's value
        temp.push_back(root->data);
        // Recursively visit the right subtree
        inorder(root->right, temp);
    }

    // Function to merge two sorted vectors into a single sorted vector
    vector<int> mergeSortedVectors(vector<int>& ar1, vector<int>& ar2) {
        vector<int> ans;
        int i = 0, j = 0;

        // Merge elements while both vectors have remaining elements
        while (i < ar1.size() && j < ar2.size()) {
            if (ar1[i] <= ar2[j]) {
                ans.push_back(ar1[i++]);  // Add the smaller element and move pointer
            } else {
                ans.push_back(ar2[j++]);  // Add the smaller element and move pointer
            }
        }

        // Add any remaining elements from the first vector
        while (i < ar1.size()) {
            ans.push_back(ar1[i++]);
        }

        // Add any remaining elements from the second vector
        while (j < ar2.size()) {
            ans.push_back(ar2[j++]);
        }

        return ans;
    }

    // Function to merge two BSTs and return the node values in sorted order
    vector<int> merge(Node *root1, Node *root2) {
        vector<int> first, second;

        // Perform in-order traversal of both trees and store the node values
        inorder(root1, first);
        inorder(root2, second);

        // Merge the two sorted vectors
        return mergeSortedVectors(first, second);
    }
};

// Helper function to insert a new node into a binary search tree
Node* insert(Node* root, int key) {
    if (root == NULL) return new Node(key);

    if (key < root->data) {
        root->left = insert(root->left, key);  // Insert in the left subtree
    } else if (key > root->data) {
        root->right = insert(root->right, key);  // Insert in the right subtree
    }

    return root;
}

// Helper function to print a vector
void printVector(const vector<int>& vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    // Create two binary search trees (BSTs)
    Node *root1 = NULL;
    root1 = insert(root1, 3);
    root1 = insert(root1, 1);
    root1 = insert(root1, 5);

    Node *root2 = NULL;
    root2 = insert(root2, 4);
    root2 = insert(root2, 2);
    root2 = insert(root2, 6);

    Solution obj;
    // Merge the two BSTs and get the node values in sorted order
    vector<int> mergedResult = obj.merge(root1, root2);

    // Print the merged result
    cout << "Merged tree values in sorted order: ";
    printVector(mergedResult);

    return 0;
}
