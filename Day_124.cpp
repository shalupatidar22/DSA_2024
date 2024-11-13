#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

// Function to find intersection point in Y-shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2) {
    if (head1 == NULL || head2 == NULL) return -1;

    Node* temp1 = head1;
    Node* temp2 = head2;

    // Loop until both pointers meet at the intersection point or reach the end.
    while (temp1 != temp2) {
        // Move to the next node in the list or switch lists if at the end.
        temp1 = (temp1 == NULL) ? head2 : temp1->next;
        temp2 = (temp2 == NULL) ? head1 : temp2->next;
    }

    // If temp1 (or temp2) is not null, return the intersection point's data.
    return (temp1 != NULL) ? temp1->data : -1;
}

// Helper function to append a new node with given data at the end of the list
void appendNode(Node*& head, int data) {
    if (head == NULL) {
        head = new Node(data);
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new Node(data);
    }
}

// Helper function to connect a node in list2 to a specific node in list1 to simulate intersection
void createIntersection(Node* head1, Node* head2, int intersectData) {
    Node* temp1 = head1;
    while (temp1 != NULL && temp1->data != intersectData) {
        temp1 = temp1->next;
    }

    if (temp1 == NULL) {
        cout << "Intersection data not found in the first list." << endl;
        return;
    }

    Node* temp2 = head2;
    while (temp2->next != NULL) {
        temp2 = temp2->next;
    }

    temp2->next = temp1;  // Create the intersection
}

// Main function to test intersectPoint function
int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;

    // Creating the first linked list: 1 -> 2 -> 3 -> 4 -> 5
    appendNode(head1, 1);
    appendNode(head1, 2);
    appendNode(head1, 3);
    appendNode(head1, 4);
    appendNode(head1, 5);

    // Creating the second linked list: 10 -> 20 (will intersect at node 4 in the first list)
    appendNode(head2, 10);
    appendNode(head2, 20);

    // Create intersection at node with data 4
    createIntersection(head1, head2, 4);

    int intersection = intersectPoint(head1, head2);
    if (intersection != -1) {
        cout << "Intersection point data: " << intersection << endl;
    } else {
        cout << "No intersection point found." << endl;
    }

    return 0;
}
