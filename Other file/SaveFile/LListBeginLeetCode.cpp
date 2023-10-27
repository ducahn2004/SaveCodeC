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
    bool hasCycle(ListNode *head) {
	
		// making two pointers fast and slow and assignning them to head
        ListNode *fast = head;
        ListNode *slow = head;
        
		// till fast and fast-> next not reaches NULL
		// we will increment fast by 2 step and slow by 1 step
        while(fast != NULL && fast ->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            
			
			// At the point if fast and slow are at same address
			// this means linked list has a cycle in it.
            if(fast == slow)
                return true;
        }
        
		// if traversal reaches to NULL this means no cycle.
        return false;
    }
    ListNode* detectCycle(ListNode* head) {
        // Initialize two pointers, slow and fast, to the head of the linked list.
        ListNode* slow = head;
        ListNode* fast = head;

        // Move the slow pointer one step and the fast pointer two steps at a time through the linked list,
        // until they either meet or the fast pointer reaches the end of the list.
        while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            // If the pointers meet, there is a cycle in the linked list.
            // Reset the slow pointer to the head of the linked list, and move both pointers one step at a time
            // until they meet again. The node where they meet is the starting point of the cycle.
            slow = head;
            while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
            }
            return slow;
        }
        }

        // If the fast pointer reaches the end of the list without meeting the slow pointer,
        // there is no cycle in the linked list. Return nullptr.
        return nullptr;
    }

        // ListNode* removeElements(ListNode* head, int val) {
            
        // }
};