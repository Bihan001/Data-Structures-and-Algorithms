// https://www.geeksforgeeks.org/job-sequencing-problem/

/* Given an array of jobs where every job has a deadline and associated profit if the job is finished before the deadline. 
It is also given that every job takes single unit of time, so the minimum possible deadline for any job is 1. 
How to maximize total profit if only one job can be scheduled at a time.
*/

#include <bits/stdc++.h>

using namespace std;

struct Job {
    char id;
    int dead;
    int profit;
};

// This function is used for sorting all jobs according to profit
bool comparison(Job a, Job b) {
    return (a.profit > b.profit);
}

void printJobScheduling(Job arr[], int n) {
    // Sort all jobs according to decreasing order of prfit
    sort(arr, arr + n, comparison);

    int result[n];
    bool slot[n];

    for (int i = 0; i < n; i++)
        slot[i] = false;

    for (int i = 0; i < n; i++) {
        // Find a free slot for this job (Note that we start
        // from the last possible slot)
        for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
            if (slot[j] == false) {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
        if (slot[i])
            cout << arr[result[i]].id << " ";
}

int main() {
    Job arr[] = {{'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, {'d', 1, 25}, {'e', 3, 15}};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Following is maximum profit sequence of jobs: ";
    printJobScheduling(arr, n);
    return 0;
}