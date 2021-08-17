// https://practice.geeksforgeeks.org/problems/activity-selection-1587115620/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    static bool comp(pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    }
    int activitySelection(vector<int> start, vector<int> end, int n) {
        vector<pair<int, int>> activities(n);
        for (int i = 0; i < n; i++) activities[i] = make_pair(start[i], end[i]);
        // Sort based on end time
        sort(activities.begin(), activities.end(), comp);
        int ans = 1;
        for (int i = 1, j = 0; i < n; i++) {
            if (activities[i].first > activities[j].second) {
                ans += 1;
                j = i;
            }
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        for (int i = 0; i < n; i++) cin >> start[i];
        for (int i = 0; i < n; i++) cin >> end[i];
        Solution ob;
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

/*
Input:
1
4
1 3 2 5
2 4 3 6

Output:
3
*/