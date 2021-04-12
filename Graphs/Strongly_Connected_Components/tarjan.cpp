#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mii map<int, int>

/*
    # Uses an adjacency vertex list.
    # Requires a Depth First Search Traversal.
    # Requires a stack, two arrays for unique ids and low values of the vertices respectively.
    # Works on directed graphs as every undirected graph is a strongly connected component.
*/

void dfs(int curr, int &id, vector<vi> &graph, vi &ids, vi &low, vector<bool> &on_stack, stack<int> &s) {
    // Adding vertex to stack
    s.push(curr);
    on_stack[curr] = true;

    // Assigning the vertex with an unique id thus marking it visited as well. The low value is also same here.
    ids[curr] = low[curr] = id++;

    for (auto to : graph[curr]) {
        // Visited neighbours if not already visited
        if (ids[to] == -1) dfs(to, id, graph, ids, low, on_stack, s);

        // After visiting the neighbour or if already visited, checking if it is in the stack. If so, we take the min of the current vertex and neightbour low value.
        // We are checking if the neighbour is in stack or not because if its not present in the stack, it can't be a part of curr's scc
        if (on_stack[to]) low[curr] = min(low[curr], low[to]);
    }

    // After visiting all neighbours, if the id and low value of current vertex is equal, that means its not a part of any other scc. Thus we pop all elements uptil curr vertex from the stack(curr included) since they can't be part of curr's scc.
    if (ids[curr] == low[curr]) {
        while (!s.empty()) {
            int node = s.top();
            on_stack[node] = false;
            s.pop();
            if (node == curr) break;
        }
    }
}

// Time complexity: O(V+E) | Space complexity: O(V)
vector<vi> tarjan_scc(vector<vi> &graph, int n) {
    vector<vi> scc;
    // A counter variable to assign an incrementing unique id to all vertices.
    int id = 0;

    // ith element of the ids array will have an unique id once the ith vertex is visited.
    // ith element of the low array will have the id of the head vertex of the scc it is in.
    vi ids(n, -1), low(n, -1);

    // on_stack array to check whether a vertex is present in stack in O(1)
    vector<bool> on_stack(n, false);
    stack<int> s;

    // Running dfs on each vertex
    for (int i = 0; i < n; i++) {
        if (ids[i] == -1) {
            dfs(i, id, graph, ids, low, on_stack, s);
        }
    }

    // Equal low values means that the vertices are of same scc. Here a hashmap is used to extract and categorise the data from low.
    map<int, vi> hash;
    for (int i = 0; i < n; i++) {
        hash[low[i]].pb(i);
    }
    for (auto it : hash) {
        scc.pb(it.second);
    }
    return scc;
}

void add_edge(vector<vi> &graph, int src, int dest) {
    graph[src].pb(dest);
}

int main() {
    int n = 8;
    vector<vi> graph(n);

    add_edge(graph, 6, 0);
    add_edge(graph, 6, 2);
    add_edge(graph, 3, 4);
    add_edge(graph, 6, 4);
    add_edge(graph, 2, 0);
    add_edge(graph, 0, 1);
    add_edge(graph, 4, 5);
    add_edge(graph, 5, 6);
    add_edge(graph, 3, 7);
    add_edge(graph, 7, 5);
    add_edge(graph, 1, 2);
    add_edge(graph, 7, 3);
    add_edge(graph, 5, 0);

    vector<vi> scc = tarjan_scc(graph, n);
    for (auto it : scc) {
        for (auto itt : it) {
            cout << itt << " ";
        }
        cout << endl;
    }
    return 0;
}