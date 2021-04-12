#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mii map<int, int>

/*
    # Uses an adjacency vertex list.
    # Requires two Depth First Search Traversals.
    # Requires a stack.
    # Works on directed graphs as every undirected graph is a strongly connected component.
    # Algorithm:
        Sort the graph topologically and then transpose the graph.
        Pop vertices from the stack and run dfs on it if it is not already visited.
        Every dfs returns a strongly connected component.
*/

// Topological sort
void dfs_1(const vector<vi> &graph, int src, vector<bool> &visited, stack<int> &s) {
    visited[src] = true;
    for (int it : graph[src]) {
        if (!visited[it]) {
            dfs_1(graph, it, visited, s);
        }
    }
    s.push(src);
}

void dfs_2(const vector<vi> &graph, int src, vector<bool> &visited, vi &scc) {
    visited[src] = true;
    scc.pb(src);
    for (int it : graph[src]) {
        if (!visited[it]) {
            dfs_2(graph, it, visited, scc);
        }
    }
}

vector<vi> transpose_graph(const vector<vi> &graph) {
    vector<vi> tg(graph.size());  // Initializing transposed graph
    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            tg[graph[i][j]].pb(i);
        }
    }
    return tg;
}

// Time complexity: O() | Space complexity: O()
vector<vi> kosaraju_scc(vector<vi> &graph) {
    stack<int> s;
    vector<bool> visited(graph.size(), false);

    // Topologically sorting the graph and storing the result in stack s
    for (int i = 0; i < graph.size(); i++) {
        dfs_1(graph, 0, visited, s);
    }

    // Transposing the graph
    vector<vi> tg = transpose_graph(graph);

    // Resetting visited array for next dfs
    for (int i = 0; i < visited.size(); i++) visited[i] = false;

    // Initializing answer array
    vector<vi> total_scc;

    // Popping every vertex x from the stack and running dfs on it. Every vertex reachable from the vertex x together forms a scc.
    while (!s.empty()) {
        int top = s.top();
        s.pop();
        if (!visited[top]) {
            vi scc;
            dfs_2(tg, top, visited, scc);
            total_scc.pb(scc);
        }
    }
    return total_scc;
}

void add_vertex(vector<vi> &graph, int src, int dest) {
    graph[src].pb(dest);
}

int main() {
    int n = 5;
    vector<vi> graph(n + 1);
    add_vertex(graph, 1, 0);
    add_vertex(graph, 0, 2);
    add_vertex(graph, 2, 1);
    add_vertex(graph, 0, 3);
    add_vertex(graph, 3, 4);
    add_vertex(graph, 4, 3);
    vector<vi> scc = kosaraju_scc(graph);
    for (auto it : scc) {
        for (auto itt : it) {
            cout << itt << " ";
        }
        cout << endl;
    }
    return 0;
}