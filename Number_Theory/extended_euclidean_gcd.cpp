#include <bits/stdc++.h>

using namespace std;

// O(log(min(a, b)))
// (a . x) + (b ⋅ y) = gcd(a, b)
// We are calculating x and y along with gcd(a, b)
int gcd_extended(int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcd_extended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}

int main() {
    int x, y;
    int gcd = gcd_extended(55, 80, &x, &y);
    cout << gcd << " " << x << " " << y;
}