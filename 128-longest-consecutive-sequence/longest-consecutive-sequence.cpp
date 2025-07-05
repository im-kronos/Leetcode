class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }
        int count = 1; 
        int temp = pq.top();
        pq.pop();
        int maxi = 1;

        while (!pq.empty()) {
            int curr = pq.top();
            pq.pop();

            if (curr == temp) {
                continue;
            }

            if (curr == temp + 1) {
                count++;
            } else {
                count = 1;
            }

            temp = curr;
            maxi = max(maxi, count);
        }

        return maxi;
    }
};
