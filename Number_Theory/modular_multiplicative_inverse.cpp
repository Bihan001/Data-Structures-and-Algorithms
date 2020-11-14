// https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m

#include <bits/stdc++.h>

using namespace std;

// O(n)
// Finding x such that -> (a * x) % m ≡ 1
// x exists only if gcd(a, m) = 1 i.e. they are coprime
// Range of x is {0,1,2...,m-1}
int mod_inverse_naive(int a, int m) {
    a = a % m;
    for (int i = 1; i < m; i++) {
        if ((a * i) % m == 1) {
            return i;
        }
    }
    return 0;
}
// O(log m)
// Using extended Euclidean algorithm ->  ax + by = gcd(a, b)
// => ax + my = 1 as gcd(a,m) should be 1
// => ax  ≡ 1 (mod m) we can remove the 'my' as m % m = 0

int mod_inverse_efficient(int a, int m) {
    int m0 = m, x = 1, y = 0;
    if (m == 1) return 0;
    while (a > 1) {
        // Basic Euclidean gcd algo
        int q = a / m;
        int t = m;
        m = a % m;
        a = t;
        // Updating x and y in extended Euclidean algo
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0) x += m0;
    return x;
}

int main() {
    int a = 3, m = 11;
    cout << mod_inverse_naive(a, m);
    return 0;
}