// Problem: Minimum Spanning Tree
// Contest: SPOJ - Partial
// URL: https://www.spoj.com/problems/MST/
// Memory Limit: 1536 MB
// Time Limit: 2000 ms
// Author: Bihan Chakraborty

#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mii map<int, int>

/*
   # Kruskal's algorithm to find the minimum cost spanning tree uses the greedy approach.

   # Performs better for sparse graphs. For dense graphs, check prim's algorithm.

   # Works only in undirected graphs.

   # Works with an edge list representation of the graph.

   # Uses dsu with path compression

   # Algorithm:
     Sort the edge list
     Loop through the edge list and add the edges to mst if the src and dest vertices of the edges don't have a common parent in the dsu.
     Union the src and dest vertices in the dsu.

   # Time complexity: O(ELogE + ELogV) | Space complexity: O(1)
*/

// Get function for DSU
int Get(mii &parent, int a) {
    return parent[a] = parent[a] == a ? a : Get(parent, parent[a]);
}

// Union function for DSU
void Union(mii &parent, mii &rank, int a, int b) {
    a = Get(parent, a);
    b = Get(parent, b);
    if (rank[a] == rank[b]) {
        rank[a]++;
    }
    if (rank[a] > rank[b]) {
        parent[b] = a;
    } else {
        parent[a] = b;
    }
}

// Helper function to sort in ascending order based on edge weights
bool comp(vi &a, vi &b) {
    return a[2] < b[2];
}

vector<vi> kurskal(vector<vi> &edges) {
    vector<vi> mst;
    mii parent, rank;

    // Sorting edges in ascending order of edge weights
    sort(edges.begin(), edges.end(), comp);

    // Initializing DSU
    for (auto edge : edges) {
        parent[edge[0]] = edge[0];
        parent[edge[1]] = edge[1];
        rank[edge[0]] = 0;
        rank[edge[1]] = 0;
    }

    // Performing union operations on disjoint edges and adding to mst array. We move from lowest to highest edge cost greedily since the edges array is sorted.
    for (auto edge : edges) {
        int x = Get(parent, edge[0]);
        int y = Get(parent, edge[1]);
        if (x == y) continue;
        Union(parent, rank, x, y);
        mst.pb(edge);
    }
    return mst;
}

void add_edge(vector<vi> &edges, int src, int dest, int weight) {
    edges.pb({src, dest, weight});
    edges.pb({dest, src, weight});
}

int main() {
    vector<vi> edges;
    add_edge(edges, 0, 1, 10);
    add_edge(edges, 0, 2, 6);
    add_edge(edges, 0, 3, 5);
    add_edge(edges, 1, 3, 15);
    add_edge(edges, 2, 3, 4);
    vector<vi> mst = kurskal(edges);
    int total_cost = 0;
    for (auto it : mst) {
        cout << "Src: " << it[0] << " Dest: " << it[1] << " Weight: " << it[2] << endl;
        total_cost += it[2];
    }
    cout << "Total MST cost: " << total_cost << endl;
    return 0;
}