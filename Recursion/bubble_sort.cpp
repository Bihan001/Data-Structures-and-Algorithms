#include <bits/stdc++.h>

using namespace std;

void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void bubble_sort(int arr[], int i, int n) {
    if (n == 1) return;
    if (i == n - 1)
        bubble_sort(arr, 0, n - 1);
    else {
        if (arr[i] > arr[i + 1]) swap(arr + i, arr + i + 1);
        bubble_sort(arr, i + 1, n);
    }
}

int main() {
    int arr[] = {3, 2, 4, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubble_sort(arr, 0, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}