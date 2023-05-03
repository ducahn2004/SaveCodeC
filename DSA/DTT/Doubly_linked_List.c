#include <stdio.h>
#include <stdlib.h>


typedef struct  node{
    int data;
    struct node* next;
    struct node* prev;
}node;

node* makeNode(int x){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
void pushFront(node** head, int x){
    node* newNode = makeNode(x);
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}
void pushBack(node** head, int x){
    node* temp = *head;
    node* newNode = makeNode(x);
    if(!temp){
        temp = newNode;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
void insert(node **head, int k , int x){
    node *newNode = makeNode(x);
    node *temp = *head;
    for(int i = 1; i <= k - 2; k++){
        temp = temp->next;
    }
    //temp is k - 1
    newNode->next = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}
node* SortedInsert(node **head,int data)
{ 
   //reserve memory for this new node
   node *newNode = (node*) malloc(sizeof(node)); 
   //Set the data of newNode as data
   newNode->data = data; 
   //Now we need to update the next and prev pointers of newNode -
   //based on its position
   if((*head) == NULL) {
       //Base case : If the list is empty
       newNode->next = NULL; //Set next and prev pointers as NULL
       newNode->prev = NULL;
       //This node now becomes the head node(the only node), so return it.
       return newNode;
   }
   if((*head)->data >= newNode->data) {
       //If the node's position is in the beginning of the list
       //set the next pointer of the newNode to point to the currentHead
       newNode->next = *head; 
       newNode->prev = NULL; //Because it is the beginning of the list
       //Update the prev pointer of the current head to point to newNode
       (*head)->prev = newNode; 
       //This node now becomes the head node, so make it.
       *head = newNode;
   } else {
       //Find the position of the new node using a temporary current node
       node *current = *head;
       while(current->next != NULL && current->next->data < newNode->data) {
           current = current->next;
       }
       //newNode lies between current and current->next
       newNode->prev = current;
       newNode->next = current->next;
       //It might happen that newNode's position is at the end. 
       //In that case we cannot update the current->next's (which is NULL) 
       //prev pointer
       if(current->next != NULL) {
           current->next->prev = newNode;
       }
       //Update the next pointer of current to point to this new node.
       current->next = newNode; 
   } 
   //Finally return the head pointer.
   return head;
}
void print(node *head){
    while(head != NULL){
        printf("%d",head->data);
        head = head->next;
    }
}
int main(){
    node *head = 0;
    for(int i = 0; i < 10; i++){
        pushBack(&head,i);
    }
    print(head);
    return 0;

}