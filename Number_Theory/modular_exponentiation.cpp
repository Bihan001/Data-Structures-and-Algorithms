#include <bits/stdc++.h>

using namespace std;

int power(int a, int p, int m) {
    int res = 1;
    a = a % m;
    if (a == 0) return 0;
    while (p > 0) {
        if (p & 1) res = res * a % m;  // if(p%2==1)
        p = p >> 1;                    // p = p/2
        a = (a * a) % m;
    }
    return res;
}

int main() {
    int a = 2, p = 5, m = 13;
    cout << power(a, p, m);
    return 0;
}