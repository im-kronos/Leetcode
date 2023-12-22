class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
     unordered_map<int,int>map;
     int size=nums.size(); int counter=0;
     for(int i=0;i<size;i++)
     {
         int a=nums[i];
         if(map.find(a)==map.end())
         {
             map[a]=0;
         }
         if(map.find(a)!=map.end() && map[a]<2)
         {
             nums[counter]=a;
             counter++;
             map[a]++;
         }
     }

     return counter;
        
    }
};