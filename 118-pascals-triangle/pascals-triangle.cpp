class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if (numRows == 0) {
            return ans;
        }
        vector<int> temp;
        temp.push_back(1);
        ans.push_back(temp);
        if (numRows == 1) {
            return ans;
        }
        temp.push_back(1);
        ans.push_back(temp);
        if (numRows == 2) {
            return ans;
        }

        vector<int> ref;
        for (int i = 2; i < numRows; i++) { 
            temp.clear();
            temp.push_back(1); 
            ref = ans[i-1];    
            for (int j = 0; j < ref.size()-1; j++) { 
                temp.push_back(ref[j] + ref[j+1]);
            }
            temp.push_back(1); 
            ans.push_back(temp);
        }
        
        return ans;
    }
};