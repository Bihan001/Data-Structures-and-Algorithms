// Fermat's little theorem
// If n is a prime number, then for every a, 1 < a < n-1, a^(n-1) ≡ 1 (mod n) => a^(n-1) % n = 1
// Success rate of the primality check is not 100%
#include <bits/stdc++.h>

using namespace std;

// Function to calculate (a^p)%m
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

// O(k*log(n))
bool is_prime(int n, int k) {
    if (n <= 1 || n == 4) return false;
    if (n <= 3) return true;
    while (k--) {
        int a = 2 + rand() % (n - 4);  // For k times, we use a random number ranging [2,n-2] and perform gcd with n to check if its prime in case the fermat's algo fails
        if (__gcd(a, n) != 1) return false;
        if (power(a, n - 1, n) != 1) return false;
    }
    return true;
}

int main() {
    int k = 10;
    cout << is_prime(5, k) << " " << is_prime(101, k) << " " << is_prime(100, k);
    return 0;
}