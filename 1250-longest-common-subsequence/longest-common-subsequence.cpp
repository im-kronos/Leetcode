class Solution {
public:
  int dp[1001][1001];
  int solve(string &s1,string &s2,int size1,int size2)
  {

      if(size1 <0  || size2 < 0 )
      {
          return 0;
      }

      if(dp[size1][size2]!=-1)
      {
          return dp[size1][size2];
      }
      int ans1=0;
      if(s1[size1]==s2[size2])
      {
           ans1 =  1+solve(s1,s2,size1-1,size2-1);
      }
      //otherwise
     
     
      int ans2 =max( solve(s1,s2,size1-1,size2),solve(s1,s2,size1,size2-1));
      
      return dp[size1][size2]= max(ans1,ans2);
  }



    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        int ans=solve(text1,text2,text1.length()-1,text2.length()-1);
        return ans;
        
    }
};



/* 

                     abcd,abxcg
          abc,abxcg             abcd,abxc
  ab,abxcg.    abc,abxc.  
    so it goes on and if last index of both stirng are same then return 1+ans 

*/