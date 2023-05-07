#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {

public:
    ListNode* makeNode(int x){
        ListNode* newNode = new ListNode;
        *newNode = ListNode(x);
        return newNode;
    }
    void pushBack(ListNode *&l1,int x){
        ListNode *temp = l1;
        ListNode *newNode = makeNode(x);
        //ListNode newNode(x);
        if(l1  == nullptr){
            l1 = newNode;
            return;
        }
        while(temp->next != nullptr){
            temp = temp->next;
        }
        (temp->next) = newNode;
    }

    void print(ListNode *head){
        while(head != NULL){
            cout << head->val << " ";
            head = head->next;
        }
    }
    // ListNode* removeElements(ListNode* head, int val) {
        
    // }
};