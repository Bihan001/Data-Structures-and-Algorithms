#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mii map<int, int>

// Checking if cycle is present in a given graph using disjoint set data structure.

int Get(mii &parent, int a) {
    return parent[a] = parent[a] == a ? a : Get(parent, parent[a]);
}

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

bool check_cycle(vector<vi> &graph) {
    mii parent, rank;

    // Initialising DSU
    for (int i = 0; i < graph.size(); i++) {
        parent[i] = i;
        rank[i] = 0;
    }
    for (int i = 0; i < graph.size(); i++) {
        for (int el : graph[i]) {
            int src = i;
            int dest = el;
            int src_parent = Get(parent, src);
            int dest_parent = Get(parent, dest);
            if (src_parent == dest_parent) return true;
            Union(parent, rank, src, dest);
        }
    }
    return false;
}

int main() {
    vector<vi> graph(6);
    graph[0].pb(1);
    graph[1].pb(2);
    graph[2].pb(4);
    graph[4].pb(5);
    graph[4].pb(3);
    graph[3].pb(1);
    bool ans = check_cycle(graph);
    if (ans) {
        cout << "Cycle found";
    } else {
        cout << "No cycle found";
    }
    return 0;
}