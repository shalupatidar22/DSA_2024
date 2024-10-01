#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    // Constructor to create a new node
    Node(int val) {
        data = val;
        next = NULL;
    }
};

long long multiplyTwoLists(Node *first, Node *second) {
    long long mod = 1000000007;
    long long num1 = 0, num2 = 0;
    
    Node *p1 = first;
    Node *p2 = second;
    
    // Convert first linked list into an integer
    while (p1 != NULL) {
        num1 = (num1 * 10 + (p1->data)) % mod;
        p1 = p1->next;
    }
    
    // Convert second linked list into an integer
    while (p2 != NULL) {
        num2 = (num2 * 10 + (p2->data)) % mod;
        p2 = p2->next;
    }
    
    // Return the product modulo 10^9+7
    return (num1 * num2) % mod;
}

// Helper function to add a node to the linked list
void appendNode(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Helper function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data;
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* first = NULL;
    Node* second = NULL;

    // Example input: 123 (as a linked list)
    appendNode(first, 1);
    appendNode(first, 2);
    appendNode(first, 3);
    
    // Example input: 456 (as a linked list)
    appendNode(second, 4);
    appendNode(second, 5);
    appendNode(second, 6);

    // Multiply two linked lists
    long long result = multiplyTwoLists(first, second);
    cout << "Product of the two lists: " << result << endl;

    return 0;
}
