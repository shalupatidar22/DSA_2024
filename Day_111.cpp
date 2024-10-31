#include <iostream>
using namespace std;

// Definition of Node for a doubly linked list
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Function to create a new Node
Node* newNode(int x) {
    Node* node = new Node();
    node->data = x;
    node->next = nullptr;
    node->prev = nullptr;
    return node;
}

// Function to insert a node in sorted order in a doubly linked list
Node* sortedInsert(Node* head, int x) {
    Node* new_node = newNode(x);
    // Case 1: If the list is empty
    if (head == nullptr) {
        return new_node;
    }
    // Case 2: Insert at the beginning if the new data is smaller than the head data
    if (head->data >= x) {
        new_node->next = head;
        head->prev = new_node;
        return new_node;
    }
    // Traverse to find the insertion point
    Node* temp = head;
    Node* prevN = nullptr;
    
    while (temp && temp->data < x) {
        prevN = temp;
        temp = temp->next;
    }
    
    // Case 3: Insert at the end
    if (temp == nullptr) {
        prevN->next = new_node;
        new_node->prev = prevN;
        new_node->next = nullptr;
    }
    // Case 4: Insert in the middle
    else {
        prevN->next = new_node;
        new_node->prev = prevN;
        new_node->next = temp;
        temp->prev = new_node;
    }
    return head;
}

// Function to print the doubly linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    // Insert nodes in sorted order
    head = sortedInsert(head, 10);
    head = sortedInsert(head, 5);
    head = sortedInsert(head, 20);
    head = sortedInsert(head, 15);

    cout << "Doubly Linked List in Sorted Order: ";
    printList(head);

    return 0;
}
