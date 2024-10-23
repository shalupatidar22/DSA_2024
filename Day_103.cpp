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

int sumOfLastN_Nodes(struct Node* head, int n) {
        // Code here
        struct Node *p=head;
        int sum=0;
        vector<int> a;
        int l=0;
        while(p!=NULL){
            l++;
            a.push_back(p->data);
            p=p->next;
        }
        l--;
        while(n!=0){
            sum+=a[l];
            l--;
            n--;
        }
        return sum;
        
        
    }

int main(){
    int a[]={3,4,5,6,7,2};
    create(a,6);
    cout<<"given linked list is : ";
    display(first);

    cout<<"sum of n nodes is:";
    cout<<sumOfLastN_Nodes(first,3);
}