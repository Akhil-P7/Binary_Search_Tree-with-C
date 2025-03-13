#include "bst.h"

tree* insert(tree* root, int x)
{
    if (root == NULL) 
    {
        tree* ptr = (tree*)(malloc(sizeof(tree)));
        ptr->right = NULL;
        ptr->data = x;
        ptr->left = NULL;
        root = ptr;
    } 
    else 
    {
        if (x < root->data) 
        {
            root->left = insert(root->left, x);
        } 
        else if (x > root->data) 
        {
            root->right = insert(root->right, x);
        }
    }
    return root;
}

void displayPostorder(tree* root) 
{
    if (root != NULL) 
    {
        displayPostorder(root->left);
        displayPostorder(root->right);
        printf("%d ", root->data);
    }
}

void displayPreorder(tree* root) 
{
    if (root != NULL) 
    {
        printf("%d ", root->data);
        displayPreorder(root->left);
        displayPreorder(root->right);
    }
}

void displayInorder(tree* root) 
{
    if (root != NULL) 
    {
        displayInorder(root->left);
        printf("%d ", root->data);
        displayInorder(root->right);
    }
}

int countNodes(tree* root, int c) 
{
    if (root != NULL) 
    {
        c = countNodes(root->left, c);
        c = c + 1;
        c = countNodes(root->right, c);
    }
    return c;
}

int One_child(tree* root, int c) 
{
    if (root != NULL) 
    {
        c = One_child(root->left, c);
        if ((root->left == NULL && root->right != NULL) || (root->right == NULL && root->left != NULL))
            c = c + 1;
        c = One_child(root->right, c);
    }
    return c;
}

int Two_child(tree* root, int c) 
{
    if (root != NULL) 
    {
        c = Two_child(root->left, c);
        if (root->right != NULL && root->left != NULL)
            c = c + 1;
        c = Two_child(root->right, c);
    }
    return c;
}

int Common_Parent(tree* root, int c) 
{
    if (root != NULL) 
    {
        c = Common_Parent(root->left, c);
        if (root->right != NULL && root->left != NULL)
            c = c + 2;
        c = Common_Parent(root->right, c);
    }
    return c;
}

tree* Delete_Node(tree* root, int key) 
{
    if (root != NULL) 
    {
        if (root->data == key) 
        {
            if (root->right != NULL && root->left != NULL) 
            {
                tree* temp1 = root->right;
                tree* temp = root->right;
                while (temp->left != NULL)
                    temp = temp->left;
                temp->left = root->left;
                free(root);
                return temp1;
            }
            if (root->right == NULL && root->left == NULL) 
            {
                free(root);
                return NULL;
            }
            if (root->right == NULL && root->left != NULL) 
            {
                tree* temp = root->left;
                free(root);
                return temp;
            }
        } 
        else if (key > root->data)
            root->right = Delete_Node(root->right, key);
        else if (key < root->data)
            root->left = Delete_Node(root->left, key);
    } 
    else 
    {
        printf("NODE NOT FOUND\n");
    }
    return root;
}
