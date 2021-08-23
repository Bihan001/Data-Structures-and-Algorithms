#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mii map<int, int>
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int main(int argc, char const *argv[]) {
    int n, k;
    cin >> n >> k;
    vi arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int first_occ = -1, last_occ = -1;
    int start = 0, end = n - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == k) {
            first_occ = mid;
            end = mid - 1;
        } else if (arr[mid] < k) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    start = 0, end = n - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == k) {
            last_occ = mid;
            start = mid + 1;
        } else if (arr[mid] < k) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    cout << "First occurence of " << k << ": " << first_occ << endl;
    cout << "Last occurence of " << k << ": " << last_occ << endl;
    return 0;
}

/*
Input:
10 3
1 2 3 3 3 3 5 5 5 7

Output:
First occurence of 3: 2
Last occurence of 3: 5
*/