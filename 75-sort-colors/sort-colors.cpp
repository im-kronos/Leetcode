class Solution {
public:

   void BSR(vector<int>&arr,int n,int i)
   {
       if(n==1)
       {
           return;
       }
       if(i==n-1)
       {
           BSR(arr,n-1,0);
           return;
       }
       if(arr[i]>arr[i+1])
       {
           swap(arr[i],arr[i+1]);
       }
       BSR(arr,n,i+1);
   }


    void sortColors(vector<int>& nums) {
        BSR(nums,nums.size(),0);

    }
};