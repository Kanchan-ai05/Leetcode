class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();

        // If there are not enough days
        if (n == 0)
            return 0;

        // If k is large, it becomes the unlimited transaction problem
        if (k >= n / 2) {
            int profit = 0;

            for (int i = 1; i < n; i++) {
                if (prices[i] > prices[i - 1])
                    profit += prices[i] - prices[i - 1];
            }

            return profit;
        }

        // dp[t][i] =
        // maximum profit using at most t transactions
        // in the first i days

        vector<vector<int>> dp(k + 1, vector<int>(n, 0));

        for (int t = 1; t <= k; t++) {

            int best = -prices[0];

            for (int i = 1; i < n; i++) {

                // Don't sell today
                dp[t][i] = dp[t][i - 1];

                // Sell today
                dp[t][i] = max(
                    dp[t][i],
                    prices[i] + best
                );

                // Consider buying at day i
                best = max(
                    best,
                    dp[t - 1][i] - prices[i]
                );
            }
        }

        return dp[k][n - 1];
    }
};