#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mii map<int, int>
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

// Find the minimum node in the subtree of all nodes in the given tree

void dfs(int curr, int parent, vi &minNodes, const vector<vi> &graph) {
    minNodes[curr] = curr;

    for (int child : graph[curr]) {
        if (child != parent) {
            dfs(child, curr, minNodes, graph);
            minNodes[curr] = min(minNodes[curr], minNodes[child]);
        }
    }
}

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<vi> tree(n + 1);
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].pb(v);
        tree[v].pb(u);
    }
    vi minNodes(n + 1);
    dfs(1, 0, minNodes, tree);
    for (int i = 1; i <= n; i++) cout << "Node: " << i << " Subtree min node: " << minNodes[i] << endl;
    return 0;
}

/*
10
1 2
1 4
2 8
8 6
8 10
6 9
4 3
4 5
5 7
*/