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


/* explanation
       mid   /| 
            / |
 target    /  |
          /   |
start   /     |    end     
              |   /
              |  /  target
              | /
              |/ mid


         mid
          /
 target. /.    => arr[s]<=arr[mid] => arr[s]<=target && target<=arr[mid]
        /                                   end=mid-1;
start. /                              else.  strat=mid+1


          end     
       /
      /  target.  => arr[mid]<=arr[e] => arr[mid]<=traget && target<=arr[end]
     /                                          start=mid+1
    / mid                               else.  end=mid-1

    */