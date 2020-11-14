#include <bits/stdc++.h>

using namespace std;

void create_z_array(string tot, int *z) {
    int n = tot.length();
    int l, r, k;
    l = r = 0;
    for (int i = 1; i < n; i++) {
        if (i > r) {
            l = r = i;
            while (r < n && tot[r] == tot[r - l]) r++;
            z[i] = r - l;
            r--;
        } else {
            k = i - l;
            if (z[k] < r - i + 1)
                z[i] = z[k];
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
    int z[tot.length()];
    create_z_array(tot, z);
    for (int i = pat.length() + 1; i < tot.length(); i++) cout << z[i] << " ";
    return 0;
}