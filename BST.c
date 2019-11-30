#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

void printMenu() {
    printf("\n#########################################\n");
    printf("#        Binary Search Tree Menu        #\n");
    printf("#########################################\n");
    printf("\t1 - Insert a Node\n");
    printf("\t2 - Remove a Node\n");
    printf("\t3 - Print Options\n");
    printf("\t4 - Count total num of Nodes\n");
    printf("\t5 - Sum of all Nodes\n");
    printf("\t0 - Quit\n");
    printf("Enter your selection: ");
}

void printOrderMenu() {
    printf("\n#########################################\n");
    printf("#          Choose how to Print          #\n");
    printf("#########################################\n");
    printf("\t1 - Print inorder\n");
    printf("\t2 - Print preorder\n");
    printf("\t3 - Print postorder\n");
    printf("\t0 - Quit\n");
    printf("Enter your selection: ");
}

BSTNode* createNode(int v) {
    BSTNode *newNode = (BSTNode*)malloc(sizeof(BSTNode));

    newNode->val = v;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

BSTNode* insertNode(BSTNode *root, BSTNode *newNode) {
    /*
    if(root == NULL)
        return newNode;

    else if(root->val >= newNode->val)
        root->left = insertNode(root->left, newNode);
    else
        root->right = insertNode(root->right, newNode);
    */
    if (root == NULL)
        return newNode;

    if (newNode->val < root->val) 
        root->left  = insertNode(root->left, newNode); 
    else if (newNode->val > root->val) 
        root->right = insertNode(root->right, newNode); 

    return root;
}

BSTNode* removeNode(BSTNode *root, int v) {
    if(root == NULL)
        return NULL;
    if(root->val > v)
        root->left = removeNode(root->left, v);
    else if(root->val < v)
        root->right = removeNode(root->right, v);
    else
    {
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if(root->left == NULL || root->right == NULL)
        {
            BSTNode *tmp;
            if(root->left == NULL)
                tmp = root->right;
            else
                tmp = root->left;
            free(root);
            return tmp;
        }
        else
        {
            BSTNode *tmp = findLeftMostChild(root->right);
            root->val = tmp->val;
            root->right = removeNode(root->right, tmp->val);
        }
    }
    return root;
}

BSTNode* findLeftMostChild(BSTNode* root) {
    if(root == NULL)
        return NULL;
    else if(root->left != NULL)
        return findLeftMostChild(root->left);
    return root;
}

void printInorder(BSTNode* root) { 
     if (root == NULL) 
          return; 
  
     //left child
     printInorder(root->left); 
  
     //node
     printf("%d ", root->val);   
  
     //right child
     printInorder(root->right); 
} 

void printPreorder(BSTNode* root) { 
     if (root == NULL) 
          return; 
  
     //node
     printf("%d ", root->val);   
  
     //left subtree
     printPreorder(root->left);   
  
     //right subtree
     printPreorder(root->right); 
}

void printPostorder(BSTNode* root) { 
     if (root == NULL) 
        return; 
  
     //left subtree 
     printPostorder(root->left); 
  
     //right subtree 
     printPostorder(root->right); 
  
     //node
     printf("%d ", root->val); 
}   

int countNodes(BSTNode* root) {
    int totalNumOfNodes = 0;

    if(root == NULL)
        return 0;

    countNodes(root->left);

    totalNumOfNodes++;

    countNodes(root->right);

    return totalNumOfNodes;
}

int sumTree(BSTNode* root) {
    int totalSumOfNodes = 0;

    if(root == NULL)
        return 0;

    sumTree(root->left);

    totalSumOfNodes+= root->val;

    sumTree(root->right);

    return totalSumOfNodes; 
}