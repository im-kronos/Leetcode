class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        //for first k elements we are pushing i
        vector<int>ans;
        for(int i=0;i<k;i++)
        {
            while(!dq.empty() && nums[dq.back()]<nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        //remaining from k
        for(int i=k;i<nums.size();i++)
        {
            ans.push_back(nums[dq.front()]);  //print max for k set
            //contacting
            while(!dq.empty() && dq.front()<=i-k)
            {
                dq.pop_front();
            }
            //expanding

            while(!dq.empty() && nums[i]>nums[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }


        ans.push_back(nums[dq.front()]);

        return ans;
    }
};

