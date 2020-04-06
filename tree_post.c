/*---------------------------------------------------------------------------
    Write a program for postorder traversal in a binary tree
    BY: DEEPANSHU MITTAL 11912056 I.T.
------------------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;                                   
    struct node* left;
    struct node* right;
}* root;
struct node* new_node(int data)
{
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->left=NULL;
    new->right=NULL;
    return(new);
}
void initialise()                                   //----Tree is assumed to be:----//
{                                                   //           6                  //
    root=new_node(6);                               //          / \                 //
    root->left=new_node(5);                         //         5   4                //
    root->right=new_node(4);                        //        /   / \               //
    root->left->left=new_node(3);                   //       3   2   1              //
    root->right->left=new_node(2);                  
    root->right->right=new_node(1);                                 
    printf("\n The tree is:\n    %d\n   / \\\n  %d   %d\n /   / \\\n%d   %d   %d",root->data,root->left->data,root->right->data,root->left->left->data,root->right->left->data,root->right->right->data);                                           
}
void postorder(struct node* t)
{   
    if(t==NULL)
    return;
    postorder(t->left);
    postorder(t->right);
    printf("%d ",t->data);
}                                                   
void main()                                         
{
    initialise();
    printf("\n Postorder traversal: ");
    postorder(root);
}
