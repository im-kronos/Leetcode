class Solution {
public:
    int maxArea(vector<int>& height)
     {
        int i=0;
        int j=height.size()-1;
        int A=0;//area=width(j-i)*minheight(a[i],a[j])
        while(i<=j)
        {
            A=max(A,min(height[i],height[j])*(j-i));
           // A=min(height[i],height[j])*(j-i);

            if(height[i]<height[j])
            {
                i++;
            }
            else
            {
                j--;
            }

        }

        return A;
    }
};