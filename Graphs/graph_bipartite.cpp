#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mii map<int, int>
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

/*
A bipartite graph (or bigraph) is a graph whose vertices can be divided into two disjoint and independent sets U and V such that every edge connects a
vertex in U to one in V. Vertex sets U and V are usually called the parts of the graph.
Equivalently, a bipartite graph is a graph that does not contain any odd-length cycles.
We can check for odd cycles by putting colors to vertices. We use two colors and put one in each vertex such that no two adjacent vertices will have
the same color.
*/

// Time complexity: O(n) | Space complexity: O(n)
bool dfs(int curr, const vector<vi> &graph, vi &visited, vi &colors) {
    visited[curr] = true;
    for (int neighbour : graph[curr]) {
        // If two adjacent vertices have the same color and they are not the initial colors, then the graph isn't bipartite
        if (colors[neighbour] == colors[curr] && colors[curr] != 0) return false;
        if (!visited[neighbour]) {
            // Put the opposite color to the neighbour and continue dfs with it
            colors[neighbour] = colors[curr] == 1 ? 2 : 1;
            bool res = dfs(neighbour, graph, visited, colors);
            // If we get false from any neighbour's recursive function, we return false
            if (!res) return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[]) {
    int n, m;
    cin >> n >> m;
    vector<vi> graph(n + 1);
    // we put color: 0 as the for all vertices(represents no color initially). While traversing we use colors 1 and 2
    vi visited(n + 1, false), colors(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    int startingVertex = 1;
    // We mark the color of the starting vertex as 2. It can be 1 as well, doesn't matter
    colors[startingVertex] = 2;
    bool isBipartite = dfs(startingVertex, graph, visited, colors);
    if (isBipartite) {
        cout << "The graph is bipartite";
    } else {
        cout << "The graph is not bipartite";
    }
    cout << endl;
    return 0;
}

/*
Input:
6 6
1 2
1 3
2 4
2 5
3 6
5 6
Output:
The graph is not bipartite

Input:
6 5
1 2
2 4
2 5
3 6
5 6
Output:
The graph is bipartite
*/
