// https://www.interviewbit.com/problems/allocate-books/
#include <bits/stdc++.h>

#include <numeric>

using namespace std;

bool isPossible(int val, vector<int> &arr, int b) {
    int cnt = 1, currSum = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > val) return false;
        if (currSum + arr[i] <= val)
            currSum += arr[i];
        else {
            cnt += 1;
            currSum = arr[i];
        }
    }
    return cnt <= b;
}

int books(vector<int> &arr, int b) {
    if (b > arr.size()) return -1;
    int start = *max_element(arr.begin(), arr.end()), end = accumulate(arr.begin(), arr.end(), 0);
    int ans = -1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (isPossible(mid, arr, b)) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    int n, b;
    cin >> n >> b;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << books(arr, b);
    return 0;
}
