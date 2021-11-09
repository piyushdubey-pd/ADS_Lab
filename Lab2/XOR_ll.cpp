#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* link;
};
Node* XOR(Node *x, Node *y){
    return (Node*)((uintptr_t)(x) ^ (uintptr_t)(y));
}
void insert(Node* &first, int ndata){
    Node *newNode = new Node();
    newNode->data=ndata;
    
    newNode->link = XOR(first,NULL);
    if(first)
    {
        first->link = XOR(newNode, XOR(first->link, NULL));
    }
    first=newNode;
}
void traverse(Node *head){
    Node *curr=head;
    Node *prev=NULL;
    Node *next;
    
    while(curr){
        cout<<curr->data << " --> ";
        next = XOR(prev,curr->link);
        prev=curr;
        curr=next;
    }
    cout<< "NULL"<<endl;
}
void dele(Node* &first){
    Node* next=XOR(first->link,NULL); // B
    Node* nnext=XOR(first,next->link); //C
    Node* repnext=XOR(nnext->link,next); //D
    first=next;
    first->link = XOR(NULL,nnext);
}

int main(){
    Node* first=NULL;
    int z;
    while(true){
        cout<<"\n\nEnter your choice:\n1 to insert\n2 to check the list\n3 to delete first node\n4 to exit"<<endl;
        cin>>z;
        switch(z){
            case 1:
            cout<<"Enter data to be inserted: ";
            int n;
            cin>>n;
            insert(first,n);
            break;
            case 2:
            cout<<"The list is as follows"<<endl;
            traverse(first);
            break;
            case 3:
            dele(first);
            break;
            case 4:
            exit(0);
            default:
            cout<<"Wrong Choice"<<endl;
        }
    }
    
}
