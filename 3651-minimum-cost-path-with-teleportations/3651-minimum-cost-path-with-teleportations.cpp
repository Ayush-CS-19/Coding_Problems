class Solution {
public:
    int minCost(vector<vector<int>>& grid, int T) {
        int n = grid.size(), m = grid[0].size();
        const int INF = 1e9;

        vector<int> best(10001, INF);
        vector<vector<vector<int>>> dp(T + 1,
            vector<vector<int>>(n, vector<int>(m, INF)));

        for(int k = 0; k <= T; k++){
            vector<int> prefix(10001, INF);

            for(int i = n - 1; i >= 0; i--){
                for(int j = m - 1; j >= 0; j--){
                    if(i == n - 1 && j == m - 1){
                        dp[k][i][j] = 0;
                    }
                    else{
                        int ans = INF;
                        if(i + 1 < n) ans = min(ans, dp[k][i + 1][j] + grid[i + 1][j]);
                        if(j + 1 < m) ans = min(ans, dp[k][i][j + 1] + grid[i][j + 1]);
                        if(k > 0) ans = min(ans, best[grid[i][j]]);
                        dp[k][i][j] = ans;
                    }
                    prefix[grid[i][j]] =
                        min(prefix[grid[i][j]], dp[k][i][j]);
                }
            }

            for(int i = 1; i < 10001; i++)
                prefix[i] = min(prefix[i], prefix[i-1]);

            best = prefix; 
        }

        return dp[T][0][0];
    }
};
