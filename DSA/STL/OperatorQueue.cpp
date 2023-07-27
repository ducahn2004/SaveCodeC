#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//return binary list 1->n 
//  n = 2 generateBinary = ["1","10"]
//  n = 5 generateBinary = ["1", "10","11", "100", "101"]
vector<string> generateBinary(int n){
    vector<string>res;
    queue<string>q;
    q.push("1");
    while(n--){ // ? while n-- is break 
        q.push(q.front() + "0");
        q.push(q.front() + "1");
        res.push_back(q.front());
        q.pop();
    }
    return res;
}
// 49 Queue code learn 
vector<int> firstNegative(vector<int> a, int k)
{
    queue<int> st;
    int n = a.size();
    for (int i = 0; i < k - 1; i++) {
        if (a[i] < 0) st.push(i);
    }
    vector<int> res;
    for (int i = k - 1; i < n; i++) {
        if (a[i] < 0) st.push(i);
        while (!st.empty() && st.front() < i - k + 1) st.pop();
        res.push_back(st.empty() ? 0 : a[st.front()]);
    }
    return res;
}

template <typename T> // T should be comparable (implement operator<)
class PriorityQueue {
private:
    int N;
    int capacity;
    T* a;
public:
    PriorityQueue(int _capacity) : N(0), capacity(_capacity) {
        a = new T[capacity];
    }

    PriorityQueue(const T* items, int _capacity) : N(_capacity), capacity(_capacity) {
        a = new T[capacity];
        for (int i = 0; i < N; i++) {
            a[i] = items[i];
        }
        for (int k = N/2; k >= 0; k--) {
            sink(k);
        }
    }

    ~PriorityQueue() {
        delete[] a;
    }

    bool empty() const {
        return N==0;
    }

    int size() const {
        return N;
    }

    void insert(const T& item) {
        assert(N < capacity); // TODO: resize
        a[N++] = item;
        swim(N-1);
    }

    T peakMin() const {
        assert(!empty());
        return a[0];
    }

    T deleteMin() {
        assert(!empty()); // TODO: resize
        T min = a[0];
        a[0] = a[--N];
        sink(0);
        return min;
    }
private:
    void swim(int k) {
        while (k > 0 && a[k] < a[(k-1)/2]) {
            std::swap(a[k], a[(k-1)/2]);
            k = (k-1)/2;
        }
    }

    void sink(int k) {
        while (2*k+1 < N) {
            int j = 2*k+1;
            if (j+1 < N && a[j+1] < a[j]) j++;
            if (a[k] < a[j]) break;
            std::swap(a[k], a[j]);
            k = j;
        }
    }
};

int main(){
    queue<int>qe;
    qe.size();    // return size of queue
    qe.empty();  // return true if queue empty and false if queue is not empty
    qe.front(); // return the first element is added to queue
    qe.back(); // return the last element is added to queue
    int x;
    qe.push(x); // add a element to last queue
    qe.pop();  // delete first element in queue

}