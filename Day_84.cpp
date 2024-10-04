#include <iostream>
using namespace std;

// Node structure for the circular linked list
struct Node {
    int data;
    Node* next;
};

// Function to insert a node at the end of a circular linked list
Node* insertNode(Node* head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    
    if (head == NULL) {
        newNode->next = newNode; // Initialize the first node to point to itself
        return newNode;
    }
    
    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    
    temp->next = newNode;
    newNode->next = head;
    
    return head;
}

// Function to print the circular linked list
void printList(Node* head) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }
    
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

// Function to reverse a circular linked list
Node* reverse(Node* head) {
    if (head == NULL) {
        return NULL;  // If the list is empty, return NULL
    }

    Node *cur = head, *prev = NULL, *next = NULL;
    do {
        next = cur->next;  // Store the next node
        cur->next = prev;  // Reverse the current node's pointer
        prev = cur;        // Move prev and cur one step forward
        cur = next;
    } while (cur != head);

    // Adjust the head pointer and make the last node point to the new head
    head->next = prev;
    head = prev;

    return head;
}

// Function to delete a node from the circular linked list
Node* deleteNode(Node* head, int key) {
    if (head == NULL) {
        return NULL;  // If the list is empty, return NULL
    }
    
    Node* temp = head;
    Node* prev = NULL;

    // Case 1: If head node itself holds the key to be deleted
    if (head->data == key) {
        // If the list contains only one node
        if (head->next == head) {
            delete head;
            return NULL;
        }
        // Find the last node of the list to adjust the circular link
        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        last->next = head->next;
        temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    // Case 2: If key is somewhere other than at head
    while (temp->next != head && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If the node to be deleted is found
    if (temp->data == key) {
        prev->next = temp->next;
        delete temp;
    } else {
        cout << "Node with key " << key << " not found!" << endl;
    }

    return head;
}

int main() {
    Node* head = NULL;

    // Insert nodes into the circular linked list
    head = insertNode(head, 10);
    head = insertNode(head, 20);
    head = insertNode(head, 30);
    head = insertNode(head, 40);
    head = insertNode(head, 50);

    // Display the circular linked list
    cout << "Original Circular Linked List: ";
    printList(head);

    // Reverse the circular linked list
    head = reverse(head);
    cout << "Reversed Circular Linked List: ";
    printList(head);

    // Delete a node from the circular linked list
    int key = 30;
    head = deleteNode(head, key);
    cout << "Circular Linked List after deleting node with data " << key << ": ";
    printList(head);

    return 0;
}
