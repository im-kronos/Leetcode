class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, list<int>> l;

        for (int i = 0; i < edges.size(); i++) {
            l[edges[i][0]].push_back(edges[i][1]);
            l[edges[i][1]].push_back(edges[i][0]);
        }

        int n = edges.size() + 1;  // Number of nodes in the tree
        for (auto& ch : l) {
            if (ch.second.size() == n - 1) {
                return ch.first;
            }
        }

        return -1;  // If no center is found
    }
};