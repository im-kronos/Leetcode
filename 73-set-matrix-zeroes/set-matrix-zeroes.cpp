class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // Check which columns contain zeros
        vector<bool> colZero(cols, false);
        for (int j = 0; j < cols; ++j) {
            for (int i = 0; i < rows; ++i) {
                if (matrix[i][j] == 0) {
                    colZero[j] = true;
                    break;
                }
            }
        }

        // Check which rows contain zeros
        vector<bool> rowZero(rows, false);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == 0) {
                    rowZero[i] = true;
                    break;
                }
            }
        }

        // Set zeros for rows
        for (int i = 0; i < rows; ++i) {
            if (rowZero[i]) {
                for (int j = 0; j < cols; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Set zeros for columns
        for (int j = 0; j < cols; ++j) {
            if (colZero[j]) {
                for (int i = 0; i < rows; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
