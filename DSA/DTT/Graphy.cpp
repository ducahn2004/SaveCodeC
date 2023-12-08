#include <bits/stdc++.h>
using namespace std;

//Input 
/*
9 9 
1 2
1 3
1 5
2 4
3 6
3 7
3 9
5 8
8 9
*/
int n,m; // so luong dinh, so luong canh
vector<int> adj[1000];
bool visited[1001];

void inp_dfs(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x,y; 
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false , sizeof(visited));
}
void inp_dfs_dir(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x,y; 
        cin >> x >> y;
        adj[x].push_back(y);
        //adj[y].push_back(x);
    }
    memset(visited, false , sizeof(visited));
}

// thuat toan tim kiem theo chieu sau
void DFS(int u){
    cout << u << " ";
    // Danh dau u da duoc tham
    visited[u] = true;
    for(int v : adj[u]){
        //neu dinh V chua duoc tham
        if(!visited[v]) DFS(v);    
    }
}


// BFS tim kiem theo chieu rong 
/*
10 11
1 2
1 3
1 5
1 10
2 4
3 6
3 7 
3 9
6 7
5 8
8 9
*/
int n,m;
vector<int>adj[1000];
bool visited_bfs[1001];
void inp(){
    cin >> n >> m;
    for(int i = 0 ; i < m; i++){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited_bfs,false,sizeof(visited_bfs));
}

void BFS(int u){
    queue<int>q;
    q.push(u);
    visited_bfs[u] = true;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        cout << v << " ";
        for(int x : adj[v]){
            if(!visited_bfs[x]){
                q.push(x);
                visited_bfs[x] = true;
            }
        }
    }
}
int main(){
    inp_dfs();
    DFS(1);
}