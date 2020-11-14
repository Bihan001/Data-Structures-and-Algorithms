#include <bits/stdc++.h>

using namespace std;

void calc_prefix(int arr[][5], int ps[][5], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (j == 0) {
                ps[i][j] = arr[i][j];
            } else {
                ps[i][j] = ps[i][j - 1] + arr[i][j];
            }
        }
    }
    for (int j = 0; j < c; j++) {
        for (int i = 0; i < r; i++) {
            if (i == 0) {
                continue;
            } else {
                ps[i][j] = ps[i - 1][j] + ps[i][j];
            }
        }
    }
}

int main() {
    int arr[5][5] = {{2, 3, 4, 5, 6}, {3, 4, 5, 6, 7}, {4, 5, 6, 7, 8}, {5, 6, 7, 8, 9}, {6, 7, 8, 9, 0}};
    int ps[5][5];
    calc_prefix(arr, ps, 5, 5);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << ps[i][j] << " ";
        }
        cout << endl;
    }

    int x1 = 1, y1 = 2, x2 = 3, y2 = 4;
    cout << "Ans: " << ps[x2][y2] - ps[x2][y1 - 1] - ps[x1 - 1][y2] + ps[x1 - 1][y1 - 1];
    return 0;
}