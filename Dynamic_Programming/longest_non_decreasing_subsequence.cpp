#include <bits/stdc++.h>

using namespace std;

int longest_non_decreasing_subsequence(int *arr, int n, int *dp) {
    for (int i = 1; i < n; i++) {
        int max = INT_MIN;
        for (int j = 0; j < i; j++) {
            if (arr[j] <= arr[i]) {
                if ((1 + dp[j]) >= max) {
                    max = 1 + dp[j];
                }
            }
        }
        dp[i] = max;
    }
    return *max_element(dp, dp + n);
}

int main() {
    int arr[] = {1, 3, 4, 5, 2, 2, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int dp[n] = {1};
    cout << longest_non_decreasing_subsequence(arr, n, dp) << endl;
    for (auto &it : dp) cout << it << " ";
    return 0;
}