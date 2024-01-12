class Solution {
public:
   void func(vector<vector<int>> &ans, vector<int> &temp, vector<int> nums, int i)
   {
       if(i==nums.size())
       {
           ans.push_back(temp);
           return;
       }
       temp.push_back(nums[i]);
       func(ans,temp,nums,i+1); //recursion   
      //backtrack part to check if we dont pushback the element ie undo the changes made
       temp.pop_back();
       func(ans,temp,nums,i+1);   //backtrack=> recursion without the previous element this is the reason for null

       /*.                            ()
                         1.                      0.  (backtrack after pop of 1)

                 1,2.          1.           2.         0

            1,2,3.   1,2    1,3    1.     2,3.  2.     3.  0

here first recursion happpen till i=3 ie <1,2,3>
then pop happens ir <1,2> only that is the backtracking part so again recursion runs resulting for <1,2>.  

then again pop happens <1>.  but i=3 still so 3 is added and recursion happens



      */

   }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        func(ans,temp,nums,0);
        return ans;
    }
    
};