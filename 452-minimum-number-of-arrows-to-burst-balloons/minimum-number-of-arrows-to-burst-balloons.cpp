
class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0; // No balloons to burst

        sort(points.begin(), points.end(), compare);

        int count = 1; // Initialize with 1, as there is at least one interval
        int end = points[0][1]; // End of the first interval

        for (int i = 1; i < points.size(); ++i) {
            // If the current interval overlaps with the previous one
            if (points[i][0] <= end) {
                // Update the end point to the minimum of the current end and the end of the current interval
                end = min(end, points[i][1]);
            } else {
                // Current interval starts after the previous one ends, indicating a new overlap region
                count++;
                end = points[i][1];
            }
        }

        return count;
    }
};