#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int source, destination, weight;

    Edge(int src, int dest, int w) : source(src), destination(dest), weight(w) {}
};

struct Graph {
    int numVertices;
    vector<Edge> edges;

    Graph(int V) : numVertices(V) {}

    void addEdge(int src, int dest, int weight) {
        edges.push_back(Edge(src, dest, weight));
    }
};

struct DisjointSet {
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int vertex) {
        if (vertex != parent[vertex]) {
            parent[vertex] = find(parent[vertex]);
        }
        return parent[vertex];
    }

    void Union(int x, int y) {
        int xRoot = find(x);
        int yRoot = find(y);

        if (rank[xRoot] < rank[yRoot]) {
            parent[xRoot] = yRoot;
        } else if (rank[xRoot] > rank[yRoot]) {
            parent[yRoot] = xRoot;
        } else {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }
    }
};

bool compareEdges(const Edge& edge1, const Edge& edge2) {
    return edge1.weight < edge2.weight;
}

vector<Edge> findMinimalSpanningTree(Graph graph) {
    vector<Edge> minimalSpanningTree;

    sort(graph.edges.begin(), graph.edges.end(), compareEdges);
    DisjointSet disjointSet(graph.numVertices);

    for (const Edge& edge : graph.edges) {
        int sourceRoot = disjointSet.find(edge.source);
        int destRoot = disjointSet.find(edge.destination);

        if (sourceRoot != destRoot) {
            minimalSpanningTree.push_back(edge);
            disjointSet.Union(sourceRoot, destRoot);
        }
    }

    return minimalSpanningTree;
}

int main() {
    Graph graph(4);
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 6);
    graph.addEdge(0, 3, 5);
    graph.addEdge(1, 3, 15);
    graph.addEdge(2, 3, 4);

    vector<Edge> minimalSpanningTree = findMinimalSpanningTree(graph);

    cout << "Minimal Spanning Tree:" << endl;
    for (const Edge& edge : minimalSpanningTree) {
        cout << edge.source << " -- " << edge.destination << " : " << edge.weight << endl;
    }

    return 0;
}