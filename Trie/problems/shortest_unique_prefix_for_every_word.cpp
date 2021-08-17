// https://www.geeksforgeeks.org/find-all-shortest-unique-prefixes-to-represent-each-word-in-a-given-list/
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
    char value;
    int count;
    bool isLeaf;
    map<char, Node *> children;
    Node(char val) {
        value = val;
        count = 1;
        isLeaf = false;
    }
};

class Trie {
   private:
    Node *root;
    int words;
    vector<string> prefixes;
    void _insert(Node *root, string word) {
        if (!root) return;
        if (word == "") {
            root->isLeaf = true;
            words++;
            return;
        }
        char newChar = word[0];
        string restWord = word.substr(1);
        if (root->children.find(newChar) == root->children.end()) {
            root->children[newChar] = new Node(newChar);
        } else {
            root->children[newChar]->count++;
        }
        _insert(root->children[newChar], restWord);
    }
    void _getUniquePrefixes(Node *root, string currWord) {
        if (!root) return;
        if (root->count == 1) {
            prefixes.pb(currWord + root->value);
            return;
        }
        for (auto it : root->children) {
            _getUniquePrefixes(it.second, currWord + root->value);
        }
    }

   public:
    Trie() {
        root = new Node('\0');
        root->count = 0;
        words = 0;
    }
    void insert(string word) { _insert(root, word); }

    vector<string> getUniquePrefixes() {
        _getUniquePrefixes(root, "");
        return prefixes;
    }
};

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    Trie t;
    while (n--) {
        string word;
        cin >> word;
        t.insert(word);
    }
    vector<string> prefixes = t.getUniquePrefixes();
    for (auto it : prefixes) cout << it << endl;
    return 0;
}

/*
Input:
6
and bool bonfire catch case char

Output:
a
bon
boo
cas
cat
ch
*/