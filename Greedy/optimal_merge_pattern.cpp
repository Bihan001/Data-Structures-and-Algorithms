// https://www.geeksforgeeks.org/optimal-file-merge-patterns/

/*
Given n number of sorted files, the task is to find the minimum computations done to reach Optimal Merge Pattern.
When two or more sorted files are to be merged all together to form a single file, the minimum computations done to reach 
this file are known as Optimal Merge Pattern.
*/

/*Here priority queue is used so we dont need to search for the smallest elements or sort the array. The queue uses min heap so
we can directly pop the smallest element from the priority queue.
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 6;
    int arr[n] = {2, 3, 4, 5, 6, 7};

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++)
        pq.push(arr[i]);

    int sum = 0;

    while (pq.size() > 1) {
        int first_smallest = pq.top();
        pq.pop();
        int second_smallest = pq.top();
        pq.pop();
        sum += first_smallest + second_smallest;
        pq.push(first_smallest + second_smallest);
    }

    cout << sum << endl;

    return 0;
}