
// Problem: Hail XOR
// Contest: CodeChef - December Challenge 2020 Division 2
// URL: https://www.codechef.com/DEC20B/problems/HXOR
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define inf 1e18
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define inputarr(arr, n) \
    for (ll i = 0; i < n; i++) cin >> arr[i];
#define printarr(arr, n) \
    for (ll i = 0; i < n; i++) cout << arr[i] << ' ';

ll closest_power_of_2(ll n) {
    ll p = (ll)log2(n);
    return (ll)(1 << p);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll n, x;
        cin >> n >> x;
        vector<ll> arr;
        for (ll i = 0; i < n; i++) {
            ll tmp;
            cin >> tmp;
            arr.pb(tmp);
        }
        ll all = 0;
        for (auto it : arr) all ^= it;
        if (x == n) {
            for (ll i = 0; i < n - 1; i++) cout << 0 << ' ';
            cout << all << endl;
            continue;
        }
        if (x > n) {
            if (x % 2 == n % 2) {
                for (ll i = 0; i < n - 1; i++) cout << 0 << ' ';
                cout << all << endl;
            } else {
                for (ll i = 0; i < n - 2; i++) cout << 0 << ' ';
                cout << 1 << ' ' << (1 ^ all) << endl;
            }
            continue;
        }
        ll cnt = 0, i = 0, j = 1, ci = 0, minval = LONG_MAX, minj = 0;
        while (cnt < x) {
            if (i >= n - 1) break;
            if (arr[i] == 0) {
                i++;
                continue;
            }
            ci = closest_power_of_2(arr[i]);
            j = i + 1;
            minval = LONG_MAX;
            minj = 0;
            while (j < n) {
                if ((arr[j] ^ ci) < minval) {
                    minval = arr[j] ^ ci;
                    minj = j;
                }
                j++;
            }
            arr[i] = arr[i] ^ ci;
            arr[minj] = minval;
            cnt++;
        }
        for (ll i = 0; i < n; i++) cout << arr[i] << ' ';
        cout << endl;
    }
    return 0;
}