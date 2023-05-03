#include <bits/stdc++.h>
using namespace std;
int main(){
    // Constructor
    int size,val;
    vector<int> vt;
    vector<int> vt2(vt.begin(),vt.end());// copy value  vt.begin() -> vt.end() of vt
    vector<int> vt3(size,val); // vector include size with value val
    vector<int> vt4{10,20,30};
    
    vector<int>::iterator it;
    // creat 2D array 
    int row,column;
    vector<vector<int>>arr (row, vector<int>(column));
    // create vt2 with element from vt\

    //vt.size(); // size of vector

    vt.resize(5); 
    // now size of vector is 5
    // if size_before < 5, new element add to vector = 0;
    // if size_after > 5 , erase all element index 5 -> vt.size()-1;

    vt.resize(10,11);
    // if vt is empty, create 10 element with element's value = 11;
    // if vt isn't empty, vt.size() < 10, add element's value = 10 from index (size()) -> 10
    //vt.end();
    // this is element after last element in vector

    sort(vt.begin(),vt.end());
    // sort in vector

    int position;//th
    int value;
    vt.insert(vt.begin() + position,value); 
    // insert a element to left element (position th - 1)
    vt.erase(vt.begin() + position); 
    // erase element vt[position th - 1];
    int start_position,end_position;//th
    vt.erase(vt.begin() + start_position, vt.begin() + end_position); 
    //  erase element from vt[start_position th - 1] to vt[end_position th - 1] exclusive vt[end_position th - 1]

    vector<int>vt6;
    vt.swap(vt6); // swap value of vt and vt2
    vt.clear();
    // clear vt

    //int val;
    count(vt.begin(),vt.end(),val); // count of val in vt 
    max_element(vt.begin(),vt.end(),val); // max element in vt 
    it = find(vt.begin(),vt.end(),val); // find val in vector, if dont fint it, return vt.end(); else return 
    // this pointer

    //print 2D vector
    vector<vector<int>> vvi;
    //assuming you have a "2D" vector vvi (vector of vector of int's)
    for (vector<vector<int>>::iterator row = vvi.begin(); row != vvi.end(); row++) {
        for (vector<int>::iterator col = row->begin(); col != row->end(); col++) {
            // do stuff ...
        }
    }
}