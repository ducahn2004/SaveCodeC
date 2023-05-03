#include <iostream>
#include <vector>
#include <bits/stdc++.h>
//https://www.youtube.com/watch?v=GQs3FhwEmy0&list=RDCMUC9L5_YMFz8JfBeQtUic8-3A&index=2
#define HASH_SIZE 10

using namespace std;

struct Node{
    int value;
    struct Node* next;
};
typedef struct Node Node;
Node * hash_table[HASH_SIZE];
//array consist of 11 pointer

/*int hash_func(int data){
    
}*/

// https://www.youtube.com/watch?v=dMyhU07qcgs

const int SIZE = 10;
class MyHashSet_Vector{
    
    private:
        int hashFunction(int key){
            return key%SIZE;    
        }
        vector<vector<int>> myBuckets;
        

    public:
        MyHashSet_Vector(){
            
        }
        void reSizeMyBuckets(){
            myBuckets.resize(SIZE);
        }

        bool contains(vector<int>bucket, int key, int &index){
            for(int i = 0; i < bucket.size(); i++){
                if(bucket[i] == key){
                    index = i;
                    return true;
                }
            }
            return false;
        }

        void add(int key){
            int hashValueIndex = hashFunction(key);
            //vector<int> bucket = myBuckets[hashValueIndex];
            //vector<int>::iterator it = myBuckets[hashValueIndex].begin();
            int index = -1;
            if(!contains(myBuckets[hashValueIndex],key,index)){
                myBuckets[hashValueIndex].push_back(key);
            }
        }

        void remove(int key){
            int hashValueIndex = hashFunction(key);
            vector<int>bucket = myBuckets[hashValueIndex];
            //vector<int>::iterator it;
            int index = -1;
            if(contains(myBuckets[hashValueIndex],key,index)){
                myBuckets[hashValueIndex].erase(myBuckets[hashValueIndex].begin() + index);
            }
        }

        
        
        void print(){
            for(vector<vector<int>>::iterator row = myBuckets.begin(); row != myBuckets.end(); row++){
                for(vector<int>::iterator col = row->begin(); col != row->end(); col++){
                    cout << *col << " ";
                }
                cout << endl;
            }
        }
};



//const int SIZE = 10;
static int arrIndex[SIZE] = {0};
class MyHashSet_Array{

    private:
        //const int SIZE = 100;
        int hashFunction(int key){
            return key%SIZE;
        }
        int arr[SIZE][SIZE];
        
    
    public:
        MyHashSet_Array(){

        }

        bool contains(int arr[],int arrIndexCount,int key,int &index){
            for(int i = 0; i < arrIndexCount; i++){
                if(arr[i] == key){
                    index = i;
                    return true;
                }
            }
            return false;
        }

        void add(int key){
            int hashValueIndex = hashFunction(key);
            int index = -1;
            if(!contains(arr[hashValueIndex],arrIndex[hashValueIndex],key,index)){
                arr[hashValueIndex][arrIndex[hashValueIndex]] = key;
                arrIndex[hashValueIndex]++; 
            }
        }

        void remove(int key){
            int hashValueIndex = hashFunction(key);
            int index = -1;
            if(contains(arr[hashValueIndex],arrIndex[hashValueIndex],key,index)){
                for(int i = index; i < arrIndex[hashValueIndex] - 1;i++){
                    arr[hashValueIndex][i] = arr[hashValueIndex][i+1];
                }
            }
        }

        
        void print(){
            for(int i = 0 ; i < SIZE; i++){
                for(int j = 0; j < arrIndex[i]; j++){
                    cout << arr[i][j] << " ";
                }
                cout << endl;
            }
        }
};


class MyHashSet_LinkedList{
    private:

        int hashFunction(int key){
            return key%SIZE;
        }

        
        struct Node{
            int data;
            struct Node* next;
            Node(){
                
            }
        };

        Node* myBuckets[SIZE] = {NULL};

        Node* makeNode(int value){
            Node* newNode = new Node;
            newNode->data = value;
            newNode->next = NULL;
            return newNode;
        }
        
        bool isEmpty(Node *head){
            return (head == NULL)? true : false;
        }

        int sizeOfLinkedList(Node *head){
            if(head == NULL) return 0;
            else{
                int size = 1;
                Node* temp = head;
                while(temp->next != NULL){
                    temp = temp->next;
                    size++;
                }
                return size;   
            }
        }

