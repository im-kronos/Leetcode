class Solution {
public:
   static bool compare(int a,int b)
{
    string num1=to_string(a);
    string num2=to_string(b);
    return (num1+num2)>(num2+num1);
}


    string largestNumber(vector<int>& nums) {
    sort(nums.begin(),nums.end(),compare);
    string ans="";
    for(int i=0;i<nums.size();i++)
    {
        ans+=to_string(nums[i]);
    }
    if(ans[0]=='0')
    {
        return "0";
    }
    //cout<<ans;
    return ans;
        
    }
};