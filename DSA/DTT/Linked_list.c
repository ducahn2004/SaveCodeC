//https://www.youtube.com/watch?v=tLZypRFV-Xk&list=PLux-_phi0Rz1k7dQ7iWAw4xDD-KBHcW0F

#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *next; //link to next element 
}node;
// tao node 
node *makeNode(int x){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}
// print node of llist 
void print(node* head){
    while(head != NULL){
        printf("%d ",head->data);
        head =  head->next;
    }
     // print tail node
     printf("\n");
}
//count of element in llist
//
int size(node *head){
    int cnt = 0;
    while(head != NULL){
        ++cnt;
        head = head ->next;
    }
    return cnt;
}
// find last node in llist
node* last_node(node *head){
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    //this is last node in llist 
    return temp;
}
//add an element to head of linked list 
void pushFront(node **head, int x){ //head is a pointer, pass by reference to head
    node *newNode = makeNode(x);
    //Step1 next of newNode => head
    newNode->next  = *head;//*head => location of node head in linked list 
    //Step2 update  Node head => newNode  
    (*head) = newNode;
}
/*void pushFront(node *&head, int x){
   node *newNode =  makeNode(x);
   newNode -> next = head;
   head = newNode(x); 
}
apply in C++*/

void pushBack(node **head, int x){
    node *temp = *head;
    node *newNode = makeNode(x);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}
/*void pushBack(node *&head, int x){
    node *temp = head;
    node *newNode = makeNote(x);
    if(head == NULL){
        head = newNode;
        return;
    }
    while(temp -> next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    //C++
}*/

void insert(node **head,int k, int x){
    int n = size(*head);
    if(k < 1 || k > n + 1) return;
    if (k == 1){
        pushFront(head,x);
        return;
    }
    node *temp = *head;
    // first location head is 0
    for(int i = 1 ; i < k ; i++){
        temp = temp->next;
    }
    //temp k-1
    node *newNode = makeNode(x);
    newNode->next = temp->next;
    temp->next = newNode;
}
//delete front of llist
void popFront(node **head){
    if(*head == NULL) return;
    node *temp = *head; // release
    *head = (*head)->next;
    free(temp);//delete temp with C++
}
void popBack(node **head){
    if(*head == NULL) return;
    node *temp = *head;
    if(temp->next == NULL){
        *head = NULL;
        free(temp);
        return;
    }
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    node *last = temp->next;
    temp->next = NULL;
    free(last);
}
//xoa node vi tri thu k  0 < k < n voi first node is 0
void erase(node **head, int k){
    int n = size(*head);
    if( k < 0|| k > n) return;
    if( k == 0) popFront(head);
    else{
    node* temp = *head;
    for(int i = 1; i < k; i++){
        temp = temp->next;
        }
        //temp = k
        node* temp_kth = temp->next;//node thu k + 1
        //cho k =>  ket noi voi node thu k + 2
        temp->next = temp_kth->next;
        free(temp_kth);
    }
}
//selection_sort llist
void selection_sort(node **head){
    for(node* i = *head; i!=NULL; i = i->next){
        node* minNode = i;
        for(node *j = i->next; j != NULL; j = j->next){
            if(minNode->data > j->data){
                minNode = j;
            }
        }
        int tmp = minNode->data;
        minNode->data = i->data;
        i->data = tmp;
    }
}


//quicksort 
node* partition(node* first, node* last){
    node* pivot = first;
    node* front = first;//element for run all of llist  
    int temp = 0;
    while(front != NULL && front != last){
        if(front->data < last->data){
            pivot = first;

            //swap node value
            temp = first->data;
            first->data = front->data;
            front->data = temp;

            //visit the next node
            first = first->next;
        }
        //visiting the next node
        front = front->next;
    }

    //change last node value to current node
    temp = first->data;
    first->data = last->data;
    last->data = temp;
    return pivot;
}
void quick_sort(node *first, node* last){
    if(first == last){
        return;
    }
    node* pivot = partition(first,last);
    if(pivot != NULL && pivot->next != NULL){
        quick_sort(pivot->next,last);
    }
    if (pivot != NULL && first != pivot){
        quick_sort(first,pivot);
    }
}


//print reverse llist 
void reversePrint(node* head) {
    if(head != NULL){
        reversePrint(head->next);
        printf("%d\n",head->data);
    }
}
// use recursive method to delete a node with a value from linked list
// ...  
void deleteNode(node **head, int n){
     //node* head = *head;
    if(*head == NULL){
        return;
    }
     
    if((*head)->data == n){
        node* tempDelete = *head;
        *head = (*head)->next;
        free(tempDelete);
    }
    deleteNode(&((*head)->next),n);
}

// use recursive method to find element from llist
int checkElement(node* head, int n){
    if(head == NULL){
        return 0;
    }
    if(head->data == n){
        return 1;
    }
    //recursive
    return checkElement(head->next , n);
}

// reverse a llist
void reverseLlist(node **head){
    node* prev = NULL;
    node* next = NULL;
    node* current = *head;
    while(current != NULL){
        // store next 
        next = current->next;

        // reverse current node's pointer
        current->next = prev;

        //move pointer one position ahead
        prev = current;
        current = next;
    }
    *head = prev;
}
int main(){
    node *head = NULL;
    while(1){
        printf("_ _ _ _ _ _ _ _ _ _ _ _ _ _ \n");
        printf("1. Add to front llist\n");
        printf("2. Add to back llist\n");
        printf("3. Add to given position \n");
        printf("4. Delete front llist\n");
        printf("5. Delete back llist\n");
        printf("6. Delete given position\n");
        printf("8. sort");
        printf("8. print\n");
        printf("_ _ _ _ _ _ _ _ _ _ _ _ _ _ \n");
        printf("Ur choice");
        int lc;
        scanf("%d",&lc);
        if(lc == 1){
            int x;
            printf("insert x ");
            scanf("%d",&x);
            pushFront(&head,x);
        }
        else if(lc == 2){
            int x;
            printf("Insert x ");
            scanf("%d",&x);
            pushBack(&head,x);
        }
        else if(lc == 3){
            int x;
            printf("Insert x ");
            scanf("%d",&x);
            int k;
            printf("Insert  x");
            scanf("%d",&k);
            //insert(&head,k,x);
        }
        else if(lc == 4){
            popFront(&head);
        }
        else if(lc == 5){
            popBack(&head);
        }
        else if(lc == 6){
            int k;
            printf("Insert given position ");
            scanf("%d",&k);
            erase(&head,k);
        }
        else if(lc == 7){
            selection_sort(&head);
        }
        else if(lc == 8){
            print(head);
            printf("\n");
        }
        else{
            break;
        }
    }
}

