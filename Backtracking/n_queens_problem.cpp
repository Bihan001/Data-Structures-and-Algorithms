#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isSafe(int r, int c, vector<string> &board) {
        for (int j = c - 1; j >= 0; j--) {
            if (board[r][j] == 'Q') return false;
        }
        for (int j = c + 1; j < board.size(); j++) {
            if (board[r][j] == 'Q') return false;
        }
        for (int i = r - 1; i >= 0; i--) {
            if (board[i][c] == 'Q') return false;
        }
        for (int i = r + 1; i < board.size(); i++) {
            if (board[i][c] == 'Q') return false;
        }
        for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }
        for (int i = r - 1, j = c + 1; i >= 0 && j < board.size(); i--, j++) {
            if (board[i][j] == 'Q') return false;
        }
        for (int i = r + 1, j = c + 1; i < board.size() && j < board.size(); i++, j++) {
            if (board[i][j] == 'Q') return false;
        }
        for (int i = r + 1, j = c - 1; i < board.size() && j >= 0; i++, j--) {
            if (board[i][j] == 'Q') return false;
        }
        return true;
    }
    void recurse(int r, vector<string> &board, set<vector<string>> &res) {
        if (r == -1) {
            res.insert(board);
            return;
        }
        for (int j = 0; j < board.size(); j++) {
            if (board[r][j] == 'Q') continue;
            if (isSafe(r, j, board)) {
                board[r][j] = 'Q';
                recurse(r - 1, board, res);
                board[r][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string s = "";
        for (int i = 0; i < n; i++) s += '.';
        vector<string> board(n, s);
        set<vector<string>> res;
        recurse(n - 1, board, res);
        vector<vector<string>> ans;
        for (auto it : res) ans.push_back(it);
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    Solution s;
    vector<vector<string>> ans = s.solveNQueens(n);
    cout << ans.size() << endl;

    // for (auto it : ans) {
    //     // for (auto itt : it) cout << itt << endl;
    // }
    return 0;
}
