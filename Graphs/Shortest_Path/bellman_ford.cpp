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

/*
   # It is a graph search algorithm that finds the shortest path between a given source vertex and all other
     vertices in the graph. This algorithm can be used on both weighted and unweighted graphs and also on 
     DG & UG.
  
   # It is a DP based algorithm.
     
   # Like Dijkstra's shortest path algorithm, the Bellman-Ford algorithm is also guaranteed to find the 
     shortest path in a graph. 

   # Though it is slower than Dijkstra's algorithm (Time Complexity: O(V x log(E))), Bellman-Ford 
     (Time Complexity: O(V x E) is capable of handling graphs that contain negative edge weights, so it is 
     more versatile. 

   # It is worth noting that if there exists a negative cycle in the graph, then there is no shortest path. 
     As Going around the negative cycle an infinite number of times would continue to decrease the cost of the 
     path (even though the path length is increasing). 
     Because of this, Bellman-Ford can also detect negative cycles which is a useful feature.

   # An UG can be converted in a DG, and so if a UG contains a -ve weight edge, then basically we can say that
     it's a -ve weight cycle and hence no shortest path exists.

   # Simple algorithm ---->
     1. Mark the dist[src] = 0 (from itself) 
        and dist[all other vertices from src] = infinity
     
     2. If we consider the #vertices = n and #edges = m
        then we just have to relax m edges (n-1) times for worst case.
        i.e. for(int i=1; i<n-1; i++){
                 for(int j=1; j<=m; j++){
                     relax the jth edge
                 }
        }

   # Unlike many other graph algorithms, for Bellman-Ford algorithm, it is more convenient to represent the 
     graph using a single list of all edges (instead of n lists of edges - edges from each vertex) i.e. 
     edge list representation.

   # Bellman-Ford algorithm returns SSSP (Single Source Shortest Path) in ((|V| - 1) x |E|) operations,
     when no negative cycles present in graph.

   # Bellman-Ford algorithm resolves negative cycle SSSP (Single Source Shortest Path) in (2 x (|V| - 1) x |E|) 
     operations, when negative cycles are present in graph.

     Time complexity: O(V x E)
*/

vi bellman_ford(vector<vi> &edgeList, int src, int vertex_count, int edge_count) {
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
    vi dist = bellman_ford(edgeList, 0, vertex_count, edge_count);
    for (auto it : dist) cout << it << " ";
    return 0;
}