// https://www.geeksforgeeks.org/greedy-algorithm-to-find-minimum-number-of-coins/

/*
Given a value V, if we want to make a change for V Rs, and we have an infinite supply of each of the denominations 
in Indian currency, i.e., we have an infinite supply of { 1, 2, 5, 10, 20, 50, 100, 500, 1000} valued coins/notes, 
what is the minimum number of coins and/or notes needed to make the change?
*/

// This result won't always work like for the case {9,1,5,6} and n = 11

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 93;
    int arr[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int size = sizeof(arr) / sizeof(arr[0]);

    sort(arr, arr + size);

    vector<int> result;

    for (int i = size - 1; i >= 0; i--) {
        while (n >= arr[i]) {
            n -= arr[i];
            result.push_back(arr[i]);
        }
    }

    for (auto &it : result) cout << it << ' ';

    return 0;
}