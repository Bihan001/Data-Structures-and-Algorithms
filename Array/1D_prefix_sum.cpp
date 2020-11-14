#include <bits/stdc++.h>

using namespace std;

void calc_prefix(int *arr, int *ps, int n) {
    ps[0] = arr[0];
    for (int i = 1; i < n; i++) {
        ps[i] = ps[i - 1] + arr[i];
    }
}

int main() {
    int arr[9] = {2, 3, -1, 5, 3, 8, 11, -10, 2};
    int ps[9];
    calc_prefix(arr, ps, 9);
    int l = 4, r = 7;
    for (int i = 0; i < 9; i++) {
        cout << ps[i] << " ";
    }
    cout << endl;
    cout << ps[r] - ps[l - 1];
    return 0;
}