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
     Find the mst using kruskal's algorithm
     Loop though the edge list and remove one edge from the edge list and again find the mst using Kruskal's algorithm and keep track of the minimum cost
     The minimum cost that is not equal to the cost of the actual mst is the cost of the second mst

   # Time complexity: O(E * (ELogE + ELogV)) | Space complexity: O(1)
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

int calc_mst_cost(const vector<vi> &mst, int n) {
    int total_cost = 0;
    if (mst.size() != (n - 1)) return -1;
    for (auto it : mst) total_cost += it[2];
    return total_cost;
}

vector<vi> kruskal(vector<vi> &edges) {
    vector<vi> mst;
    mii parent, rank;

    // Initializing DSU
    for (auto edge : edges) {
        parent[edge[0]] = edge[0];
        parent[edge[1]] = edge[1];
        rank[edge[0]] = 0;
        rank[edge[1]] = 0;
    }
    for (auto edge : edges) {
        int x = Get(parent, edge[0]);
        int y = Get(parent, edge[1]);
        if (x == y) continue;
        Union(parent, rank, x, y);
        mst.pb(edge);
    }
    return mst;
}

// Time complexity: O(ELogE + ELogV) | Space complexity: O(1)
vector<vi> second_mst_kruskal(vector<vi> &edges, int n) {
    vector<vi> second_mst;
    int mst_cost = 0;
    int second_mst_cost = INT_MAX;  // If no mst exists, then second mst will be INT_MAX

    // Sorting edges in ascending order of edge weights
    sort(edges.begin(), edges.end(), comp);

    mst_cost = calc_mst_cost(kruskal(edges), n);

    if (mst_cost == -1) return {};

    for (int i = 0; i < edges.size(); i++) {
        vector<vi> edges_copy = edges;
        vi tmp_edge = edges_copy[i];
       // Removing ith edge
        edges_copy.erase(edges_copy.begin() + i);
       // Removing opposite edge as the graph is bidirectional 
       for (int j = 0; j < edges_copy.size(); j++) {
            if (edges_copy[j][0] == tmp_edge[1] && edges_copy[j][1] == tmp_edge[0] && edges_copy[j][2] == tmp_edge[2]) {
                edges_copy.erase(edges_copy.begin() + j);
                break;
            }
        }
        vector<vi> tmp_second_mst = kruskal(edges_copy);
        int tmp_cost = calc_mst_cost(tmp_second_mst, n);
        if (tmp_cost != -1) {
            if (tmp_cost < second_mst_cost && tmp_cost != mst_cost) {
                second_mst_cost = tmp_cost;
                second_mst = tmp_second_mst;
            }
        }
        edges_copy.clear();
        tmp_second_mst.clear();
    }
    return second_mst;
}

void add_edge(vector<vi> &edges, int src, int dest, int weight) {
    edges.pb({src, dest, weight});
    edges.pb({dest, src, weight});
}

int main() {
    int total_vertex_count = 6;
    vector<vi> edges;
    add_edge(edges, 0, 1, 13);
    add_edge(edges, 1, 2, 7);
    add_edge(edges, 2, 3, 2);
    add_edge(edges, 0, 3, 27);
    add_edge(edges, 1, 3, 28);
    add_edge(edges, 0, 4, 39);
    add_edge(edges, 3, 4, 34);
    add_edge(edges, 4, 5, 36);
    add_edge(edges, 3, 5, 14);
    add_edge(edges, 2, 5, 7);

    vector<vi> mst = second_mst_kruskal(edges, total_vertex_count);
    int total_cost = calc_mst_cost(mst, total_vertex_count);
    if (total_cost == -1) {
        cout << "No mst found";
    } else {
        for (auto it : mst) {
            cout << "Src: " << it[0] << " Dest: " << it[1] << " Weight: " << it[2] << endl;
        }
        cout << "Total MST cost: " << total_cost << endl;
    }
    return 0;
}
