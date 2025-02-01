class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++)
        {
            bool num_one = (nums[i]%2 == 0)?true:false;
            bool num_two = (nums[i+1]%2 == 0)?true:false;
            if(num_one == num_two)
            {
                return false;
            }
        }
        return true;
        
    }
};