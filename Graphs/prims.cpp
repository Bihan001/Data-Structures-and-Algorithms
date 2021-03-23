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

// Finding the minimum spanning tree using Prim's algorithm

// Time complexity: O() | Space complexity: O()
vector<vi> prims(const vector<vector<pii>> &graph, int src, int n) {
    priority_queue<vi, vector<vi>, greater<vi>> pq;
    vector<vi> mst;

    // visited array to keep track of all the vertices which have been included in the MST Set so far
    vector<bool> visited(n + 1, false);

    // Adding a dummy edge from starting vertex
    pq.push({0, src, src});  // Edge -> {weight, start_vertex, end_vertex}

    while (!pq.empty()) {
        // extract the edge with minimum weight among  all the active edges
        vi edge = pq.top();
        pq.pop();

        int wt = edge[0];
        int from = edge[1];
        int to = edge[2];

        if (visited[to]) {
            // discard this edge
            continue;
        }

        mst.pb({from, to, wt});  // {start_vertex, end_vertex, weight}
        visited[to] = true;

        for (auto x : graph[to]) {
            if (!visited[x.first]) {
                pq.push({x.second, to, x.first});
            }
        }
    }

    // Removing the dummy edge inserted at start
    mst.erase(mst.begin());

    return mst;
}

void add_vertex(vector<vector<pii>> &graph, int src, int dest, int weight) {
    graph[src].pb({dest, weight});
    graph[dest].pb({src, weight});
}

int main() {
    int n = 8;
    vector<vector<pii>> graph(n + 1);
    add_vertex(graph, 0, 1, 10);
    add_vertex(graph, 0, 2, 6);
    add_vertex(graph, 0, 3, 5);
    add_vertex(graph, 1, 3, 15);
    add_vertex(graph, 2, 3, 4);
    vector<vi> mst = prims(graph, 1, n);
    int total_cost = 0;
    for (auto it : mst) {
        cout << "Src: " << it[0] << " Dest: " << it[1] << " Weight: " << it[2] << endl;
        total_cost += it[2];
    }
    cout << "Total MST cost: " << total_cost << endl;
    return 0;
}