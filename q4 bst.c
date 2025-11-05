#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *right;
    struct node *left;
};

struct node *node = NULL;

struct node *insert(int data,struct node* node){
    if(node==NULL){
        struct node *new = (struct node*) malloc(sizeof(struct node));
        new->data = data;
        new->left = NULL;
        new->right = NULL;
        return new;
    }
    if(data>node->data){
        node->right = insert(data,node->right);
    }
    else if(data< node->data){
        node->left = insert(data,node->left);
    }
    return node;
}

void preorder(struct node* node){
    if(node!=NULL){
        printf("%d ",node->data);
        preorder(node->left);
        preorder(node->right);
    }
}
void postorder(struct node* node){
    if(node!=NULL){
        postorder(node->left);
        postorder(node->right);
        printf("%d ",node->data);
    }
}
void inorder(struct node* node){
    if(node!=NULL){
        inorder(node->left);
        printf("%d ",node->data);
        inorder(node->right);
    }
}

int main(){
    int data;
    while(1){
    printf("\n1.Insert\n2.Preorder\n3.Postorder\n4.Inorder");
    printf("Enter your choice: ");
    int choice ;
    scanf("%d",&choice);
    switch(choice){
        case 1:
        printf("Enter value to be inserted:");
        scanf("%d",&data);
        node = insert(data,node);
        break;
        case 2:
        preorder(node);
        break;
        case 3:
        postorder(node);
        break;
        case 4:
        inorder(node);
        break;

    }
    }
}
