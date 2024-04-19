class Solution {
public:

    int check(vector<vector<char>>&grid,int &count,int i,int j)
    {
        //base exit condition
        if (i >= grid.size() || j >= grid[0].size() || grid[i][j] != '1') {
            return 0;
        }

        // Mark current cell as visited
        grid[i][j] = '0';

        //trverse all nighbour ones
        check(grid,count,i+1,j);
        check(grid,count,i,j+1);
        check(grid,count,i-1,j);
        check(grid,count,i,j-1);
        return 1;
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1') //each entire island is counted here
                {
                    count+=check(grid,count,i,j);
                }

            }
        }
        
        return count;
 
    }
};