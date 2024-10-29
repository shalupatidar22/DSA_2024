#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

// Function to partition the list and return the pivot node
Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd) {
    Node* pivot = end;
    Node* prev = nullptr, *cur = head, *tail = pivot;

    while (cur != pivot) {
        if (cur->data < pivot->data) {
            if ((*newHead) == nullptr) (*newHead) = cur;
            prev = cur;
            cur = cur->next;
        }
        else {
            if (prev) prev->next = cur->next;
            Node* temp = cur->next;
            cur->next = nullptr;
            tail->next = cur;
            tail = cur;
            cur = temp;
        }
    }

    if ((*newHead) == nullptr) (*newHead) = pivot;
    (*newEnd) = tail;

    return pivot;
}

// Recursive quicksort function on the linked list
Node* quickSortRecur(Node* head, Node* end) {
    if (!head || head == end) return head;

    Node* newHead = nullptr, *newEnd = nullptr;
    Node* pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot) {
        Node* temp = newHead;
        while (temp->next != pivot) temp = temp->next;
        temp->next = nullptr;

        newHead = quickSortRecur(newHead, temp);

        temp = newHead;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = pivot;
    }

    pivot->next = quickSortRecur(pivot->next, newEnd);

    return newHead;
}

// Main quickSort function to be called
Node* quickSort(Node* head) {
    Node* end = head;
    while (end->next != nullptr) end = end->next;
    return quickSortRecur(head, end);
}

// Function to print the linked list
void printList(Node* node) {
    while (node) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Function to insert a new node at the beginning
void push(Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    Node* a = nullptr;
    push(&a, 5);
    push(&a, 20);
    push(&a, 4);
    push(&a, 3);
    push(&a, 30);

    cout << "Linked List before sorting: ";
    printList(a);

    a = quickSort(a);

    cout << "Linked List after sorting: ";
    printList(a);

    return 0;
}
