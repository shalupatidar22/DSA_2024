#include <bits/stdc++.h>
using namespace std;

// Structure of Node
struct Node {
    int data;
    struct Node* npx; // XOR of previous and next node

    Node(int x) {
        data = x;
        npx = NULL;
    }
};

// Utility function to get XOR of two Node pointers
struct Node* XOR(struct Node* a, struct Node* b) {
    return (struct Node*) ((uintptr_t)(a) ^ (uintptr_t)(b));
}

// Function to insert the data to the front of the XOR Linked List
struct Node* insert(struct Node* head, int data) {
    Node* newNode = new Node(data);

    // New node's npx will be XOR of NULL and current head
    newNode->npx = XOR(NULL, head);

    // If head is not NULL, we need to update the previous head's npx
    if (head != NULL) {
        // Update the head's npx, which is XOR of its previous node and the new node
        Node* next = XOR(NULL, head->npx);
        head->npx = XOR(newNode, next);
    }

    // Return the new head, which is the new node
    return newNode;
}

// Function to traverse the XOR Linked List and return the elements
vector<int> getList(struct Node* head) {
    vector<int> result;
    Node* curr = head;
    Node* prev = NULL;
    Node* next;

    while (curr != NULL) {
        // Add current node's data to the result
        result.push_back(curr->data);

        // Get the next node using XOR of curr's npx and prev
        next = XOR(prev, curr->npx);

        // Move prev and curr one step forward
        prev = curr;
        curr = next;
    }

    return result;
}

// Driver code
int main() {
    struct Node* head = NULL;

    // Inserting nodes
    head = insert(head, 10);
    head = insert(head, 20);
    head = insert(head, 30);
    head = insert(head, 40);

    // Get the list of elements in the XOR Linked List
    vector<int> elements = getList(head);

    // Print the elements
    for (int elem : elements) {
        cout << elem << " ";
    }

    return 0;
}
