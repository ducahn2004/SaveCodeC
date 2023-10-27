#include <bits/stdc++.h>

using namespace std;

queue<vector<int>> addToQueue(vector<vector<int>> petrolpumps,int i){
    queue<vector<int>> store;
    for(int j = i; j < petrolpumps.size(); j++){
        store.push(petrolpumps[j]);
    }
    for(int j = 0; j < i; j++){
        store.push(petrolpumps[i]);
    }
    return store;
}

int truckTour(vector<vector<int>> petrolpumps) {
    int i = 0;
    bool result_check = false;
    while(!result_check){
        queue<vector<int>> store = addToQueue(petrolpumps,i);
        long long int remainOfPertrol = 0;
        while(!store.empty() || remainOfPertrol >= 0){
            // vector<int> it = store.front();
            // remainOfPertrol += it[0];
            // remainOfPertrol -= it[1];
            remainOfPertrol += store.front()[0];
            remainOfPertrol -= store.front()[1];
            store.pop();
        }
        (store.empty())? i++ : result_check = true;
    }
    return i;
}
int main(){
    int N;
    cin >> N;
    vector<vector<int>> petrolpumps;
    for(int i = 0; i < N; i++){
        int amountOFPetrol;
        int distance;
        cin >> amountOFPetrol >> distance;
        petrolpumps.push_back({amountOFPetrol,distance});
    }
    cout << truckTour(petrolpumps);
}