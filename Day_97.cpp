#include <iostream>
#include <vector>
using namespace std;

// Structure for a linked list node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to print a linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to split a linked list into two lists alternately
vector<Node*> alternatingSplitList(Node* head) {
    Node* head1 = nullptr; // First list head
    Node* head2 = nullptr; // Second list head
    Node* temp1 = nullptr; // Temp pointer for first list
    Node* temp2 = nullptr; // Temp pointer for second list
    int cnt = 0;

    // Traverse the original list
    while (head) {
        if (cnt % 2 == 0) {  // Even index: Add to the first list
            if (!head1) {
                head1 = head;
                temp1 = head1;
            } else {
                temp1->next = head;
                temp1 = temp1->next;
            }
        } else {  // Odd index: Add to the second list
            if (!head2) {
                head2 = head;
                temp2 = head2;
            } else {
                temp2->next = head;
                temp2 = temp2->next;
            }
        }
        head = head->next;  // Move to the next node in the original list
        cnt++;
    }

    // Ensure the last node of each list points to nullptr
    if (temp1) temp1->next = nullptr;
    if (temp2) temp2->next = nullptr;

    return {head1, head2};
}

// Function to push a new node at the end of a linked list
void appendNode(Node*& head, int new_data) {
    Node* new_node = new Node(new_data);
    if (!head) {
        head = new_node;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6
    Node* head = nullptr;
    for (int i = 1; i <= 6; i++) {
        appendNode(head, i);
    }

    // Split the list alternately
    vector<Node*> result = alternatingSplitList(head);
    Node* head1 = result[0];
    Node* head2 = result[1];

    // Print the two lists
    cout << "First list: ";
    printList(head1);
    cout << "Second list: ";
    printList(head2);

    return 0;
}
