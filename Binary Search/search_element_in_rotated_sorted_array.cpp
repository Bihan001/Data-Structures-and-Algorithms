#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mii map<int, int>
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

// Given a sorted array with some rotations ([1, 2, 3] -> [3, 1, 2] on first rotation), find whether a given number exists in the array

// Time complexity: O(log(n))
int main(int argc, char const *argv[]) {
    int n, k;
    cin >> n >> k;
    vi arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int start = 0, end = n - 1;
    int index = -1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == k) {
            index = mid;
            break;
        }
        if (arr[start] <= arr[mid]) {
            if (k >= arr[start] && k <= arr[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        } else {
            if (k >= arr[mid] && k <= arr[end]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }
    cout << index << endl;
    return 0;
}

/*
Input:
6 7
7 8 1 2 3 4

Output:
0
*/