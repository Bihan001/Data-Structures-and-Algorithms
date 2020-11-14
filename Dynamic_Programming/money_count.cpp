#include <bits/stdc++.h>

using namespace std;

int dp[100];

int getMinCount(int *arr, int h, int key) {
    if (key == 0) return 0;
    int min = INT_MAX;
    for (int i = 0; i <= h; i++) {
        if (key - arr[i] >= 0) {
            int tmp;
            if (dp[key - arr[i]] != -1)
                tmp = dp[key - arr[i]];
            else {
                tmp = getMinCount(arr, h, key - arr[i]);
            }
            if (tmp + 1 < min) min = tmp + 1;
        }
    }
    dp[key] = min;
    return min;
}

int main() {
    int arr[] = {1, 2, 5, 10, 20, 50, 100, 200, 400, 500, 2000};
    int n = sizeof(arr) / sizeof(arr[0]);
    int val = 70;
    for (int i = 0; i < 100; i++) dp[i] = -1;
    dp[0] = 0;
    cout << getMinCount(arr, n - 1, val) << endl;
}