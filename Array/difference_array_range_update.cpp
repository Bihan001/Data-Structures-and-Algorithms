#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mii map<int, int>
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

// Given an array of n integers, perform q queries on it. In each query, you are given two integers L and R.
// Increment all values in the range L to R (inclusive). After finishing all queries, print the final array

// Time complexity: O(n) | Space complexity: O(n)
int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vi arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    vi diff(n + 1, 0);
    diff[0] = arr[0];
    for (int i = 1; i < n; i++) diff[i] = arr[i] - arr[i - 1];
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        diff[l] += 1;
        diff[r + 1] -= 1;
    }
    arr[0] = diff[0];
    for (int i = 1; i < n; i++) arr[i] = diff[i] + arr[i - 1];
    for (int i = 0; i < n; i++) cout << arr[i] << ' ';
    cout << endl;
    return 0;
}

/*
Input:
5
1 2 3 4 5
3
0 2
1 3
2 3

Output:
2 4 6 6 5

Steps:
Initial array:   1 2 3 4 5
After 1st query: 2 3 4 4 5
After 2nd query: 2 4 5 5 5
After 3rd query: 2 4 6 6 5
*/