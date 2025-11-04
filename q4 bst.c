#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *right;
    struct node *left;
};

struct Node* createNode(int data) {
    struct Node* newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL){
        printf("Memory allocation failed");
    }
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
};

struct Node* insert(struct Node* node,int data){
    if(node==NULL){
        return createNode(data);
    }
    if(data<node->data){
        node->left = insert(data,node->left);
    }
    else if(data>node->data){
        node->right = insert(data,node->right);
    }
    return node;
};

void preorder(struct Node* node){
    if(node!=NULL){
        printf("%d ",node->data);
        preorder(node->left);
        preorder(node->right);
    }
};

void inorder(struct Node* node){
    if(node!=NULL){
        inorder(node->left);
        printf("%d ",node->data);
        inorder(node->right);
    }
};


void postorder(struct Node* node){
    if(node!=NULL){
        postorder(node->left);
        postorder(node->right);
        printf("%d ",node->data);
    }
};

int main(){
    struct Node* node = NULL;
    int sequence[] = {5,6,9,22,41,9};
    int n = sizeof(sequence)/sizeof(sequence[0]);
    for(int i = 0 ; i<n;i++){
        node = insert(node,sequence[i]);
    }
    preorder(node);
}
