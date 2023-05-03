/*stack (last is end out) is push and pop in the top */

#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int data;
    struct node *next;
}node;

node *makeNode(int x){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}
void push(node **top, int x){
    node *newNode = makeNode(x);
    if(*top == NULL){
        *top = newNode;
        return;
    }
    newNode->next = *top;
    *top = newNode;
}
void pop(node **top, int x){
    if(*top != NULL){
        node *temp = *top;
        (*top)= temp->next;
        free(temp);
    }
}
int Top(node **top){
    if(*top != NULL){
        return (*top)->data;
    }
}
int size(node *top){
    int ans = 0;
    while(top != NULL){
        ++ans;
        top = top->next;
    }
    return ans;
}
int main(){
    node* head = NULL;
    return 0;
}
/*int n = 0;
int st[10001];
void push(int x){
    *(st + n) = x;
    ++n;
}
void pop(){
    if (n >= 1){
        --n;
    }
}
int top(){
    return st[n - 1];
}
int size(){
    return n;
}
int main(){
    while(1){
        cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n";
        cout<<"1. push\n";
        cout<<"2. pop\n";
        cout<<"3. top\n";
        cout<<"4. size\n";
        cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n";
        cout<<"your choice ";
        int lc;
        cin >> lc;
        if(lc == 1){
            int x;
            cout << "add "; 
            cin >> x;
            push(x);
        }
        else if(lc == 2){
            pop();
        }
        else if(lc == 3){
            cout << top();
        }
        else if(lc == 4){
            cout << size();
        }
        else{
            break;
        }
        
    }
    return 0;
}*/