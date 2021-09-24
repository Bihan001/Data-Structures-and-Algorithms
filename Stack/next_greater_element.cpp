#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mii map<int, int>
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

// Next greater elements on right side and left side
// Time complexity: O(n) | Space complexity: O(n)
int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vi arr(n), resRight(n, -1), resLeft(n, -1);
    for (int i = 0; i < n; i++) cin >> arr[i];
    stack<int> s;
    // Calculating the resRight
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[s.top()] <= arr[i]) s.pop();
        if (!s.empty()) resRight[i] = arr[s.top()];
        s.push(i);
    }
    for (int it : resRight) cout << it << ' ';
    cout << endl;
    while (!s.empty()) s.pop();  // Clearing the stack for resLeft calculation
    // Calculating the resLeft
    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] <= arr[i]) s.pop();
        if (!s.empty()) resLeft[i] = arr[s.top()];
        s.push(i);
    }
    for (int it : resLeft) cout << it << ' ';
    cout << endl;
    return 0;
}

/*
Input:
4
13 7 6 12

Output:
-1 12 12 -1 
-1 13 7 13
*/