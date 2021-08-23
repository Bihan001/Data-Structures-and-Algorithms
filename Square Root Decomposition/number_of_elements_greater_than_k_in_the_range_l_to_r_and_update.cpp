#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mii map<int, int>
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

// You are given an array of n integers and q queries of 2 types. For type 1 query, take two inputs: index and value and update do arr[index] = value.
// For type 2 query, take 3 inputs: l, r and k. Then print the number of integers in range (l, r) that is strictly greater than k.

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vi arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    // Size of each block
    int blockSize = ceil(sqrt(n));

    vector<set<int>> blocks(n / blockSize + 1, set<int>());

    for (int i = 0; i < n; i++) {
        blocks[i / blockSize].insert(arr[i]);
    }

    int q;
    cin >> q;
    while (q--) {
        int option;
        cin >> option;
        // update
        if (option == 1) {
            int index, value;
            cin >> index >> value;
            blocks[index / blockSize].erase(arr[index]);
            blocks[index / blockSize].insert(value);
            arr[index] = value;
        }
        // print
        if (option == 2) {
            int l, r, k;
            cin >> l >> r >> k;
            int startBlock = l / blockSize, endBlock = r / blockSize, cnt = 0;

            // Edge case
            if (startBlock == endBlock) {
                for (int i = l; i <= r; i++) {
                    if (arr[i] > k) cnt += 1;
                }
                cout << cnt << endl;
                return;
            }

            // Cannot use set/sort/upper_bound here as the ordering would be different. As we are not considering the whole block,
            // we need to manually check the elements
            for (int i = l; i <= (startBlock + 1) * blockSize - 1; i++) {
                if (arr[i] > k) cnt += 1;
            }
            // Cannot use set/sort/upper_bound here as the ordering would be different. As we are not considering the whole block,
            // we need to manually check the elements
            for (int i = endBlock * blockSize; i <= r; i++) {
                if (arr[i] > k) cnt += 1;
            }
            // For the blocks in between, we take the number of elements starting from the number just greater than k to the end of the block
            for (int i = startBlock + 1; i <= endBlock - 1; i++) {
                cnt += distance(blocks[i].upper_bound(k), blocks[i].end());
            }
            cout << cnt << endl;
            continue;
        }
    }
    return 0;
}

/*
Input:
6
7 3 9 13 5 4
4
2 0 3 6
2 0 5 8
1 2 3
2 0 5 6

Output:
3
2
2
*/