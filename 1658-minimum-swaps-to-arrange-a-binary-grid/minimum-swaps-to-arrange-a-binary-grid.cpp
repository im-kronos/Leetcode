class Solution
{
public:
    vector<int> track = vector<int>(200, -1);

    bool validate(vector<vector<int>> &grid)
    {
        int n = grid.size();
        for (int i = 0; i < 200; i++)
            track[i] = -1;

        int t = 0;

        for (int i = 0; i < n; i++)
        {
            t = 0; 

            for (int j = n - 1; j >= 0; j--)
            {
                if (grid[i][j] == 1) break;
                t++;
            }
            track[i] = t;  
        }

        return true; 
    }

    int minSwaps(vector<vector<int>> &grid)
    {
        if (validate(grid) == false)
        {
            return -1;
        }

        int n = grid.size();
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            int required = n - i - 1;
            int j = i;
            while (j < n && track[j] < required)
            {
                j++;
            }
            if (j == n)
            {
                return -1;
            }
            while (j > i)
            {
                swap(track[j], track[j - 1]);
                ans++;
                j--;
            }
        }
        return ans;
    }
};