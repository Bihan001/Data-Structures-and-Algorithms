// Euler's totient function ϕ(n) counts the number of integers between 1 and n inclusive, which are coprime to n.
// If n = p1^a1 . p2^a2 ... pk^ak, where p are the prime factors of n, ϕ(n) = n . (1 - 1/p1) . (1 - 1/p2) ...(1 - 1/pk)

#include <bits/stdc++.h>

using namespace std;

// O(sqrt(n))
int phi(int n) {
    int res = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) n = n / i;
            res = res - res / i;
        }
    }
    if (n > 1) res -= res / n;
    return res;
}

// O(n*log(loog n))
// To calculate phi(i) for range [1,n]
vector<int> phi_1_to_n(int n) {
    vector<int> phi(n + 1);
    phi[0] = 0, phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i;
    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
    return phi;
}

int main() {
    cout << phi(5) << " " << phi(6);
    cout << endl;
    vector<int> phi = phi_1_to_n(10);
    for (auto &it : phi) cout << it << " ";
    return 0;
}