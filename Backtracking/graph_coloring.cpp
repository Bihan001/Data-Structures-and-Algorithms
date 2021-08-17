#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mii map<int, int>
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int recurse(int i, int iColor, const vector<vi> &graph, const vi &colors, vector<bool> &visited) {
    int cnt = 0;
    for (int next : graph[i]) {
        for (int color : colors) {
            if (iColor == color) continue;
            if (!visited[next]) {
                visited[i] = true;
                cnt += 1 + recurse(next, color, graph, colors, visited);
                visited[i] = false;
            }
        }
    }
    return cnt;
}

int main(int argc, char const *argv[]) {
    int n, m, c;
    cin >> n >> m >> c;
    vector<vi> graph(n + 10);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    vi colors(c);
    vector<bool> visited(n + 1, false);
    for (int i = 0; i < c; i++) cin >> colors[i];
    int possibleWays = 0;
    for (int col : colors) possibleWays += recurse(1, col, graph, colors, visited);
    cout << "Possible ways to color this graph with colors ";
    for (int col : colors) cout << col << " ";
    cout << "is " << possibleWays << endl;
}

/*
Input:
4 5 2
1 3
1 4
2 3
2 4
3 4
1 2
Output:

*/