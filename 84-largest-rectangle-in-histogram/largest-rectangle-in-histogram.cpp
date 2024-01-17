class Solution {
public:
    int largestRectangleArea(vector<int>& ht)
    {
       //here we are going to approach using stack 
       //we will find prev_small and next_small 
       //area= width(next_small[i]-prev_small[i]-1) * max(heights)
       int area=INT_MIN;

       vector<int>prev_small(ht.size(),0);
       vector<int>next_small(ht.size(),0);

       stack<int>s1;
       stack<int>s2;
       //prev_small
       for(int i=0;i<ht.size();i++)
       {
           while(!s1.empty() && ht[s1.top()]>=ht[i])
           {
               s1.pop();
           }
           if(s1.empty())
           {
               prev_small[i]=-1; //extreme left -1
           }
           else
           {
               prev_small[i]=s1.top();
           }
           s1.push(i);
       }
/*
       for(int i=0;i<ht.size();i++)
       {
           cout<<prev_small[i]<<" ";
       }

*/


//next_small
       for(int i=ht.size()-1;i>=0;i--)
       {
           while(!s2.empty() && ht[s2.top()]>=ht[i])
           {
               s2.pop();
           }
           if(s2.empty())
           {
               next_small[i]=ht.size();  //extreme right + 1 =>ht.size()
           }
           else
           {
               next_small[i]=s2.top();
           }
           s2.push(i);
       }

/*

       for(int i=0;i<ht.size();i++)
       {
           cout<<next_small[i]<<" ";
       }
*/


//for area and return ans
      for(int i=0;i<ht.size();i++)
       {
           area=max(area,ht[i]*(next_small[i]-prev_small[i]-1));
       }
     return area;  
        
    }
};