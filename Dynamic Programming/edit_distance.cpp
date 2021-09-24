// https://practice.geeksforgeeks.org/problems/edit-distance3702/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> dp;
    int recurse(int n, int m, string s, string t) {
        if (n == 0) return m;
        if (m == 0) return n;
        if (dp[n][m] != -1) return dp[n][m];
        if (s[n - 1] == t[m - 1]) return dp[n][m] = recurse(n - 1, m - 1, s, t);
        return dp[n][m] = 1 + min({recurse(n - 1, m - 1, s, t), recurse(n, m - 1, s, t), recurse(n - 1, m, s, t)});
    }
    int editDistance(string s, string t) {
        // Code here
        dp.resize(s.size() + 10, vector<int>(t.size() + 10, -1));
        int ans = recurse(s.size(), t.size(), s, t);
        return ans;
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
