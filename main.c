#include <stdio.h>
#include <stdlib.h>
#include "BST.c"

int main(int argc, char* argv[]) {
    int choice, newVal, removeVal, printChoice, totalNumOfNodes, totalSumOfTree;
    BSTNode *root, *newNode;

    while(1) {
        printMenu();
        scanf("%d", &choice);
        printf("\n");

        switch(choice) {
            case 1:     //insert a Node
                printf("Add a new value: ");
                scanf("%d", &newVal);

                createNode(newVal);

                insertNode(root, newNode);
                break;

            case 2:     //remove a Node
                printf("Value to remove: ");
                scanf("%d", &removeVal);

                removeNode(root, removeVal);
                break;

            case 3:     //print options [inorder, preorder, postorder]
                printOrderMenu();
                scanf("%d", &printChoice);
                printf("\n");

                switch(printChoice) {
                    case 1:     //print inorder
                        printInorder(root);
                        printf("\n");
                        break;

                    case 2:     //print preorder
                        printPreorder(root);
                        printf("\n");
                        break;

                    case 3:     //print postorder
                        printPostorder(root);
                        printf("\n");
                        break;

                    case 0:     //exit printChoice switch
                    default:
                        break;
                }
                break;

            case 4:     //Node count
                totalNumOfNodes = countNodes(root);

                printf("There are currently %d nodes in the tree\n", totalNumOfNodes);
                break;

            case 5:     //Node sum
                totalSumOfTree = sumTree(root);

                printf("Total sum of all values in the tree currently is: %d\n", totalSumOfTree);
                break;

            case 0:     //exit the program
            default:
                return 0;
        }
    }

    return 0;
}