// https://www.spoj.com/problems/CLFLARR/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
const int MOD = 1e9 + 7;
const ll INF = 1e18;
#define inputarr(arr, n) \
    for (ll i = 0; i < n; i++) cin >> arr[i];
#define printarr(arr, n) \
    for (ll i = 0; i < n; i++) cout << arr[i] << ' ';

ll findParent(ll x, vll &parents) {
    if (parents[x] == x) return x;
    return parents[x] = findParent(parents[x], parents);
}

void solve() {
    ll n, q;
    cin >> n >> q;
    vll parents(n + 1), arr(n, 0);
    for (int i = 0; i <= n; i++) parents[i] = i;
    vector<vll> queries;
    while (q--) {
        ll l, r, c;
        cin >> l >> r >> c;
        l--, r--;
        queries.pb({l, r, c});
    }
    for (int x = queries.size() - 1; x >= 0; x--) {
        ll l = queries[x][0], r = queries[x][1], c = queries[x][2];
        for (ll i = findParent(l, parents); i <= r; i = findParent(i, parents)) {
            arr[i] = c;
            parents[i] = i + 1;
        }
    }
    for (ll it : arr) cout << it << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
