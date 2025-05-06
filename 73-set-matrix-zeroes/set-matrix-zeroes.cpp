class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int>rows;
        vector<int>columns;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    rows.push_back(i);
                    columns.push_back(j);
                }
            }
        }

        // Set entire rows to 0
        for(int i = 0; i < rows.size(); i++)
        {
            for(int j = 0; j < matrix[0].size(); j++)
            {
                matrix[rows[i]][j] = 0;
            }
        }

        // Set entire columns to 0
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < columns.size(); j++)
            {
                matrix[i][columns[j]] = 0;
            }
        }
    }
};