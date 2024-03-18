class Solution {
public:
    static bool Sorted_points(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), Sorted_points);
        int ct = 1, i = 1, comX1 = points[0][0], comX2 = points[0][1];
        int n = points.size();
        while (i < n) {
            if (points[i][0] >= comX1 and points[i][0] <= comX2) {
                comX1 = max(points[i][0], comX1);
                comX2 = min(comX2, points[i][1]);
            } else {
                comX1 = points[i][0];
                comX2 = points[i][1];
                ct++;
            }
            i++;
        }
        return ct;
    }
};