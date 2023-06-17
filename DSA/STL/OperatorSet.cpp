#include <iostream>
#include <vector>
#include <set>
using namespace std;
// Sets are a type of associative container in which each element has 
// to be UNIQUE because the value of the element identifies it. 
//The values are stored in a specific sorted order i.e. either ascending or descending.
vector<vector<int>> uniqueRows(vector<vector<int>> matrix){
    set<vector<int>> checkUnique;
    for(auto it = matrix.begin(); it != matrix.end(); it++){
        checkUnique.insert(*it);
    }
    vector<vector<int>>resultMatrix(checkUnique.begin(),checkUnique.end());
    return resultMatrix;
}
// find a element in set (s.find())
// if don't find element K return s.end();else return iterator this element in set
bool setFind(vector<int> arr, int k)
{
    set<int> s(arr.begin(), arr.end());
    set<int>::iterator it = s.find(k);
    if(it == s.end()){
        return false;
    }
    else{
        return true;
    }
    
} 
// upper_bound return iterator is postilion whose value > key else return end()
    // lower_bound return iterator is postilion whose value < key else return end()

vector<int> setFunction(vector<int> arr, int k)
{
    int m,n;
    set<int> s(arr.begin(), arr.end());
    set<int>:: iterator it;
    
    it = s.upper_bound(k);
    m =  (it != s.end()) ? *it : -1;

    it = s.lower_bound(k);
    n = (it != s.end()) ? *it : -1;

    return {m,n};
}


int main(){
    set<int> s;
    
    // erase(x) x is a position kth or a value 
    //delete a value s =[1,2,3,4,5,6];
    s.erase(s.begin());
    s.erase(3); // s = [1,2,4,5,6,7]
    s.insert(3);
    set<int>s2(s.begin(),s.end()); // copy s -> s2
    // delete element kth in set
    set<int>::iterator it = s.begin(); // create a iterator 
    advance(it,2); // it point 3th element  // 2 is a mount of step 
    s.erase(it);
    s.find(2); // tim gia tri 2 return a pointer
    s.erase(s.begin(), s.find(2)); // remove all element up to 2 in s

    // upper_bound return iterator is postilion whose value > key else return end()
    // lower_bound return iterator is postilion whose value < key else return end()


}