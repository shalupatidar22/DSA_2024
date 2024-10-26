#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*first=NULL;

void create(int *a,int n){
    struct Node *t,*last;
    first=new Node;
    first->data=a[0];
    first->next=NULL;
    last=first;

    for(int i=1;i<n;i++){
        t=new Node;
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;

    }
}

void display(struct Node *p){
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<"\n";
}

int count(struct Node* head, int key) {
        // add your code here
        Node *p=head;
        int cnt=0;
        while(p!=NULL){
            if(p->data==key){
                cnt++;
            }
            p=p->next;
        }
        return cnt;
    }
int main(){
    int a[]={1,2,1,3,7,1,4,1};
    create(a,8);
    cout<<"linked list is :";
    display(first);

    cout<<count(first,1);
}