#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mii map<int, int>
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

// Start from a city and visit all the other cities and get back to the starting city with minimum total cost

int n, startingCity, VISITED_ALL;

// Time complexity: Without Memoization: O(n!), With Memoization: O(2^n . n)
int tsp_dp(int currCity, int mask, const vector<vi> &adjMatrix, vector<vi> &dp) {
    // If all cities are visited, return distance from the current city to the starting city
    if (mask == VISITED_ALL) return adjMatrix[currCity][startingCity];

    if (dp[currCity][mask] != -1) return dp[currCity][mask];

    int ans = INT_MAX;

    // Looping through all cities connected with currCity in the adjMatrix
    for (int i = 0; i < n; i++) {
        // This binary number has one in the ith position, rest are 0
        int newMask = (1 << i);

        // The ith city is not visited yet
        if ((newMask & mask) == 0) {
            // We are marking the ith bit of mask as 1 by doing mask = mask | newMask
            ans = min(ans, adjMatrix[currCity][i] + tsp_dp(i, mask | newMask, adjMatrix, dp));
        }
    }

    return dp[currCity][mask] = ans;
}

int main(int argc, char const *argv[]) {
    vector<vi> adjMatrix = {{0, 20, 42, 25}, {20, 0, 30, 34}, {42, 30, 0, 10}, {25, 34, 10, 0}};
    n = adjMatrix.size();

    // There are max n cities and the mask can contain a max of 2^n possible values (All permutations of 0 and 1 in binary number of size n)
    vector<vi> dp(n, vi((1 << n), -1));

    // (1 << 4) = 2^4 = 16, binary: 10000, so (1 << 4) - 1 = 15, binary: 1111
    // Each bit represents a city, if all bits are one, then all cities are visited, else the 0 bit cities are yet to be visited
    VISITED_ALL = (1 << n) - 1;
    startingCity = 0;
    // Marking the bit corresponding to the starting city as 1 i.e. visited
    int mask = (1 << startingCity);
    int ans = tsp_dp(startingCity, mask, adjMatrix, dp);
    cout << ans << endl;
    return 0;
}
