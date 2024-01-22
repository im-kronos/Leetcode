class Solution {
public:
    int search(vector<int>& arr, int k) {
        int start = 0;
        int size = arr.size();
        int end = size-1;
        while(start<=end){
            int mid = (start+end)/2;
            if(arr[mid]==k){
                return mid;
            }
            if(arr[start]<=arr[mid]){
                if(arr[start]<=k && k<=arr[mid]){
                    end = mid-1;
                }
                else{
                    start = mid+1;
                }
            }
            else{
                if(arr[mid]<=k && k<=arr[end]){
                    start = mid + 1;
                }
                else{
                    end = mid-1;
                }
            }
           
        }
        return -1;
    }
};

/*class Solution
{
    public:
        int search(vector<int> &nums, int target)
        {
            int s = 0;
            int e = nums.size()-1;
            int mid;
            int ans;
            while (s <= e)
            {
                mid = s + (e - s) / 2;
                if (nums[mid] <= nums[mid - 1] && nums[mid] <= nums[mid + 1])
                {
                    ans = mid;
                    break;
                }
                else
                if (nums[mid] < nums[mid + 1] && nums[mid] > nums[mid + 1])
                {
                    s = mid;
                }
                else
             	//  if (nums[mid] < nums[mid + 1] && nums[mid] > nums[mid - 1])
                {
                    e = mid;
                }
            }

            return ans;
        }
};

*/