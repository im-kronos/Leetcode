class Solution {
public:
    int trap(vector<int>& height) {
        int lmax=INT_MIN;
        int rmax=INT_MIN;
        int ans=0;
        int l=0;
        int r=height.size()-1;
        while(l<r)
        {
            lmax=max(lmax,height[l]);
            rmax=max(rmax,height[r]);
            //update l is updated and r is updated if its greater
            ans+=(lmax<rmax)?lmax-height[l++]:rmax-height[r--];
        }
        return ans;
    }
};