class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0; 
        
        for(int i = 1; i < n; i++) {  
            if(nums[i-1] > nums[i]) {
                count++;
            }
        }
        return count == 0 || (count == 1 && nums[n-1] <= nums[0]);
    }
};

