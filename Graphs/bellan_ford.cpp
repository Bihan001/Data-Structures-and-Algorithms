#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define inf 1e18
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define printarr(arr, n) \
    for (ll i = 0; i < n; i++) cout << arr[i] << ' ';

// Finding shortest distance from a single source to all other vertexes in a graph even if the graph contains negative weights
// Also detects if the graph contains any negative cycles
// Works with both directed and undirected weighted graphs

// Time complexity: O(vertex_count * edge_count) | Space complexity: O(vertex_count)
vi bellan_ford(vector<vi> &edgeList, int src, int vertex_count, int edge_count) {
    vi dist(vertex_count, INT_MAX);
    dist[src] = 0;
    for (int i = 1; i < vertex_count; i++) {
        for (int j = 0; j < edge_count; j++) {
            int u = edgeList[j][0];
            int v = edgeList[j][1];
            int w = edgeList[j][2];
            int newDistance = dist[u] + w;
            if (newDistance < dist[v]) {
                dist[v] = newDistance;
            }
        }
    }
    for (int j = 0; j < edge_count; j++) {
        int u = edgeList[j][0];
        int v = edgeList[j][1];
        int w = edgeList[j][2];
        int newDistance = dist[u] + w;
        if (newDistance < dist[v]) {
            cout << "Negative cycle found between vertex " << u << " and " << v << endl;
            break;
        }
    }
    return dist;
}

int main() {
    int vertex_count = 5, edge_count = 8;
    // 0 indexed graph
    vector<vi> edgeList;
    // src, dest, weight
    edgeList.pb({0, 1, -1});
    edgeList.pb({0, 2, 4});
    edgeList.pb({1, 2, 3});
    edgeList.pb({1, 3, 2});
    edgeList.pb({1, 4, 2});
    edgeList.pb({3, 2, 5});
    edgeList.pb({3, 1, 1});
    edgeList.pb({4, 3, -3});
    vi dist = bellan_ford(edgeList, 0, vertex_count, edge_count);
    for (auto it : dist) cout << it << " ";
    return 0;
}