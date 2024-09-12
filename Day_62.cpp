#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
}*first=NULL;

 /* Should return data of middle node. If linked list is empty, then -1 */

void create(int A[],int n){
	int i;
	struct Node *t,*last;
	first=new Node;
	first->data=A[0];
	first->next=NULL;
	last=first;
	
	for(i=1;i<n;i++){
		t=new Node;
		t->data=A[i];
		t->next=NULL;
		last->next=t;
		last=t;
		
		
	}
}


    int getMiddle(Node* head) {
        // code here
        Node *p=head;
        Node *q=head;
        int n=0;
        while(p!=NULL){
            p=p->next;
            n++;
        }
        int d=n/2;
        for(int i=0;i<d;i++){
            q=q->next;
        }
        return q->data;
    }
int main(){
   	int A[]={3,4,7,2,6};
    create(A,5);
    cout<<getMiddle(first);

}