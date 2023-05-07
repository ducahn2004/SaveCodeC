#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Error{
private:
    string message;

public:
    Error(string message){this->message= message;}
    Error(string expected, string got){this->message = "Expected: " + expected + " but got " + got;}
    Error(int expected, int got): Error(to_string(expected), to_string(got)){

    }
    string getMessage(){return message;}
};
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

    
    ListNode* removeElements(ListNode* head, int val) {
        
        //if val in 0 of llist
        while(head->val != val && head != NULL){
            head = head->next;
        }
        ListNode *temp = head->next;
        ListNode *temp_behind = head;
        while(temp != NULL){
            if(temp->val == val){
                temp_behind->next = temp->next; 
                temp = temp->next;
            }
            else{
                temp_behind = temp_behind->next;
                temp = temp->next;
            }
        }
        return head;
    }
};
int main(){
    // try{
    

    
    // }catch(Error& e) {
	// 	cout << e.getMessage() << endl;
	// }
    Solution so;
    ListNode *head = NULL;
    //test case 1
    // so.pushBack(head,1);
    // so.pushBack(head,2);
    // so.pushBack(head,6);
    // so.pushBack(head,6);
    // so.pushBack(head,6);
    // so.pushBack(head,3);
    // so.pushBack(head,4);
    // so.pushBack(head,5);
    // so.pushBack(head,6);

    //test case 2
    so.pushBack(head,7);
    so.pushBack(head,7);
    so.pushBack(head,7);
    so.pushBack(head,7);
    so.pushBack(head,7);
    so.print(head);
    cout << endl;   
    ListNode* result = so.removeElements(head,7);
    so.print(result);
    
}