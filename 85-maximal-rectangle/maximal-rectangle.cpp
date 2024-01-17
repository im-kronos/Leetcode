#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix)
    {

        //precomputing new heights
        int t_sum;
        int row = matrix.size();
        int col = matrix[0].size();
        int csum[matrix.size()][matrix[0].size()];

        for (int i = 0; i < col; i++) {
            t_sum = 0;
            for (int j = 0; j < row; j++) {
                if (matrix[j][i] == '0') {
                    t_sum = 0;
                    csum[j][i] = 0;
                }
                if (matrix[j][i] == '1') {
                    t_sum++;
                    csum[j][i] = t_sum;
                }
            }
        }

      //to compute prev and next small elements
      int prev_small[matrix.size()][matrix[0].size()];
      int next_small[matrix.size()][matrix[0].size()];

      stack<int>s1;
      stack<int>s2;


      for(int i=0;i<row;i++)
      {
          for(int j=0;j<col;j++)
          {
              while(!s1.empty() && csum[i][s1.top()] >= csum[i][j]){
                s1.pop();
            }
            if(s1.empty()){
                prev_small[i][j]=-1;
            }
            else{
                prev_small[i][j]=s1.top();
            }
            s1.push(j);  //here we are supposed to push index of j
          }

        while (!s1.empty())
           s1.pop();
      }

// to calculate next_small


   for(int i=row-1;i>=0;i--)
   {
       for(int j=col-1;j>=0;j--)
       {
           while(!s2.empty() && csum[i][s2.top()]>=csum[i][j])
           {
               s2.pop();
           }
           if(s2.empty())
           {
               next_small[i][j]=col;  //extreme right + 1 =>ht.size()
           }
           else
           {
               next_small[i][j]=s2.top();
           }
           s2.push(j);
       }

       while(!s2.empty())
       s2.pop();
   }

 
       // to compute max area from the prev and next small value
       int max_area;
       int area;

      for(int i=0;i<row;i++)
      {
          for(int j=0;j<col;j++)
          {
              area=csum[i][j]*(next_small[i][j]-prev_small[i][j]-1);
              max_area=max(max_area,area);
          }
      }


        return max_area;
     
    }
};
