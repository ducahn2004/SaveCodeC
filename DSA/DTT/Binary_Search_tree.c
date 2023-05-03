// C program to insert anode
// in a BST
#include <stdio.h>
#include <stdlib.h>
  
// GivenNode
typedef struct node {
    int key;
    struct node *left, *right;
}node;
  
// Function to create a new BSTnode
node* newNode(int item)
{
    node* temp= (node*)malloc(sizeof(node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
  
// Function to insert a new node with
// given key in BST
node* insert(node*node, int key)
{
    // If the tree is empty, return a newNode
    if (node == NULL)
        return newNode(key);
  
    // Otherwise, recur down the tree
    if (key < node->key) {
        node->left = insert(node->left, key);
        }
    else if (key >node->key) {
        node->right = insert(node->right, key);
        }
  
    // Return the node pointer
    return node;
}
  
// Function to do inOrder traversal of BST
void inOrder(node* root)
{
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}
  
// Driver Code
int main()
{
    /* Let us create following BST 
              50 
           /     \ 
          30      70 
         /  \    /  \ 
       20   40  60   80 
   */
node* root = NULL;
  
    // inserting value 50
    root = insert(root, 50);
  
    // inserting value 30
    insert(root, 30);
  
    // inserting value 20
    insert(root, 20);
  
    // inserting value 40
    insert(root, 40);
  
    // inserting value 70
    insert(root, 70);
  
    // inserting value 60
    insert(root, 60);
  
    // inserting value 80
    insert(root, 80);
  
    // print the BST
    inOrder(root);
  
    return 0;
}