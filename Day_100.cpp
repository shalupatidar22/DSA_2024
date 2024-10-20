#include<bits/stdc++.h>
using namespace std;

struct DLLNode{
    int data;
    DLLNode *next;
    DLLNode* prev;
}*first=NULL;

void create(int *a,int n){
    DLLNode *t,*last;
    first=new DLLNode;
    first->data=a[0];
    first->next=NULL;
    first->prev=NULL;
    last=first;

    for(int i=1;i<n;i++){
        t=new DLLNode ;
        t->data=a[i];
        t->prev=last;
        t->next=last->next;
        last->next=t;
        last=t;
    }
}
void display(struct DLLNode *p){
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<"\n";
}

     // function to sort a k sorted doubly linked list
    DLLNode *sortAKSortedDLL(DLLNode *head, int k) {
        // code here
        priority_queue<int,vector<int>,greater<int>> mh;
        DLLNode *temp1=head;
        DLLNode *temp2=head;
        while(temp1){
            mh.push(temp1->data);
            if(mh.size()==k+1){
                temp2->data=mh.top();
                mh.pop();
                temp2=temp2->next;
            }
            temp1=temp1->next;
        }
        while(!mh.empty()){
            temp2->data=mh.top();
            mh.pop();
            temp2=temp2->next;
        }
        return head;
        
    }


int main(){
    int a[]={3,2,1,5,6,4};
    create(a,6);
    cout<<"the given linked list is :";
    display(first);
    cout<<"the sorted linked list is :";
    DLLNode *ans=sortAKSortedDLL(first,2);
    display(ans);

}
