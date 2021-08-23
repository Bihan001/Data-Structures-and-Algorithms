#include <bits/stdc++.h>

using namespace std;

// O(log(min(a,b)))
int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main() {
    cout << gcd(5, 6) << " " << gcd(24, 12);
}