class Solution {
public:
    int maxPoints(vector<vector<int>>& p) {
        int n = p.size();
        if(n==1) return 1;
        int iteration = 2000;
        int ans = 0;
        while (iteration--)
        {
            int i = rand() % n;
            int j = rand() % n;
            while (i == j)
                j = rand() % n;
            int x1 = p[i][0], y1 = p[i][1];
            int x2 = p[j][0], y2 = p[j][1];
            int ct = 0;
            for (int k = 0; k < n; k++)
            {
                int xk = p[k][0], yk = p[k][1];
                if ((y2 - y1) * (xk - x1) == (yk - y1) * (x2 - x1))
                    ct++;
            }
            ans = max(ans, ct);
        }
        return ans;
    }
};