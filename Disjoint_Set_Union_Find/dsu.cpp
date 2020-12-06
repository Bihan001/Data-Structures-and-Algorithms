#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mii map<int, int>

int Get(mii &parent, int a) {
    return parent[a] = parent[a] == a ? a : Get(parent, parent[a]);
}

void Union(mii &parent, mii &rank, int a, int b) {
    a = Get(parent, a);
    b = Get(parent, b);
    if (rank[a] == rank[b]) {
        rank[a]++;
    }
    if (rank[a] > rank[b]) {
        parent[b] = a;
    } else {
        parent[a] = b;
    }
}

int main() {
    mii parent, rank;
    for (int i = 1; i <= 9; i += 2) {
        parent[i] = i;
        rank[i] = 0;
    }
    cout << Get(parent, 1) << endl;
    cout << Get(parent, 5) << endl;
    Union(parent, rank, 1, 5);
    cout << Get(parent, 1) << endl;
    cout << Get(parent, 5) << endl;
    return 0;
}