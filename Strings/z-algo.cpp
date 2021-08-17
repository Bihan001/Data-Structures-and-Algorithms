#include <bits/stdc++.h>
using namespace std;

void create_z_array(string tot, vector<int> &z) {
    int n = tot.length();
    int l, r, k;
    l = r = 0;
    for (int i = 1; i < n; i++) {
        // normal case: when we need to match the current values with its prefixes
        if (i > r) {
            // Resetting the z-box
            l = r = i;
            // Increasing the width of the z-box by incrementing r
            while (r < n && tot[r] == tot[r - l]) r++;
            // (r - l) = length of the substring that is also the prefix
            z[i] = r - l;
            r--;
        } else {
            // optimizing case: when i is inside the z-box so we don't need to recalculate its values
            // k = corresponding position in the prefix
            k = i - l;
            // if the expected value exists inside the z-box
            if ((z[k] + i - 1) < r) z[i] = z[k];
            // else we need to recalculate the values like the normal case
            else {
                l = i;
                while (r < n && tot[r] == tot[r - l]) r++;
                z[i] = r - l;
                r--;
            }
        }
    }
}

int main() {
    // 0, 6, 11
    string s = "ababbaababbaba";
    string pat = "aba";
    string tot = pat + "$" + s;
    vector<int> z(tot.length());
    create_z_array(tot, z);
    for (int i = pat.length() + 1; i < tot.length(); i++) cout << z[i] << " ";
    return 0;
}