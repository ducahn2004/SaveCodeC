#include <iostream>
#include <vector>
#include <list>
using namespace std;
// base index  = 1

// list = double linked list 
// push_back, push_front, pop_back, pop_front
// erase (n)th element to (m)th element 
list<int> changeValue(list<int> l, int n, int m) {
	list<int>:: iterator it1 = l.begin();
    advance(it1, n-1);
    // here it1 is at (n)th element 
    list<int>:: iterator it2 = l.begin();
    advance(it2, m);
    //here it1 is at (m+1)th element 
    l.erase(it1, it2);
    // erase from (n)th to (m)th elements
    // erase use to erase (n)th to (m-1)th with syntax erase(n,m)
    return l;
}
// iterator element (k)th 
int AccessKth(list<int> linkedList, int k){
    list<int>::iterator it = linkedList.begin();
    advance(it,k-1);
    // you are (k)th element in list 
    // k-1 step;
    return *it;
}
// remove all elements's value  = n in list 
list<int> removeAllElements(list<int> linkedList, int n) {
	linkedList.remove(n);
	return linkedList;
}
//erase elements with list.erase()
list<int> removeElements(list<int> linkedList, int n) {
    list<int>::iterator j;
    for(auto i = linkedList.begin(); i != linkedList.end(); i++){
        if(*i >= n){
            j = i;
            i--;
            linkedList.erase(j);
        }
    }
    return linkedList;
}
// sort list 
list<int> sortLinkedList(list<int> l) {
    for (list<int>::iterator it1 = l.begin(); it1 != l.end(); it1++) {
		list<int>::iterator it2 = it1;
		for(;it1 != l.end() && ++it2!=l.end();){
			if(*it1 > * it2){
				int tmp = *it1;
				*it1 = *it2;
				*it2 = tmp;
			}
		}
	}
	return l;
}
// or
list<int> sortLinkedList(list<int> l) {
    l.sort();
	return l;
}
int main(){
    list<int>l;
    l.size(); // size of list 
}