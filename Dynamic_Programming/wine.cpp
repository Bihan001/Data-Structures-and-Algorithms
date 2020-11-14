#include <bits/stdc++.h>

using namespace std;

int dp[10000][10000];

int getMaxProfit(int *arr, int l, int h, int year) {
    if (l == h) return arr[l] * year;
    if (dp[l][h] != -1) return dp[l][h];
    int lval = (arr[l] * year) + getMaxProfit(arr, l + 1, h, year + 1);
    int hval = (arr[h] * year) + getMaxProfit(arr, l, h - 1, year + 1);
    dp[l][h] = max(lval, hval);
    return dp[l][h];
}

int main() {
    int arr[] = {2, 3, 5, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < 10000; j++) {
            dp[i][j] = -1;
        }
    }
    cout << getMaxProfit(arr, 0, n - 1, 1);
    return 0;
}