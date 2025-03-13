#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Binary_Search_Tree {
    struct Binary_Search_Tree *left;
    int data;
    struct Binary_Search_Tree *right;
} tree;

tree* insert(tree* root, int x);
void displayPostorder(tree* root);
void displayPreorder(tree* root);
void displayInorder(tree* root);
int countNodes(tree* root, int c);
int One_child(tree* root, int c);
int Two_child(tree* root, int c);
int Common_Parent(tree* root, int c);
tree* Delete_Node(tree* root, int key);

#endif // BST_H
