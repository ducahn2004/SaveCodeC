
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BinaryTree{

public:
    
    void addNode(TreeNode* &root, int val){
        if(root == NULL){
            root = new TreeNode(val);
        }
        else{
            if(val < root->val){
                addNode(root->left,val);
            }
            else{
                addNode(root->right,val);
            }
        }
    }
    //50 25 12 37 30 43 75
    void preOrderTraversal(TreeNode* root){
        if(root != nullptr){
            cout << root->val << " ";
            preOrderTraversal(root->left);
            preOrderTraversal(root->right);
        }
    }
    //12 25 30 37 43 50 75
    // void Inorder(TreeNode* root){
    //     if(root == nullptr){
    //         return;
    //     }
    //     Inorder(root->left);
    //     cout << root->val << " ";
    //     Inorder(root->right);
    // }
    vector<int>result;
    void Inorder(TreeNode* root){
        if(root == nullptr){
            return;
        }
        Inorder(root->left);
        cout << root->val << " ";
        Inorder(root->right);
    }
    //Not use rescure
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>result;
        stack<TreeNode*>store;
        TreeNode* current = root;
        while(current != nullptr || !store.empty()){
            while(current != nullptr){
                store.push(current);
                current = current->left;
            }
            current = store.top();
            store.pop();
            result.push_back(current->val);
            current = current->right;
        }
        return result;
    }
    void postOrder(TreeNode* root){
        if(root == nullptr){
            return;
        }   
        postOrder(root->left);
        postOrder(root->right);
        cout <<root->val << " ";
    }

    //LevelOrderTreeTravel
    void printLevelOrder(TreeNode* root){
        int h = height(root);
        int i;
        for (i = 1; i <= h; i++)
            printCurrentLevel(root, i);
    }
 
    // Print TreeNodes at a current level
    void printCurrentLevel(TreeNode* root, int level){
        if (root == NULL)
            return;
        if (level == 1)
            cout << root->val << " ";
        else if (level > 1) {
            printCurrentLevel(root->left, level - 1);
            printCurrentLevel(root->right, level - 1);
        }
    }
 
    // Compute the "height" of a tree -- the number of
    // TreeNodes along the longest path from the root TreeNode
    // down to the farthest leaf TreeNode.
    int height(TreeNode* Node){
        if (Node == NULL)
            return 0;
        else {
            
            // Compute the height of each subtree
            int lheight = height(Node->left);
            int rheight = height(Node->right);
    
            // Use the larger one
            if (lheight > rheight) {
                return (lheight + 1);
            }
            else {
                return (rheight + 1);
            }
        }
    }

    /* Function to find LCA of n1 and n2.
    The function assumes that both
    n1 and n2 are present in BST */
    TreeNode* lca(TreeNode* root, int n1, int n2)
    {
        if (root == NULL)
            return NULL;
    
        // If both n1 and n2 are smaller
        // than root, then LCA lies in left
        if (root->val > n1 && root->val > n2)
            return lca(root->left, n1, n2);
    
        // If both n1 and n2 are greater than
        // root, then LCA lies in right
        if (root->val < n1 && root->val < n2)
            return lca(root->right, n1, n2);
    
        return root;
    }
};

int main(){
    TreeNode *root = NULL;
    vector<int> inp{50,25,75,12,37,43,30,91,72,51,49,27,70,53,66};
    BinaryTree BT;
    
    for(auto it : inp){
        BT.addNode(root,it);
    }
    
    BT.preOrderTraversal(root);
}
