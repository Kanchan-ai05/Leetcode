class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        if (n <= 2)
            return n;

        int ans = 2;

        for (int i = 0; i < n; i++)
        {
            map<pair<int, int>, int> slopeCount;
            int maxi = 0;

            for (int j = i + 1; j < n; j++)
            {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                int g = gcd(dx, dy);
                dx /= g;
                dy /= g;

                // Normalize sign
                if (dx < 0)
                {
                    dx = -dx;
                    dy = -dy;
                }

                // Vertical line
                if (dx == 0)
                    dy = 1;

                // Horizontal line
                if (dy == 0)
                    dx = 1;

                slopeCount[{dx, dy}]++;
                maxi = max(maxi, slopeCount[{dx, dy}]);
            }

            ans = max(ans, maxi + 1); // +1 for the anchor point
        }

        return ans;
    }
};