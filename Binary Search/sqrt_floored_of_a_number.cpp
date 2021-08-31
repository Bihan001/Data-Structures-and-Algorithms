#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mii map<int, int>
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

// Find the square root of a number using binary search upto a certain precision

// Time complexity: O(log(n))
int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    int start = 0, end = n;
    double ans = 0;

    // Binary search to get the integer part
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (mid * mid <= n) {
            ans = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    // Brute force to get the decimal part (Low time complexity as we consider of a few decimal places)
    int precission = 3;
    double inc = 0.1;
    for (int i = 1; i <= precission; i++) {
        while (ans * ans <= n) {
            ans += inc;
        }
        ans -= inc;
        inc = inc / 10;
    }
    cout << ans << endl;
    return 0;
}

/*
Input:
3

Output:
1.732
*/