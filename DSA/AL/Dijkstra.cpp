#include <iostream>
#include <vector>
#include <limits>
#include <cstring>
using namespace std;

bool visited[5];
vector<vector<int>> store[6];  // Increase the size of the store vector to 6
int Distance[5];

void inp() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        store[a].push_back({b, d});
    }
    memset(visited, false, sizeof(visited));
    memset(Distance, 0x3f, sizeof(Distance));  // Initialize to INT_MAX
}

void distancePoint(int n) {
    for (int i = 0; i < store[n].size(); i++) {
        vector<int> arr = store[n][i];
        Distance[arr[0]] = min(Distance[arr[0]], arr[1] + Distance[n]);
    }
}

int findMin() {
    int min_index = -1;
    int min = numeric_limits<int>::max();  // Use INT_MAX
    for (int i = 0; i < 5; i++) {
        if (Distance[i] < min && !visited[i]) {
            min = Distance[i];
            min_index = i;
        }
    }
    return min_index;
}

void dijkstra(int n) {
    Distance[n] = 0;
    int check = 5;
    for (int i = 0; i < check; i++) {
        int h = findMin();
        visited[h] = true;
        distancePoint(h);
    }
}

int main() {
    inp();
    dijkstra(0);
    for (int i = 0; i < 5; i++) {
        cout << Distance[i] << " ";
    }
    return 0;
}