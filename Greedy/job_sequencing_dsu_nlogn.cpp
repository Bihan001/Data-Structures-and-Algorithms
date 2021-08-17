// https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1
#include <bits/stdc++.h>
using namespace std;

struct Job {
    int id;      // Job Id
    int dead;    // Deadline of job
    int profit;  // Profit if job is over before or on deadline
};

class DSU {
    vector<int> parent;

   public:
    DSU(int m) {
        parent.resize(m + 1);
        for (int i = 0; i <= m; i++) parent[i] = i;
    }
    int find(int n) {
        if (parent[n] == n) return n;
        return parent[n] = find(parent[n]);
    }
    void union_nodes(int u, int v) { parent[v] = u; }
};

class Solution {
   public:
    static bool comp(Job a, Job b) { return a.profit > b.profit; }
    vector<int> JobScheduling(Job arr[], int n) {
        int maxval = 0;
        for (int i = 0; i < n; i++) maxval = max(maxval, arr[i].dead);
        DSU d(maxval);
        int cnt = 0, profit = 0;
        // sort based on profit in descending order
        sort(arr, arr + n, comp);
        for (int i = 0; i < n; i++) {
            // Initially available slots will be their own deadline
            int availableSlot = d.find(arr[i].dead);
            // If availableSlot is greater than 0, then slots are available.
            // So we take that slot and union that with the next possible available slot which is currentSlot - 1.
            if (availableSlot > 0) {
                cnt += 1;
                profit += arr[i].profit;
                d.union_nodes(availableSlot - 1, availableSlot);
            }
        }
        return {cnt, profit};
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Job arr[n];
        for (int i = 0; i < n; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            arr[i].id = x;
            arr[i].dead = y;
            arr[i].profit = z;
        }
        Solution ob;
        vector<int> ans = ob.JobScheduling(arr, n);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}

/*
Input:
1
5
1 2 100
2 1 19
3 2 27
4 1 25
5 1 15

Output:
2 127
*/