        void addNode(Node* &head,int value){
            Node* newNode = makeNode(value);
            if(isEmpty(head)) head = newNode;
            else{
                Node* temp = head;
                while(temp->next != NULL){
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }

        // void removeNode(Node* &head){
        //     Node* temp = head;
        //     if(temp->next = NULL) temp = NULL;
        //     temp = temp->next->next;

        // }

        void removeNode(Node* &head){
            if(head->next->next == NULL){
                head->next = NULL;
            }
            else{
                head->next = head->next->next;
            }
        }
    
        bool contains(Node *head, int value, int &position){
            if (head == NULL) return false;
            else{
                position = 0; // position start 0
                Node* temp = head;
                while(temp != NULL){
                    if(temp->data == value){
                        //position++
                        return true;
                    }
                    position++;
                    temp = temp->next;
                }
                //position begins at 0
                return false;
            }
            
        }

        void printNode(Node *head){
            Node* temp = head;
            while(temp != NULL){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        
    public:

        
        void add(int key){
            int hashValueIndex = hashFunction(key);
            int position = -1;
            if(!contains(myBuckets[hashValueIndex],key,position)){
                addNode(myBuckets[hashValueIndex],key);
            }
        }
        void remove(int key){
            int hashValueIndex = hashFunction(key);
            int position = -1;
            if(contains(myBuckets[hashValueIndex],key, position)){
                if(position == 0){
                    myBuckets[hashValueIndex] = myBuckets[hashValueIndex]->next;
                }else{
                    Node *temp  = myBuckets[hashValueIndex];
                    for(int i = 0; i < position - 1; i++){
                    temp = temp->next;
                    }
                    removeNode(temp);
                }
                
            }
        }
        void print(){
            for(int i = 0; i < SIZE; i++){
                printNode(myBuckets[i]);
            }
        }
        
};


class MyHashMap{
    private:

        int hashFunction(int key){
            return key%SIZE;
        }
        vector<map<int,int>> myHashMap;
        
    public:

        MyHashMap(){
            
        }

        void resizeHash(){
            myHashMap.resize(SIZE);
        }
        bool contains(int key, map<int,int>::iterator index){
            int hashValueIndex = hashFunction(key);
            for(vector<map<int,int>>::iterator row = myHashMap.begin(); row != myHashMap.end(); row++){
                for(map<int,int>::iterator col = row->begin(); col != row -> end(); col++){
                    if(col->first == key){
                        index = col;
                        return true;
                    }
                }
            }
            return false;
        }
        void put(int key){
            int hashValueIndex = hashFunction(key);
            map<int,int>::iterator index = myHashMap[hashValueIndex].begin();
            if(!contains(key,index)){
                myHashMap[hashValueIndex].insert(pair<int,int>(key,1));
                index->second = 1;
            }
            else{
               (index->second)++;
            }
            
        }
        void remove(int key){
            int hashValueIndex = hashFunction(key);
            map<int,int>::iterator index = myHashMap[hashValueIndex].begin();
            if(contains(key,index)){
                myHashMap[hashValueIndex].erase(key);
            }
        }
        void get(int key){
            int hashValueIndex = hashFunction(key);
            map<int,int>::iterator index = myHashMap[hashValueIndex].begin();
            if(contains(key,index)){
                cout << "Key: " << key << " count: " << index->second;
            }
        }
        void print(){
            for(vector<map<int,int>>::iterator row = myHashMap.begin(); row != myHashMap.end(); row++){
                for(map<int,int>::iterator col = row->begin(); col != row -> end(); col++){
                    cout << "<" << col->first << ":" << col->second << "> ";
                }
            }
        }

};
int main(){

    int n;
    cin >> n;
    while(n != 0){
        switch (n){

        case 1:
            cout << "this is hashtableSet_vector" <<endl;
            {MyHashSet_Vector MyHash_SetVector;
            MyHash_SetVector.reSizeMyBuckets();
            for(int i = 0; i < 100; i++){
                MyHash_SetVector.add(i);
            }
            MyHash_SetVector.print();
            cout << endl;
            MyHash_SetVector.remove(13);
            cout << endl;
            MyHash_SetVector.print();}
            break;

        case 2:
            cout << "this is hashtableSet_array" <<endl;
            {MyHashSet_Array MyHash_SetArray;
            //MyHash_SetArray.reSizeMyBuckets();
            for(int i = 0; i < 100; i++){
                MyHash_SetArray.add(i);
            }
            MyHash_SetArray.print();
            cout << endl;
            MyHash_SetArray.remove(13);
            cout << endl;
            MyHash_SetArray.print();
            }
            break;

        case 3:
            cout << "this is hashtableSet_linkedlist" <<endl;
            {MyHashSet_LinkedList Myhash_SetLinkedList;
            for(int i = 0; i < 100; i++){
                Myhash_SetLinkedList.add(i);
            }
            Myhash_SetLinkedList.print();
            cout << endl;
            Myhash_SetLinkedList.remove(13);
            Myhash_SetLinkedList.print();   
            }
            break;

        case 4:
            cout << "this is hashtableMap_vector" <<endl;
            {MyHashMap MyHash_Map;
            MyHash_Map.resizeHash();
            int inp;
            srand((unsigned int)time(NULL));
            for(int i = 0; i < 100; i++){
                inp = 0 + (int)(rand()*(10-0+1.0)/(1.0+RAND_MAX));;
                MyHash_Map.put(inp);
            }
            // 1:3 2:1 3:2 4:1 5:1
            MyHash_Map.print();
            cout << endl;
            MyHash_Map.get(1);
            cout << endl;
            MyHash_Map.remove(3);
            MyHash_Map.print();
            cout <<endl;
            }
            break;

        }
        cout << endl;
        cin >> n;
    }
}