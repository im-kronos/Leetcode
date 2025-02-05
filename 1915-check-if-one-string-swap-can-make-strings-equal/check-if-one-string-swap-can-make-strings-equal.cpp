class Solution {
public:
    bool areAlmostEqual(string str1, string str2) {
        vector<int>nums;
        for(int i=0;i<str1.size();i++)
        {
            if(str1[i]!= str2[i])
            {
                nums.push_back(i);
            }

            if(nums.size()>2)
            {
              return false;
            }

        }
        if(nums.size()==1 )
        {
            return false;
        }

        if(nums.size()== 0 || (str1[nums[0]] == str2[nums[1]]) && (str1[nums[1]] == str2[nums[0]]))
        {
            return true;
        }
    

        return false;

        
    }
};