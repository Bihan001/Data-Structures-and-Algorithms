#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mii map<int, int>
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

// Checking if any neighbours of vertex v is having the color 'color'. If so, then we can't put the same color on vertex v.
bool isSafe(int v, int color, const vector<vi> &graph, const vi &nodeColors) {
    for (int neighbour : graph[v]) {
        if (nodeColors[neighbour] == color) return false;
    }
    return true;
}

// Time complexity: O(n ^ k) [k = number of given colors]  | Space Complexity: O(n)
void countWays(int i, int &count, vi &nodeColors, const vector<vi> &graph, const vi &colors) {
    // If all vertices have colors, then we have a valid configuration (all colors will be valid due to the isSafe condition below)
    if (i == graph.size()) {
        count += 1;
        // We can print nodeColors array here to get the colors for all the vertices
        return;
    }
    for (int color : colors) {
        if (isSafe(i, color, graph, nodeColors)) {
            // We check if we can put the current 'color' in vertex i. If it's possible we put it and continue with the next vertex.
            // Then backtrack and reset the color to -1 indicating no color and check with other colors in next iterations.
            nodeColors[i] = color;
            countWays(i + 1, count, nodeColors, graph, colors);
            nodeColors[i] = -1;
        }
    }
}

int main(int argc, char const *argv[]) {
    int n, m, c;
    cin >> n >> m >> c;
    vector<vi> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    vi colors(c), nodeColors(n + 1, -1);
    for (int i = 0; i < c; i++) colors[i] = i + 1;
    int possibleWays = 0;
    countWays(1, possibleWays, nodeColors, graph, colors);
    cout << possibleWays << endl;
}

/*
Input:
4 5 4
1 3
1 4
2 3
2 4
3 4
Output:
48

Input:
3 3 3
1 2
2 3
3 1
Output:
6
*/