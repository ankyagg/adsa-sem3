#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *right;
    struct node *left;
};

struct node* root=NULL;

struct node* insert(int n,struct node *root){
    if(root==NULL){
        struct node *new = (struct node*)malloc(sizeof(struct node));
        new->data = n;
        new->left = NULL;
        new->right = NULL;
        return new;
    }
    if(n<root->data){
        root->left=insert(n,root->left);
    }
    else if(n>root->data){
        root->right = insert(n,root->right);
    }
    else{
        printf("Already exists");
    }
    return root;
};

struct node* delete(int key,struct node* root){
    if(root==NULL){
        printf("Element not found");
    }
    else {
        if(key<root->data){
            root->left = delete(key,root->left);
        }
        else if(key>root->data){
            root->right = delete(key,root->right);
        }
        else{
            if(root->left == NULL && root->right == NULL){
                free(root);
                return NULL;
            }
            else if(root->left==NULL){
                struct node* temp = root->right;
                free(root);
                return temp;
            }
            else if(root->right==NULL){
                struct node *temp = root->left;
                free(root);
                return temp;
            }
            struct node *temp = root->left;
            while(temp->right!=NULL){
                temp=temp->right;
            }
            root->data = temp->data;
            root->left=delete(temp->data,root->left);
        }
    }
    return root;
};

struct node *search(struct node *root,int key){
    if(root==NULL) return NULL;
    else if(root->data == key){
        printf("%d",root->data);
        return root;
    }
    else if(key> root->data){
        return search(root->right,key);
        
    }
    else{
        return search(root->left,key);
    }
}

void display(struct node *root){
    if(root!=NULL){
        display(root->left);
        printf("%d, ",root->data);
        display(root->right);
    }
}

int main(){
    int n;
    while(1){
        int choice;
        printf("1.Insert\n2.Delete\n3.Search\n4.Display");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1: 
            printf("Enter value to be inserted: ");
            scanf("%d",&n);
            root = insert(n,root);
            break;
            case 2: 
            printf("Enter value to be deleted: ");
            scanf("%d",&n);
            delete(n,root);
            break;
            case 3: 
            printf("Enter value to be searched: ");
            scanf("%d",&n);
            search(root,n);
            break;
            case 4: 
            display(root);
            break;
        }
    }
}
