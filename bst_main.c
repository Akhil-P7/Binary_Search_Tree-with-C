#include "bst.h"

int main() 
{
    tree* root = NULL;
    int ch, x, c = 0, k;
    do 
    {
        printf("\nEnter your Choice:\n");
        printf("1. Insert Node\n");
        printf("2. Postorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Inorder Traversal\n");
        printf("5. Count Total Nodes\n");
        printf("6. Count Nodes with One Child\n");
        printf("7. Count Nodes with Two Children\n");
        printf("8. Count Nodes with Common Parent\n");
        printf("9. Delete a Node\n");
        printf("0. EXIT\n");
        printf("Your Choice: ");
        scanf("%d", &ch);

        switch (ch) 
        {
            case 0:
                    exit(0);
            case 1:
                    printf("Enter the value: ");
                    scanf("%d", &x);
                    root = insert(root, x);
                    break;
            case 2:
                    if (root == NULL) 
                    {
                        printf("BST is Empty\n");
                    } 
                    else 
                    {
                        displayPostorder(root);
                        printf("\n");
                    }
                    break;
            case 3:
                    if (root == NULL) 
                    {
                        printf("BST is Empty\n");
                    } 
                    else 
                    {
                        displayPreorder(root);
                        printf("\n");
                    }
                    break;
            case 4:
                    if (root == NULL) 
                    {
                        printf("BST is Empty\n");
                    } 
                    else 
                    {
                        displayInorder(root);
                        printf("\n");
                    }
                    break;
            case 5:
                    c = countNodes(root, c);
                    printf("Total Nodes in BST: %d\n", c);
                    c = 0;
                    break;
            case 6:
                    c = One_child(root, c);
                    printf("Nodes with One Child: %d\n", c);
                    c = 0;
                    break;
            case 7:
                    c = Two_child(root, c);
                    printf("Nodes with Two Children: %d\n", c);
                    c = 0;
                    break;
            case 8:
                    c = Common_Parent(root, c);
                    printf("Nodes with Common Parent: %d\n", c);
                    c = 0;
                    break;
            case 9:
                    printf("Enter the Value to be Deleted: ");
                    scanf("%d", &k);
                    root = Delete_Node(root, k);
                    break;
            default:
                    printf("INVALID CHOICE\n");
        }
    }while (1);

    return 0;
}
