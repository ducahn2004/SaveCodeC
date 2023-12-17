#include <bits/stdc++.h>

class Edge {
    int v;
    int w;
    double weight;
public:
    Edge(int v, int w, double weight) : v(v), w(w), weight(weight) {}
    int either() const { return v; }
    int other(int vertex) const { return vertex == v ? w : v; }
    double getWeight() const { return weight; }
    bool operator<(const Edge& that) const { return weight < that.weight; }
    bool operator>(const Edge& that) const { return weight > that.weight; }
    bool operator==(const Edge& that) const { return weight == that.weight; }
    bool operator!=(const Edge& that) const { return weight != that.weight; }
    bool operator<=(const Edge& that) const { return weight <= that.weight; }
    bool operator>=(const Edge& that) const { return weight >= that.weight; }
};

class EdgeWeightedGraph {
    int V;
    int E;
    std::vector<std::vector<Edge>> adj;
public:
    EdgeWeightedGraph(int V) : V(V), E(0), adj(V) {}
    
    int getV() const { return V; }
    int getE() const { return E; }
    
    void addEdge(const Edge& e) { // add an edge to the graph
        int v = e.either();
        int w = e.other(v);
        adj[v].push_back(e); // add the edge to the adjacency lists of v
        adj[w].push_back(e); // and w
        ++E;
    }
    
    const std::vector<Edge>& getAdj(int v) const { return adj[v]; }
    
    std::vector<Edge> edges() const {
        std::vector<Edge> edges;
        for (int v = 0; v < V; ++v) {
            for (const Edge& e : adj[v]) {
                if (e.other(v) > v) {
                    edges.push_back(e);
                }
            }
        }
        return edges;
    }
};
class MinimumSpanningTree {
    const EdgeWeightedGraph& G;
    std::queue<Edge> mst;
public:
    MinimumSpanningTree(const EdgeWeightedGraph& G_)
        : G(G_)
    {
        std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> pq;
        for (int v = 0; v < G.getV(); ++v) {
            for (const Edge& e : G.getAdj(v)) {
                if (e.other(v) > v) {
                    pq.push(e);
                }
            }
        }

        WeightedQuickUnionWithPathCompression uf(G.getV());
        while (!pq.empty() && mst.size() < G.getV() - 1) {
            Edge e = pq.top();
            pq.pop();
            int v = e.either();
            int w = e.other(v);
            if (!uf.connected(v, w)) {
                uf.link(v, w);
                mst.push(e);
            }
        }

    }

    std::queue<Edge> edges() const 
    {
        return mst;
    }
};