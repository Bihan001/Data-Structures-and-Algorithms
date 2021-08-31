// https://www.spoj.com/problems/AGGRCOW/
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mii map<int, int>
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int main(int argc, char const *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        int n, c;
        cin >> n >> c;
        vi arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        sort(arr.begin(), arr.end());
        int start = arr[0], end = arr[n - 1], ans = 0;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int tmpc = c - 1, prev = 0;
            for (int i = 1; i < n; i++) {
                if (tmpc == 0) break;
                if (arr[i] - arr[prev] >= mid) tmpc -= 1, prev = i;
            }
            if (tmpc == 0) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
