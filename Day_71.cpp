#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
    struct Node *random;

    Node(int x){
        data=x;
        next=NULL;
        random=NULL;
    }
};


 void insertinbetween(Node *head){
      Node *temp=head;
      while(temp!=NULL){
          Node *copy=new Node(temp->data);
          copy->next=temp->next;
          temp->next=copy;
          temp=temp->next->next;
      }
  }
  
  void randompointer(Node *head){
      Node *temp=head;
      while(temp!=NULL){
          Node *copy=temp->next;
          if(temp->random!=NULL){
              copy->random=temp->random->next;
          }
          else{
              copy->random=NULL;
          }
          temp=temp->next->next;
      }
  }
  
  Node* removepointer(Node *head){
      Node *temp=head;
      Node *dummy=new Node(-1);
      Node *res=dummy;
      while(temp!=NULL){
          res->next=temp->next;
          res=res->next;
          
          temp->next=temp->next->next;
          temp=temp->next;
      }
  }
    Node *copyList(Node *head) {
        // Write your code here
        insertinbetween(head);
        randompointer(head);
        return removepointer(head);
    }

int main() {
    // Create a simple linked list: 1 -> 2 -> 3 -> 4
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    // Setting up random pointers
    head->random = head->next->next;           // 1's random points to 3
    head->next->random = head;                 // 2's random points to 1
    head->next->next->random = head->next;     // 3's random points to 2
    head->next->next->next->random = head->next->next; // 4's random points to 3

    // Copy the list
    Node* copiedList = copyList(head);

    // Print copied list to verify (data and random pointers)
    Node* temp = copiedList;
    while (temp != NULL) {
        cout << "Node: " << temp->data;
        if (temp->random != NULL) {
            cout << ", Random: " << temp->random->data << endl;
        } else {
            cout << ", Random: NULL" << endl;
        }
        temp = temp->next;
    }

    return 0;
}
