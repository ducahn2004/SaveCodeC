#include <bits/stdc++.h>
using namespace std;


int main(){

    vector<int>a;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int h;
        cin >> h;
        a.push_back(h);
    }
    int max = 0;
    int* arr_element = new int[100]();
    for(int i = 0; i < 100; i++){
        arr_element[i] = 0;
    } 
    for(int i = 0 ; i < a.size(); i++){
        for(int j = i + 1; j < a.size(); j++){
            if(a[i] > a[j]) swap(a[i],a[j]);
        }
    }
    set<int>eleMent(a.begin(),a.end()); // correct
    // for(auto it = eleMent.begin(); it != eleMent.end(); it++){
    //     cout << *it;
    // } 
    for(auto itSet = eleMent.begin(); itSet != eleMent.end(); itSet++){
        int count = 0;
        for(auto itVt = a.begin(); itVt != a.end(); itVt++){
            if((*itSet) == (*itVt)) count++; 
        }
        arr_element[(*itSet)] = count;
    }
    for(int i = 0; i < 100; i++){
        if(arr_element[i] != 0) cout << i <<" "<< arr_element[i] << endl;
    }
    for(int i = 0; i < 100; i++){
        if(max < arr_element[i]) max = arr_element[i];
    }
    for(int i = 1; i < 100; i++){
        if(arr_element[i] + arr_element[i-1] > max) max = arr_element[i] + arr_element[i-1];
    }
}