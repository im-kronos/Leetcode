class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        stack<int>in;
        stack<int>de;
        int max_in = 0;
        int max_de = 0;

        in.push(nums[0]);
        de.push(nums[0]);

        for(int i = 1; i < nums.size(); i++) {
            if(in.top() < nums[i]) {
                in.push(nums[i]);
            } else {
                max_in = max(max_in, (int)in.size());
                while(!in.empty()) {
                    in.pop(); 
                }
                in.push(nums[i]); 
            }

            if(de.top() > nums[i]) {
                de.push(nums[i]);
            } else {
                max_de = max(max_de, (int)de.size());
                while(!de.empty()) {
                    de.pop(); 
                }
                de.push(nums[i]); 
            }
        }

        max_in = max(max_in,(int) in.size());
        max_de = max(max_de, (int)de.size());

        return max(max_in, max_de);  
    }
};
