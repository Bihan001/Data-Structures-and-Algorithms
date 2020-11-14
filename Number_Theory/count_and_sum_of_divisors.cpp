#include <bits/stdc++.h>

using namespace std;

// If prime factorization of n is p1^e1 . p2^e2...pk^ek, then
// d(n) = (e1+1) . (e2+1)...(ek+1)
int divisors_count(int n) {
    map<int, int> hash;
    while (n % 2 == 0) {
        hash[2]++;
        n = n / 2;
    }
    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            hash[i]++;
            n = n / i;
        }
    }
    if (n > 2)
        hash[n]++;

    int ans = 1;
    for (auto i : hash) {
        ans = ans * (i.second + 1);
    }
    return ans;
}

// If prime factorization of n is p1^e1 . p2^e2...pk^ek, then
// σ(n) = (p1^(e1+1)-1)/(p1-1) . (p2^(e2+1)-1)/(p2-1) ... (pk^(ek+1)-1)/(pk-1)
int sum_of_divisors(int n) {
    map<int, int> hash;
    while (n % 2 == 0) {
        hash[2]++;
        n = n / 2;
    }
    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            hash[i]++;
            n = n / i;
        }
    }
    if (n > 2)
        hash[n]++;

    int sum = 1;
    for (auto i : hash) {
        sum = sum * (pow(i.first, i.second + 1) - 1) / (i.first - 1);
    }
    return sum;
}

int main() {
    cout << divisors_count(7) << " " << divisors_count(6) << " " << divisors_count(10) << endl;
    cout << sum_of_divisors(7) << " " << sum_of_divisors(6) << " " << sum_of_divisors(10);
}