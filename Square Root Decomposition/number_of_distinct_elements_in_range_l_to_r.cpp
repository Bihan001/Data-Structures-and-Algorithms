#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mii map<int, int>
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vi arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    mii occurences;
    vi nextOccIndices(n);
    for (int i = n - 1; i >= 0; i--) {
        if (occurences.find(arr[i]) == occurences.end()) {
            nextOccIndices[i] = n;
        } else {
            nextOccIndices[i] = occurences[arr[i]];
        }
        occurences[arr[i]] = i;
    }
    int blockSize = ceil(sqrt(n));
    vector<set<int>> blocks(n / blockSize + 1, set<int>());
    for (int i = 0; i < n; i++) {
        blocks[i / blockSize].insert(nextOccIndices[i]);
    }
    int q;
    cin >> q;
    while (q--) {
        int option;
        cin >> option;
        // update
        if (option == 1) {
        }
        // print
        if (option == 2) {
            int l, r, cnt = 0;
            cin >> l >> r;
            int startBlock = l / blockSize, endBlock = r / blockSize;
            if (startBlock == endBlock) {
                for (int i = l; i <= r; i++) {
                    if (nextOccIndices[i] > r) cnt += 1;
                }
                cout << cnt << endl;
                continue;
            }
            for (int i = l; i <= (startBlock + 1) * blockSize - 1; i++) {
                if (nextOccIndices[i] > r) cnt += 1;
            }
            for (int i = endBlock * blockSize; i <= r; i++) {
                if (nextOccIndices[i] > r) cnt += 1;
            }
            for (int i = startBlock + 1; i <= endBlock - 1; i++) {
                cnt += distance(blocks[i].upper_bound(r), blocks[i].end());
            }
            cout << cnt << endl;
            continue;
        }
    }
    return 0;
}

/*
Input:
5
1 1 2 1 3
3
2 0 4
2 1 3
2 2 4

Output:
3
2
3
*/