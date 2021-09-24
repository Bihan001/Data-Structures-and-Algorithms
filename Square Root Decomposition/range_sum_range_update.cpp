#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mii map<int, int>
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

// Given an array of n integers, perform two types of queries on it.
// In query of type 1, take three integers as input, l, r and value. Add 'value' to all elements in range [l, r].
// In query of type 2, take two integers l and r. Print the sum of all elements in range [l, r].

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vi arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    // Each block is of size ceil(sqrt(n))
    int blockSize = ceil(sqrt(n));
    vi blocks(n / blockSize + 1, 0), lazy(n / blockSize + 1, 0);

    // (i / blockSize) gives the block index where the index i is belonging to.
    // We store the sum of all elements of a block to the corresponding block of the blocks array
    for (int i = 0; i < n; i++) {
        blocks[i / blockSize] += arr[i];
    }

    int q;
    cin >> q;
    while (q--) {
        int option;
        cin >> option;
        // update query
        if (option == 1) {
            int l, r, val;
            cin >> l >> r >> val;
            // startBlock holds the index of the block in which l belongs, endBlock holds the index of the block in which r belongs
            int startBlock = l / blockSize, endBlock = r / blockSize;

            // Updating only the lazy value and not the actual range.
            // Time complexity: O(n/blockSize+1)
            for (int i = startBlock; i <= endBlock; i++) lazy[i] += val;
        }
        // print query
        if (option == 2) {
            int l, r;
            cin >> l >> r;

            // startBlock holds the index of the block in which l belongs, endBlock holds the index of the block in which r belongs
            int startBlock = l / blockSize, endBlock = r / blockSize, sum = 0;

            // edge case
            if (startBlock == endBlock) {
                for (int i = l; i <= r; i++) sum += arr[i] + lazy[startBlock];
                cout << sum << endl;
                continue;
            }

            // sum of all elements starting from l to the end of starting block
            // Time complexity: O(blockSize)
            for (int i = l; i <= (startBlock + 1) * blockSize - 1; i++) sum += arr[i] + lazy[startBlock];

            // sum of all elements starting from the first index ending block to r
            // Time complexity: O(blockSize)
            for (int i = endBlock * blockSize; i <= r; i++) sum += arr[i] + lazy[endBlock];

            // sum of all blocks in between starting and ending block
            // Time complexity: O(blockSize) [Since, blockSize * blockSize = n (approx)]
            for (int i = startBlock + 1; i <= endBlock - 1; i++) sum += blocks[i] + (lazy[i] * blockSize);

            cout << sum << endl;
        }
    }
    return 0;
}

/*
Input:
10
1 2 3 4 5 6 7 8 9 10
4
1 3 8 100
2 1 9
1 7 9 4
2 0 9

Output:
954
1079
*/