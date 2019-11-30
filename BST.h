#ifndef BST_H
#define BST_H

typedef struct BSTNode {
    int val;
    struct BSTNODE *left, *right;
} BSTNode;

//prints the current menu of options for the user to interact with
void printMenu();

//prints the menu for the user for order print of the BST nodes
void printOrderMenu();

//uses a users new value to create a new BSTNode
BSTNode* createNode(int);

//inserts a Nod einto the BST
BSTNode* insertNode(BSTNode*, BSTNode*);

//removes a specified Node from the BST
BSTNode* removeNode(BSTNode*, int);

// Find left most child of the tree or subtree
BSTNode* findLeftMostChild(BSTNode*);

//all print order functions
void printInorder(BSTNode*);
void printPreorder(BSTNode*);
void printPostorder(BSTNode*);

//takes in the root of a BST and counts all nodes to return total number of nodes in the tree
int countNodes(BSTNode*);

//Takes in the root and counts the int sum of all the values of the node and returns it.
int sumTree(BSTNode*);

#endif