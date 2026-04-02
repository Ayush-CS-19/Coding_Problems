class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();
        int m = coins[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3, INT_MIN)));
        for (int k = 0; k <= 2; k++) {
            if (coins[n-1][m-1] < 0 && k > 0)
                dp[n-1][m-1][k] = 0;
            else
                dp[n-1][m-1][k] = coins[n-1][m-1];
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (i == n-1 && j == m-1) continue;

                for (int k = 0; k <= 2; k++) {

                    int bestNext = INT_MIN;

                    if (i + 1 < n)
                        bestNext = max(bestNext, dp[i+1][j][k]);
                    if (j + 1 < m)
                        bestNext = max(bestNext, dp[i][j+1][k]);

                    if (coins[i][j] >= 0) {
                        if (bestNext != INT_MIN)
                            dp[i][j][k] = coins[i][j] + bestNext;
                    } 
                    else {
                        // take negative
                        int take = INT_MIN;
                        if (bestNext != INT_MIN)
                            take = coins[i][j] + bestNext;

                        // skip negative
                        int skip = INT_MIN;
                        if (k > 0) {
                            int bestSkip = INT_MIN;
                            if (i + 1 < n)
                                bestSkip = max(bestSkip, dp[i+1][j][k-1]);
                            if (j + 1 < m)
                                bestSkip = max(bestSkip, dp[i][j+1][k-1]);

                            skip = bestSkip;
                        }

                        dp[i][j][k] = max(take, skip);
                    }
                }
            }
        }

        return dp[0][0][2];
    }
};