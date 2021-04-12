#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mii map<int, int>
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

/* 
   # Time complexity: O(V.E^2)
   # Works of directed graphs
   # This implementation is done using an vertex adjecency list.
   # Algorithm:
   Step 1. Initialize the residual capacity matrix by assuming flow of each edge as 0 initially for every valid 
           edge pair (i, j) & for all other pair fill it with 0 as well. Also initialize max_flow = 0.
   Step 2. Keep finding the augmenting path and add the min flow of the augmenting path to the max_flow. Also subtract the flow from all direct edges of the path and add to all residual edges of the path.
           Stop if no augmenting path is left.

   # Special Note: In the below algorithm, 'g' is the adjacency list of the undirected graph since we also have 
                   to use the reversed of directed edges of the original directed graph when we are looking for 
                   augmenting paths.
*/

// Initialising these as global variables to avoid passing as reference to every function
vector<vi> graph;    // to store the directed graph
vector<vi> res_cap;  // residual graph
mii parent;          // parent array to store parent of each vertex while doing bfs to backtrack on the augmenting path is found
int n, m;            // n = vertex_count, m = edge_count

int bfs(int s, int t) {
    // resetting parent map
    parent.clear();

    // queue to store the vertex & min flow discovered so far in the augmenting path
    queue<pii> q;
    q.push({s, INF});

    while (!q.empty()) {
        int curr = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : graph[curr]) {
            // If the node hasn't been visited yet and it's residual flow is greater than zero
            if (parent.find(next) == parent.end() && res_cap[curr][next] > 0) {
                // Add current node as parent of the next node
                parent[next] = curr;
                // Finding the minimum flow in the augmenting path
                int new_flow = min(flow, res_cap[curr][next]);
                // If sink is reached, that means the augmenting path has been found so return the min flow.
                if (next == t) return new_flow;
                // If the next node is not sink, then add it to queue for bfs.
                q.push({next, new_flow});
            }
        }
    }

    // if no augmenting path found return flow as 0 to stop loop
    return 0;
}

int edmonds_karp_algo(int s, int t) {
    int max_flow = 0;  // to store the final result (maximum flow possible)
    int flow;          // to store the intermediate flows of augmenting paths

    while (flow = bfs(s, t)) {
        max_flow += flow;  // increment the result

        // Traversing through the augmenting path by backtracking the parent map
        int curr = t;
        while (curr != s) {
            int prev = parent[curr];      // previous is parent of current vertex
            res_cap[prev][curr] -= flow;  // Subtract the min flow from the direct edges in the path
            res_cap[curr][prev] += flow;  // Add the min flow to the opposite edges in the path
            curr = prev;
        }
    }

    return max_flow;
}

int main() {
    cin >> n >> m;
    graph.resize(n);
    res_cap.resize(n);
    for (int i = 0; i < n; i++) res_cap[i].resize(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res_cap[i][j] = 0;
        }
    }

    // vertices are 0-based
    for (int i = 0; i < m; i++) {
        int u, v, capacity;
        cin >> u >> v >> capacity;
        graph[u].pb(v);
        graph[v].pb(u);
        res_cap[u][v] = capacity;
    }

    int s, t;  // s = source vertex & t = sink vertex in the network
    cin >> s >> t;
    cout << "Max flow possible in the network = " << edmonds_karp_algo(s, t) << "\n";

    return 0;
}

/*
Sample i/p ---->
6 9
0 1 7
0 4 4
1 2 5
1 3 3
2 5 8
3 2 3
3 5 5
4 3 2
4 1 3
0 5
Sample o/p ---->
Max flow possible in the network = 10
*/