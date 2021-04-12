#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
   public:
    long long int recurse(int S[], int m, int n) {
        if (n < 0) return INT_MIN;
        if (n == 0) return 1;
        long long ans = 0;
        for (int i = m - 1; i >= 0; i--) {
            if (n - S[i] >= 0) ans += count(S, i + 1, n - S[i]);
        }
        return ans;
    }
    long long int count(int S[], int m, int n) {
        sort(S, S + m);
        return recurse(S, m, n);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends