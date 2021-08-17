// https://www.geeksforgeeks.org/count-of-cyclic-permutations-having-xor-with-other-binary-string-as-0/
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mii map<int, int>
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

vi createZArray(string s) {
    int n = s.length(), l = 0, r = 0;
    vi z(n, 0);
    for (int i = 1; i < n; i++) {
        if (i > r) {
            l = r = i;
            while (r < n && s[r] == s[r - l]) r++;
            z[i] = r - l;
            r--;
        } else {
            if (z[i - l] + i - 1 < r) {
                z[i] = z[i - l];
            } else {
                l = i;
                while (r < n && s[r] == s[r - l]) r++;
                z[i] = r - l;
                r--;
            }
        }
    }
    return z;
}

int main(int argc, char const *argv[]) {
    string a, b;
    cin >> a >> b;
    string s = a + '$' + b + b;
    s.pop_back();
    vi z = createZArray(s);
    int cnt = 0;
    for (int i = 0; i < z.size(); i++) {
        if (z[i] == a.length()) cnt += 1;
    }
    cout << cnt << endl;
    return 0;
}
