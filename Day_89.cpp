#include <iostream>
#include <vector>

using namespace std;

// Definition for a Node in the linked list
struct Node {
    int data;
    Node* right;
    Node* down;

    Node(int x) {
        data = x;
        right = NULL;
        down = NULL;
    }
};

class Solution {
public:
    Node* fun(vector<vector<int>>& mat, int i, int j, int n, int m) {
        // Base case: if we exceed the bounds of the matrix
        if (i >= n || j >= m) {
            return NULL;
        }
        
        // Create a new node for the current element
        Node* temp = new Node(mat[i][j]);
        
        // Recursively construct the right and down pointers
        temp->right = fun(mat, i, j + 1, n, m); // Right pointer (same row)
        temp->down = fun(mat, i + 1, j, n, m);  // Down pointer (next row)
        
        return temp;
    }

    Node* constructLinkedMatrix(vector<vector<int>>& mat) {
        // If the matrix is empty, return NULL
        if (mat.empty()) {
            return NULL;
        }
        
        int n = mat.size();        // Number of rows
        int m = mat[0].size();     // Number of columns
        
        // Start constructing the linked matrix from the top-left corner
        return fun(mat, 0, 0, n, m); 
    }
};

// Helper function to print the linked matrix
void printLinkedMatrix(Node* head) {
    while (head) {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->right;
        }
        cout << endl;
        head = head->down;
    }
}

int main() {
    // Example usage
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Solution sol;
    Node* head = sol.constructLinkedMatrix(mat);
    
    cout << "Linked Matrix:" << endl;
    printLinkedMatrix(head);

    return 0;
}
