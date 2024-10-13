#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// Function to delete alternate nodes
void deleteAlt(Node *head) {
    Node *curr = head;
    while (curr != nullptr && curr->next != nullptr) {
        Node *temp = curr->next;
        curr->next = temp->next;
        delete temp;
        curr = curr->next;
    }
}

// Function to insert a new node at the end of the list
void insert(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = nullptr;

    if (*head_ref == nullptr) {
        *head_ref = new_node;
        return;
    }

    while (last->next != nullptr) {
        last = last->next;
    }

    last->next = new_node;
}

// Function to print the linked list
void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Main function
int main() {
    Node* head = nullptr;

    // Inserting some values into the list
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);
    insert(&head, 6);

    cout << "Original List: ";
    printList(head);

    // Deleting alternate nodes
    deleteAlt(head);

    cout << "Modified List: ";
    printList(head);

    return 0;
}
