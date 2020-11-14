#include <bits/stdc++.h>

using namespace std;

void calc_lps_array(string pat, int *lps) {
    int m = pat.length();
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < m) {
        if (pat[i] == pat[len]) {
            lps[i++] = ++len;
        } else {
            if (len != 0)
                len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

vector<int> kmp_search(string s, string pat) {
    vector<int> res;
    int n = s.length();
    int m = pat.length();
    int lps[m];
    calc_lps_array(pat, lps);
    int i = 0, j = 0;
    while (i < n) {
        if (s[i] == pat[j]) {
            i++;
            j++;
        }
        if (j == m) {
            res.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && pat[j] != s[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i += 1;
        }
    }
    return res;
}

int main() {
    string s = "ABABDABACDABABCABAB";
    string pat = "ABA";
    vector<int> res;
    res = kmp_search(s, pat);
    for (auto &it : res) cout << it << " ";
    return 0;
}