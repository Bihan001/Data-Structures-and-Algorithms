#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mii map<int, int>
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

// Run dfs through the tree and fill up the timein and timeout arrays
void euler_tour(int curr, int parent, vector<vi> &tree, int &timer, vi &timein, vi &timeout) {
    timein[curr] = ++timer;
    for (int child : tree[curr]) {
        if (child != parent) {
            euler_tour(child, curr, tree, timer, timein, timeout);
        }
    }
    timeout[curr] = timer;
}

// Check if x is ancestor of y in a given tree by checking if the (timein, timeout) interval of x completely overlaps the interval of y
bool isAncestor(int x, int y, const vi &timein, const vi &timeout) {
    if (timein[x] <= timein[y] && timeout[x] >= timeout[y]) return true;
    return false;
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
    vi time_in(n + 1), time_out(n + 1);
    int timer = 0;
    euler_tour(1, 0, tree, timer, time_in, time_out);
    cout << "Number of nodes: " << timer << endl;
    cout << "Timein and Timeout values for all nodes:" << endl;
    for (int i = 1; i <= n; i++) {
        cout << i << ' ' << time_in[i] << ' ' << time_out[i] << endl;
    }
    cout << "Is 1 ancestor of 7?" << endl;
    if (isAncestor(1, 7, time_in, time_out)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}

/*
9
1 2
2 4
2 5
2 6
1 3
3 7
7 8
7 9
*/