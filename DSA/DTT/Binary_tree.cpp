
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
        cout <<root->val;
    }
};

int main(){
    TreeNode *root = NULL;
    vector<int> inp{50,25,75,12,37,43,30};
    BinaryTree BT;
    
    for(auto it : inp){
        BT.addNode(root,it);
    }
    
    BT.inorderTraversal(root);
}
