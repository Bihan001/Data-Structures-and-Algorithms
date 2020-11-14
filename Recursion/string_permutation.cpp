#include <bits/stdc++.h>

using namespace std;

void swap(char *a, char *b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void permutation(char *arr, int l, int h) {
    if (l + 1 == h) {
        for (int i = 0; i < h; i++) cout << arr[i];
        cout << endl;
        return;
    }
    for (int i = l; i < h; i++) {
        swap(arr + l, arr + i);
        permutation(arr, l + 1, h);
        swap(arr + l, arr + i);
    }
}

int main() {
    char arr[] = {'A', 'B', 'C'};
    int h = sizeof(arr) / sizeof(arr[0]);
    permutation(arr, 0, h);
    return 0;
}