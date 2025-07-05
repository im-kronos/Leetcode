#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        // Min-heap
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }

        int count = 1; // at least one element exists
        int temp = pq.top();
        pq.pop();
        int maxi = 1;

        while (!pq.empty()) {
            int curr = pq.top();
            pq.pop();

            if (curr == temp) {
                // Skip duplicates
                continue;
            }

            if (curr == temp + 1) {
                // Consecutive
                count++;
            } else {
                // Sequence breaks
                count = 1;
            }

            temp = curr;
            maxi = max(maxi, count);
        }

        return maxi;
    }
};
