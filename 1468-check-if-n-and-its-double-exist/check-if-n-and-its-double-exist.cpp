class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
         unordered_map<int, int> mp; 
        for (int num : arr) {
            mp[num]++;
        }
        
        for (int num : arr) {
            if (num == 0) {
                if (mp[num] > 1) {
                    return true;
                }
            } else {
                if (mp.find(2 * num) != mp.end()) {
                    return true;
                }
            }
        }
        return false;
    }
};