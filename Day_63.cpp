#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data =x;
        left = right=NULL;
    }

};

 // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        // code here
        if(node == NULL)
            return;
        
        //Invert  pointers    
        Node* left = node->left;
        node->left = node->right;
        node->right = left;
        
        //Do the same for both TREES
        mirror(node->left);
        mirror(node->right);
    }

int main(){
      // Create the root of the binary tree  
    struct Node* root = new Node(1);  
    // Create left and right child nodes  
    root->left = new Node(2);  
    root->right = new Node(3);  
    // Create a left child for the root's left node  
    root->left->left = new Node(4); 
    root->left->right = new Node(6); 
    mirror(root); 
}