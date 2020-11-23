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

// Works with both directed and undirected weighted graphs

pair<vi, vi> dijkstra(vector<vector<pii>> &graph, int src, int n) {
    set<pii> s;
    vi dist(n + 1, INT_MAX);
    vi prev(n + 1, -1);
    dist[src] = 0;
    s.insert({0, src});
    while (!s.empty()) {
        // Popping the current min element from the set. First value of the pair isn't required as we can get it from the dist array. It is used in the set for getting the min index value
        int current = s.begin()->second;
        s.erase(s.begin());
        // Iterating through the neighbours of current
        for (auto it : graph[current]) {
            // Index of a neighbour
            int adj_el = it.first;
            // Weight of the edge between current and the neighbour
            int weight = it.second;
            if (dist[current] + weight < dist[adj_el]) {
                // Updating the the shorter distance along with the vertex's index in the set
                s.erase({dist[adj_el], adj_el});
                dist[adj_el] = dist[current] + weight;
                s.insert({dist[adj_el], adj_el});
                // Creating parent-child relationship for traversing through the shortest route
                prev[adj_el] = current;
            }
        }
    }
    return {dist, prev};
}

int main() {
    int n = 8;
    vector<vector<pii>> graph(n + 1);
    graph[1].pb({2, 5});
    graph[1].pb({8, 8});
    graph[1].pb({5, 9});
    graph[2].pb({4, 15});
    graph[2].pb({3, 12});
    graph[2].pb({8, 4});
    graph[3].pb({4, 3});
    graph[3].pb({7, 11});
    graph[4].pb({7, 9});
    graph[5].pb({8, 5});
    graph[5].pb({6, 4});
    graph[5].pb({7, 20});
    graph[6].pb({3, 1});
    graph[6].pb({7, 13});
    graph[8].pb({3, 7});
    graph[8].pb({6, 6});
    pair<vi, vi> ans = dijkstra(graph, 1, n);
    cout << "Final minimum distances: ";
    for (auto it : ans.first) cout << it << " ";
    cout << endl;
    cout << "Shortest path from 1 to 7 is: ";
    // Since the algorithm was ran with 1 as source, so we can get shortest path for all vertexes only from 1
    int target = 7;
    while (target != -1) {
        cout << target << " ";
        target = ans.second[target];
    }
    return 0;
}