
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    int height;
};
//int max(int a,int b){
//return a>b?a:b;
//}
int height(struct node* x){
    if(x==NULL)
    return 0;
    return x->height;
}

struct node* newNode(int k){
    struct node* x=(struct node*)malloc(sizeof(struct node));
    x->data=k;
    x->left=NULL;
    x->right=NULL;
    x->height=1;
    return x;
}

struct node* right_rot(struct node* y){
    struct node* x=y->left;
    struct node* temp=x->right;
    x->right=y;
    y->left=temp;
    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->left),height(x->right))+1;
    return x;
}

struct node* left_rot(struct node* x){
    struct node* y=x->right;
    struct node* temp=y->left;
    y->left=x;
    x->right=temp;
    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->left),height(x->right))+1;
    return y;
}
int balfac(struct node* x){
    if(!x)
    return 0;
    return (height(x->left)-height(x->right));
}

struct node* insert(struct node* x, int key){
    if(!x)
    return newNode(key);

    if(key<x->data)
    x->left=newNode(key);
    else if(key>x->data)
    x->right=newNode(key);
    else
    return x;

    x->height=max(height(x->left),height(x->right))+1;
    int balance=balfac(x);

    if(balance>1 && key<x->left->data)
    return right_rot(x);
    if(balance<-1 && key>x->right->data)
    return left_rot(x);
    if(balance>1 && key>x->left->data)
    {
        x->left=right_rot(x->left);
        return right_rot(x);
    }
    if(balance<-1 && key<x->right->data)
    {
        x->right=left_rot(x->right);
        return left_rot(x);
    }
    return x;
}

struct node* minValueNode(struct node* x){
    struct node* curr=x;
    while(curr->left!=NULL)
    {
        curr=curr->left;
    }
    return curr;
}

struct node* deleteNode(struct node* base, int key){
    if(!base)
        return base;
    if(base->left)
        base->left= deleteNode(base->left,key);
    if(base->right)
        base->right= deleteNode(base->right,key);

    else
    {
        if(!(base->left) || !(base->right))
        {
            struct node* temp=base->left?base->left:base->right;
            if(!temp)
            {
                temp=base;
                base=NULL;
            }
            else
            {
                *base=*temp;
                free(temp);
            }
        }
        else{
            struct node* temp=minValueNode(base->right);
            base->data=temp->data;
            base->right=deleteNode(base->right,temp->data);
        }
    }
    if (!base)
        return base;

    base->height=max(height(base->left),height(base->right))+1;
    int balance=balfac(base);

    if (balance>1 && balfac(base->left)>=0)
        return right_rot(base);
    if (balance>1 && balfac(base->left)<0)
    {
        base->left=left_rot(base->left);
        return right_rot(base);
    }
    if(balance<-1 && balfac(base->right)<=0)
        return left_rot(base);
    if(balance<-1 && balfac(base->right)>0)
    {
        base->right=right_rot(base->right);
        return left_rot(base);
    }
    return base;
}
void preOrder(struct node* base){
if(base){
    cout<<base->data<<" ";
    preOrder(base->left);
    preOrder(base->right);
}
}
int main()
{
    struct node *base = NULL;
base = insert(base, 27);
base = insert(base, 9);
base = insert(base, 19);
base = insert(base, 91);
base = insert(base, 90);
base = insert(base, 72);
printf("The output of an AVL tree in preOrder form: \n");
preOrder(base);
printf("\n");
base = deleteNode(base, 9);
base = deleteNode(base, 72);
printf("The tree in preOrder traversal outputs after deletion: \n");
preOrder(base);
printf("\n");
base = insert(base, 1);
base = insert(base, 2709);
printf("The tree in preOrder traversal outputs 2 more inserts: \n");
preOrder(base);
printf("\n");
return 0;

}
