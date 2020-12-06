#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mii map<int, int>

// Finding the minimum spanning tree using Kruskal's algorithm and DSU data structure

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

// Time complexity: O(ELogE + ELogV) | Space complexity: O(1)
vector<vi> kurskal(vector<vi> &edges) {
    vector<vi> mst;
    mii parent, rank;
    sort(edges.begin(), edges.end(), comp);
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

int main() {
    vector<vi> edges;
    edges.pb({0, 1, 10});
    edges.pb({0, 2, 6});
    edges.pb({0, 3, 5});
    edges.pb({1, 3, 15});
    edges.pb({2, 3, 4});
    vector<vi> mst = kurskal(edges);
    for (auto it : mst) {
        cout << "Src: " << it[0] << " Dest: " << it[1] << " Weight: " << it[2] << endl;
    }
    return 0;
}