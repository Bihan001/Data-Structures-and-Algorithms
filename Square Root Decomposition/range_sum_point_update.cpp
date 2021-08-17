#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mii map<int, int>
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

// Given an array of n integers, perform two types of queries on it.
// In query of type 1, take two integers as input, index and value. Replace the element of that index to the value.
// In query of type 2, take two integers l and r. Print the sum of all elements in the range l to r (inclusive).

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vi arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    // Each block is of size ceil(sqrt(n))
    int blockSize = n / ceil(sqrt(n));
    vi blocks(blockSize, 0);

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
            int index, value;
            cin >> index >> value;

            // we subtract the old value of the index from its block and add the new value to it
            int old = arr[index];
            blocks[index / blockSize] -= old;
            blocks[index / blockSize] += value;
            continue;
        }
        // print query
        if (option == 2) {
            int l, r;
            cin >> l >> r;

            // startBlock holds the index of the block in which l belongs, endBlock holds the index of the block in which r belongs
            int startBlock = l / blockSize, endBlock = r / blockSize, sum = 0;

            // edge case
            if (startBlock == endBlock) {
                for (int i = l; i <= r; i++) sum += arr[i];
                cout << sum << endl;
                continue;
            }

            // sum of all elements starting from l to the end of starting block
            // Time complexity: O(blockSize)
            for (int i = l; i <= (startBlock + 1) * blockSize - 1; i++) sum += arr[i];

            // sum of all elements starting from the first index ending block to r
            // Time complexity: O(blockSize)
            for (int i = endBlock * blockSize; i <= r; i++) sum += arr[i];

            // sum of all blocks in between starting and ending block
            // Time complexity: O(blockSize) [Since, blockSize * blockSize = n (approx)]
            for (int i = startBlock + 1; i <= endBlock - 1; i++) sum += blocks[i];

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
1 3 100
2 1 9
1 7 4
2 0 9

Output:
150
147
*/