// ? SOLVED https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mii map<int, int>
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

class Node {
   public:
    int value;                // 0, 1
    vector<Node *> children;  // size: 2
    Node(int val) {
        value = val;
        children.resize(2, NULL);
    }
};

class Trie {
   public:
    Node *root;
    Trie() { root = new Node(-1); }
    void insert(int num) {
        Node *p = root;
        // we check and insert all 32 bits(integer range) of each number so all numbers have the same bit count
        for (int i = 31; i >= 0; i--) {
            // starting from the msb(31) and moving to the lsb(0)
            int bit = (num >> i) & 1;  // possible values: 0 and 1
            // we check if there is a node in the 0th or 1st index of the children array according to the bit. If not, we create it
            if (!p->children[bit]) p->children[bit] = new Node(bit);
            // then we move down the trie
            p = p->children[bit];
        }
    }
    int findMaxXor(vi &arr) {
        int maxXor = INT_MIN;
        for (int num : arr) {
            int currXor = 0;
            Node *p = root;
            for (int i = 31; i >= 0; i--) {
                // for each number in the array, we check each of its 32 bits and find the opposite bit in the trie. If found we proceed with that,
                // else we take the same bit. We update our currXor whenever we proceed with the opposite bit as bit ^ oppositeBit = 1,
                // so pow(2,n)*1 = pow(2^n). If we proceed with the same bits then the result will be pow(2, n)*0 = 0;
                int bit = (num >> i) & 1;
                int invertedBit = !bit;
                if (p->children[invertedBit]) {
                    p = p->children[invertedBit];
                    currXor += (1 << i);  // (1 << i) == pow(2, i)
                } else {
                    p = p->children[bit];
                }
            }
            maxXor = max(maxXor, currXor);
        }
        return maxXor;
    }
};

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vi arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Trie t;
    for (auto it : arr) t.insert(it);
    int ans = t.findMaxXor(arr);
    cout << ans << endl;
    return 0;
}

/*
Input:
6
3 10 5 25 2 8

Output:
28
*/