#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to check if the length of the linked list is even
bool isLengthEven(Node** head) {
    Node* p = *head;
    int length = 0;
    
    // Traverse the linked list and count the nodes
    while (p != NULL) {
        length++;
        p = p->next;
    }
    
    // Check if the length is even
    return (length % 2 == 0);
}

// Function to push a new node at the beginning of the list
void push(Node** head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;

    // Create a linked list: 1 -> 2 -> 3 -> 4
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    // Print the list
    printList(head);

    // Check if the length is even
    if (isLengthEven(&head)) {
        cout << "The length of the linked list is even." << endl;
    } else {
        cout << "The length of the linked list is odd." << endl;
    }

    return 0;
}
