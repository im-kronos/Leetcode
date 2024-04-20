#include <vector>
using namespace std;

class Solution {
private:
    void group(vector<vector<int>>& land, int r, int c, int& top, int& left, int& bottom, int& right) {
        if (r < 0 || r >= land.size() || c < 0 || c >= land[0].size() || land[r][c] != 1) {
            return;
        }
        
        // Update the boundaries of the current group of farmland
        top = min(top, r);
        left = min(left, c);
        bottom = max(bottom, r);
        right = max(right, c);
        
        // Mark the current cell as visited (forest)
        land[r][c] = 0;
        
        // Perform DFS in four directions
        group(land, r + 1, c, top, left, bottom, right); // Down
        group(land, r - 1, c, top, left, bottom, right); // Up
        group(land, r, c + 1, top, left, bottom, right); // Right
        group(land, r, c - 1, top, left, bottom, right); // Left
    }

public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        
        for (int i = 0; i < land.size(); ++i) {
            for (int j = 0; j < land[0].size(); ++j) {
                if (land[i][j] == 1) {
                    int top = i, left = j, bottom = i, right = j;
                    group(land, i, j, top, left, bottom, right);
                    ans.push_back({top, left, bottom, right});
                }
            }
        }
        
        return ans;
    }
};
