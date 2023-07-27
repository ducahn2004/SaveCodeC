#include <iostream>
#include <assert.h>
#include <vector>

class QuickFind{
    std::vector<int> id;

public:
    QuickFind(int n);
    bool connected(int p, int q);
    void link(int p, int q);
};

QuickFind::QuickFind(int n) : id(n){
    std::iota(id.begin(), id.end(), 0); // incrementally assign values, 0, 1, 2, ...
}

bool QuickFind::connected(int p, int q){
    assert(p >= 0 && p < id.size());
    assert(q >= 0 && q < id.size());
    return id[p] == id[q];
}

void QuickFind::link(int p, int q){
    assert(p >= 0 && p < id.size());
    assert(q >= 0 && q < id.size());
    int pid = id[p];
    int qid = id[q];
    for (int i = 0; i < id.size(); ++i)
        if (id[i] == pid)
            id[i] = qid; // move p to q's component
}

class QuickUnion {
protected:
    std::vector<int> id;
public:
    QuickUnion(int n);
    bool connected(int p, int q);
    void link(int p, int q);
protected:
    int root(int i);
};

QuickUnion::QuickUnion(int n): id(n){
    // each node is a root of its own component
    std::iota(id.begin(), id.end(), 0); // incrementally assign values, 0, 1, 2, ...
}

bool QuickUnion::connected(int p, int q){
    return root(p) == root(q);
}

void QuickUnion::link(int p, int q){
    int i = root(p);
    int j = root(q);
    id[i] = j; // move p to q's component by changing root of p to root of q
}

int QuickUnion::root(int i){
    assert(i >= 0 && i < id.size());
		// find root by going up via id array until id[i] == i
    while (i != id[i])
        i = id[i];
    return i;
}

class WeightedQuickUnion {
    std::vector<int> id;
    std::vector<int> count;
public:
    WeightedQuickUnion(int n);
    void link(int p, int q);
    bool connected(int p, int q);
protected:
    int root(int i);
};

WeightedQuickUnion::WeightedQuickUnion(int n)
    : id(n), count(n, 1) // each tree has 1 node
{
    std::iota(id.begin(), id.end(), 0); // incrementally assign values, 0, 1, 2, ...
}

void WeightedQuickUnion::link(int p, int q){
    int i = root(p);
    int j = root(q);
    if (count[i] < count[j]) {
        id[i] = j; // move p to q's component
        count[j] += count[i];
    }
    else {
        id[j] = i; // move q to p's component
        count[i] += count[j];
    }
}

int WeightedQuickUnion::root(int i){
    assert(i >= 0 && i < id.size());
    // find root by going up via id array until id[i] == i
    while (i != id[i])
        i = id[i];
    return i;
}

bool WeightedQuickUnion::connected(int p, int q){
    return root(p) == root(q);
}


class WeightedQuickUnionWithPathCompression {
    std::vector<int> id;
    std::vector<int> count;
public:
    WeightedQuickUnionWithPathCompression(int n);
    void link(int p, int q);
    bool connected(int p, int q);
protected:
    int root(int i);
};

WeightedQuickUnionWithPathCompression::WeightedQuickUnionWithPathCompression(int n)
    : id(n), count(n, 1) // each tree has 1 node
{
    std::iota(id.begin(), id.end(), 0); // incrementally assign values, 0, 1, 2, ...
}

void WeightedQuickUnionWithPathCompression::link(int p, int q){ 
    int i = root(p);
    int j = root(q);
    if (count[i] < count[j]) {
        id[i] = j; // move p to q's component
        count[j] += count[i];
    }
    else {
        id[j] = i; // move q to p's component
        count[i] += count[j];
    }
}

bool WeightedQuickUnionWithPathCompression::connected(int p, int q){
    return root(p) == root(q);
}

int WeightedQuickUnionWithPathCompression::root(int i){
    assert(i >= 0 && i < id.size());
    // find root by going up via id array until id[i] == i
    while (i != id[i]) {
        id[i] = id[id[i]]; // path compression by halving
        i = id[i];
    }
        
    return i;
}
// int main(){
//     int n, p, q;
//     std::cin >> n;
//     UF uf(n);
//     while (std::cin >> p >> q){
//         if (!uf.connected(p, q)){
//             std::cout << p << " " << q << std::endl; // only print when not connected
//             uf.link(p, q); // union them
//         }
//     }
//     return 0;
// }