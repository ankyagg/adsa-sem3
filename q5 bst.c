#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* right;
    struct node* left;
};

struct node* root = NULL;

struct node* insert(struct node* root,int n){
    if(root==NULL){
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = n;
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode;
    }
    if(n<root->data){
        root->left=insert(root->left,n);
    }
    else if(n>root->data){
        root->right = insert(root->right,n);
    }
    else{
        printf("Element already exists");
    }
    return root;
};

struct node* delete(struct node* root,int m){
    if(root==NULL){
        printf("Element not found\n");
        return root;
    }
    else{
        if(m<root->data){
            root->left = delete(root->left,m);
        }
        else if(m>root->data){
            root->right = delete(root->right,m);
        }
        else{
            if(root->left==NULL){
                struct node* temp = root->right;
                free(root);
                return temp;
            }
            else if(root->right==NULL){
                struct node* temp = root->left;
                free(root);
                return temp;
            }
            struct node *temp = root->left;
            while (temp->right != NULL)
                temp = temp->right;
            root->data = temp->data;
            root->left = delete(root->left, temp->data);
        }
    }
    return root;
};

struct node* search(struct node* root,int n ){
    if(root==NULL){
        return NULL;
    }
    if(root->data == n){
        printf("Element Found %d\n",n);
    }
    else if (n<root->data){
        return search(root->left,n);
    }
    else{
        return search(root->right,n);
    }
};

void display(struct node* root){
    if(root!=NULL){
        display(root->left);
        printf("%d ,",root->data);
        display(root->right);
    }
}

int main(){
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);
    search(root,40);
    display(root);

}


