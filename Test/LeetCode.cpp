#include <iostream>
#include <vector>
#include <stack>
#include <algorithm> 
#include <string>
#include <math.h>
using namespace std;

class ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    ListNode* makeNode(int x){
        ListNode* newNode = new ListNode;
        *newNode = ListNode(x);
        return newNode;
    }
    void pushBack(ListNode *&l1,int x){
        ListNode *temp = l1;
        ListNode *newNode = makeNode(x);
        //ListNode newNode(x);
        if(l1  == nullptr){h
            l1 = newNode;
            return;
        }
        while(temp->next != nullptr){
            temp = temp->next;
        }
        (temp->next) = newNode;
    }

    int lenListNode(ListNode* head){
        int count = 0;
        while(head != NULL){
            count++;
            head = head->next;
        }
        return count;
    }

    void print(ListNode* l1){
        ListNode* temp = l1;
        while(temp != nullptr){
            cout << temp->val << " ";
            temp = temp->next; 
        }
        cout << endl;
    }
};
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
        else if (root->left == NULL){
            root ->right = new TreeNode(val);
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

class Solution {

public:
    bool isAnagram(string s, string t) {
        if(s.size != t.size()) return false;
        vector<char>SStore(s.begin(),s.end());
        vector<char>TStore(t.begin(),t.end());
        sort(SStore.begin(),SStore.end());
        sort(TStore.begin(),TStore.end());
        bool result = true;
        for(int i = 0; i < SStore.size(); i++){
            if(SStore[i] != TStore[i]){
                result = false;
                break;
            }
        }
        return result;
    }
};


int main(){
    Solution solu;
    vector<int>inp{6,6,6,7,7};
    string s = "anagram", t = "nagaram";
    //vector<int>result = solu.runningSum(inp);
    // for(auto it : result){
    //     cout << it << " ";
    // }
    (solu.isAnagram(s,t))? cout << "true": cout << "false";
}