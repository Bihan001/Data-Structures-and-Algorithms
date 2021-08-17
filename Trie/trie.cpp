#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    // value: contains the character, children: contains addresses of next characters, isLeaf: true when the string ends
    char value;
    map<char, Node *> children;
    bool isLeaf;
    Node(char value) {
        this->value = value;
        this->isLeaf = false;
    }
    ~Node() {
        this->children.clear();
        this->isLeaf = false;
    }
};

// The trie is case sensative i.e. Hello != hello
class Trie {
   private:
    Node *root;
    int wordCount = 0;

    void _add(Node *parent, string value) {
        if (!parent) return;

        // Mark the node as terminating node and increase word count
        if (value == "") {
            parent->isLeaf = true;
            this->wordCount += 1;
            return;
        }

        // curr: first character of the current string, rest: remaining string
        char curr = value[0];
        string rest = value.substr(1);

        // If the parent doesn't already have the curr character as children, create it
        if (parent->children.find(curr) == parent->children.end()) {
            parent->children[curr] = new Node(curr);
        }

        // Then move to the child node and continue until no character is left in the string
        _add(parent->children[curr], rest);
    }

    bool _isPresent(Node *parent, string value) {
        if (!parent) return false;

        // If no character is left in the string and the node is also terminating, the the target string is present
        if (value == "") {
            if (parent->isLeaf) return true;
            return false;
        }

        // curr: first character of the current string, rest: remaining string
        char curr = value[0];
        string rest = value.substr(1);

        // If the current character is not present in the parent node's children, then the target string is ofc not present
        if (parent->children.find(curr) == parent->children.end()) return false;

        // Then move to the child node and continue to check until no character is left
        return _isPresent(parent->children[curr], rest);
    }

    void _remove(Node *parent, string value) {
        if (!parent) return;

        // If all characters of the target string are traversed, then mark the parent node's isLeaf as false as the string is being removed
        if (value == "") {
            if (parent->isLeaf) parent->isLeaf = false;
            this->wordCount -= 1;
            return;
        }

        // curr: first character of the current string, rest: remaining string
        char curr = value[0];
        string rest = value.substr(1);

        // If the current character is not present, then the target string is also not present in the trie so can't remove it as well
        if (parent->children.find(curr) == parent->children.end()) return;

        // Then move to the child node and continue until no character is left
        _remove(parent->children[curr], rest);

        // Clearing the memory as well: If the parent node's isLeaf is false and it has no children then we remove it as it violates trie's rules i.e.
        // it should have atleast one child if it is not isLeaf
        if (parent->isLeaf == false && parent->children[curr]->children.empty()) {
            parent->children.erase(curr);
        }
    }

   public:
    Trie() {
        this->root = new Node('\0');
        this->wordCount = 0;
    }
    ~Trie() {
        delete this->root;
        this->wordCount = 0;
    }
    void add(string value) { this->_add(this->root, value); }
    void remove(string value) { this->_remove(this->root, value); }
    bool isPresent(string value) { return this->_isPresent(this->root, value); }
    int count() { return this->wordCount; }
};

int main() {
    string stringsPresent[] = {"Hello", "Apple", "Appy", "Arara", "Hi", "Hey"};
    string stringsNotPresent[] = {"Hii", "Aple", "App", "He", "Appl", "Yo", "Mobile"};
    Trie t;
    for (string s : stringsPresent) {
        t.add(s);
    }
    for (string s : stringsPresent) {
        cout << "Should be present" << endl;
        cout << s << ": " << t.isPresent(s) << endl;
    }
    for (string s : stringsNotPresent) {
        cout << "Should not be present" << endl;
        cout << s << ": " << t.isPresent(s) << endl;
    }
    cout << endl;
    t.remove("Hello");
    t.remove("Apple");
    t.remove("Hii");
    cout << "Hello: " << t.isPresent("Hello") << endl;
    cout << "Apple: " << t.isPresent("Apple") << endl;
    cout << "Hii: " << t.isPresent("Hii") << endl;
    cout << "Count: Expected: " << 4 << ", Obtained: " << t.count() << endl;
    return 0;
}