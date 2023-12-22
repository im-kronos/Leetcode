class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            //for unique elemnts or less than 2 counts
            if(count<2 || nums[count-2]!=nums[i]){
                // If the current element is unique, update it in the vector
                nums[count]=nums[i];
                // Increment the count to move to the next position in the vector
                count++;
            }
        }
        return count;
    }
};