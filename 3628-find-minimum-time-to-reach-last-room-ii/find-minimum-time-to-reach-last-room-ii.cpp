class Solution {
public:
    typedef tuple<int, int, int, int> State; 

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        priority_queue<State, vector<State>, greater<>> pq;
        pq.push({0, 0, 0, 0}); 
        vector<vector<vector<int>>> minTime(n, vector<vector<int>>(m, vector<int>(2, INT_MAX)));
        minTime[0][0][0] = 0;

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!pq.empty()) {
            auto [currTime, row, col, stepType] = pq.top();
            pq.pop();

            if (row == n - 1 && col == m - 1) return currTime;

            for (auto dir : directions) {
                int newRow = row + dir.first;
                int newCol = col + dir.second;

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) {
                    int moveDuration = (stepType == 0) ? 1 : 2;
                    int arrivalTime = max(currTime, moveTime[newRow][newCol]) + moveDuration;

                    int nextStepType = 1 - stepType;

                    if (arrivalTime < minTime[newRow][newCol][nextStepType]) {
                        minTime[newRow][newCol][nextStepType] = arrivalTime;
                        pq.push({arrivalTime, newRow, newCol, nextStepType});
                    }
                }
            }
        }

        return -1; // not reachable
    }
};
